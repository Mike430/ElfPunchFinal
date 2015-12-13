//INCLUDES
#include "EP_Game.h"

//=========================================//

cocos2d::Scene* EP_Game::createScene()
{
	// 'scene' is an autorelease object
	auto scene = cocos2d::Scene::create();
	// 'layer' is an autorelease object
	auto layer = EP_Game::create();
	// add layer as a child to scene
	scene->addChild(layer);
	//RETURN
	return scene;
}

//=========================================//

bool EP_Game::init()
{
	//A call to super? C++ doesn't have one so this is needed.
	if (!Layer::init())
	{
		return false;
	}
	//Scene Setter
	_rootNode = cocos2d::CSLoader::createNode("GameScene.csb");
	this->addChild(_rootNode);
	// get components from level
	_backdrop = (cocos2d::Sprite*)_rootNode->getChildByName("GameBoardScreen_1");
	_frameCounter = (cocos2d::ui::Text*)_rootNode->getChildByName("Frame_Counter");
	//Random Generator
	srand(time(NULL));
	//Get the view pane size
	_winSize = cocos2d::Director::getInstance()->getVisibleSize();
	
	// Set up this class before you set up the elves
	_numOfElfs = 100;
	_running = true;
	_gameOver = false;
	_frameCount = 0;
	_elfUpdateIndex = 0;

	_difficulty = 5;// This in particular caused trouble when the elves got their initial time
	_allElvesDown = true;
	_elfsUp = 0;
	_elfsDown = 11;

	for (int i = 0; i < ELF_NUMBER; i++)
	{
		_elfs[i] = new Elfs();
	}
	
	_elfs[0]->_loadedNode = _rootNode->getChildByName("Elf_1");
	_elfs[1]->_loadedNode = _rootNode->getChildByName("Elf_2");
	_elfs[2]->_loadedNode = _rootNode->getChildByName("Elf_3");
	_elfs[3]->_loadedNode = _rootNode->getChildByName("Elf_4");
	_elfs[4]->_loadedNode = _rootNode->getChildByName("Elf_5");
	_elfs[5]->_loadedNode = _rootNode->getChildByName("Elf_6");
	_elfs[6]->_loadedNode = _rootNode->getChildByName("Elf_7");
	_elfs[7]->_loadedNode = _rootNode->getChildByName("Elf_8");
	_elfs[8]->_loadedNode = _rootNode->getChildByName("Elf_9");
	_elfs[9]->_loadedNode = _rootNode->getChildByName("Elf_10");
	_elfs[10]->_loadedNode = _rootNode->getChildByName("Elf_11");

	for (int i = 0; i < ELF_NUMBER; i++)
	{
		float posX = _elfs[i]->_loadedNode->getPositionX();
		float posY_Up = _elfs[i]->_loadedNode->getPositionY() + 20.0f;
		float posY_Down = _elfs[i]->_loadedNode->getPositionY();
		_elfs[i]->_startingYPos = _elfs[i]->_loadedNode->getPositionY();

		cocos2d::Vec2 up = cocos2d::Vec2(posX, posY_Up);
		cocos2d::Vec2 down = cocos2d::Vec2(posX, posY_Down);

		_elfs[i]->_posUpY = up;
		_elfs[i]->_posDownY = down;
		_elfs[i]->_timeLeft = SetATime();
		_elfs[i]->_name = i;

		_elfs[i]->_isUp = false;
	}

	auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
	// Assign the event methods to the event listener (known as callbacks)
	touchListener->onTouchBegan = CC_CALLBACK_2(EP_Game::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(EP_Game::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(EP_Game::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(EP_Game::onTouchCancelled, this);

	/* For more information on the eventdispatcher mechanism (and how events in Cocos work in general)
	go to http://www.cocos2d-x.org/wiki/EventDispatcher_Mechanism */
	// Add the event listener to the event dispatcher which is not a member of this class but of it's own
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	//Calls the game loop
	this->scheduleUpdate();
	//INIT ENDS IN RETURN TRUE
	return true;
}
//=========================================//

void EP_Game::update(float deltaTime)
{
	if (_running)
	{
		// Update the game
		_frameCount += 1;
		//GameManager::GetInstance()->AddToScore(1);

		int count = 0;
		for (int i = 0; i < ELF_NUMBER; i++)
		{
			if (!_elfs[i]->_isUp) count += 1;
		}

		if (count == ELF_NUMBER)
			_allElvesDown = true;
		else
			_allElvesDown = false;

		UpdateElves();

		UpdateScoreDisplay();

		//TRANSITION TEST 
		if (_numOfElfs <= 0)
		{
			_gameOver = true;
		}
	}

	if (_gameOver)
	{
		EndGame();
	}
}

void EP_Game::UpdateElves()
{
	vector<Elfs*> elfListDown = MakeElfList(false);
	ScrambleList(elfListDown);

	vector<Elfs*> elfListUp;
	if (!_allElvesDown)
	{
		elfListUp = MakeElfList(true);
		ScrambleList(elfListUp);
		for (int i = 0; i < elfListUp.size(); i++)
		{
			UpdateElf(elfListUp.at(i), true);
		}
	}

	for (int i = 0; i < elfListDown.size(); i++)
	{
		UpdateElf(elfListDown.at(i), false);
	}
}

void EP_Game::UpdateElf(Elfs* elf, bool state)
{
	elf->_timeLeft -= 1;
	if (elf->_timeLeft <= 0.0f)
	{
		if (elf->_isUp)
			ElfPopDown(elf);
		else
			ElfPopUp(elf);

		//elf->_isUp = !elf->_isUp;//This flips the state but the methods abover were already doing that. woops
		elf->_timeLeft = SetATime();
	}
}

void EP_Game::ElfPopUp(Elfs* elf)
{
	_numOfElfs -= 1;
	if (_numOfElfs <= 0)
		_gameOver = true;
	else
	{
		cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(0.1, elf->_posUpY);
		elf->_loadedNode->runAction(moveTo);
		elf->_isUp = true;
	}
}

void EP_Game::ElfHit(Elfs* elf)
{
	GameManager::GetInstance()->AddToScore(10);
	ElfPopDown(elf);
}

void EP_Game::ElfPopDown(Elfs* elf)
{
	cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(0.1, elf->_posDownY);
	elf->_loadedNode->runAction(moveTo);
	elf->_isUp = false;
}

int EP_Game::CountElvesState(bool upOrDown)
{
	int count = 0;
	for (int i = 0; i < ELF_NUMBER; i++)
	{
		if (upOrDown)// look for elves that are up
		{
			if (_elfs[i]->_isUp)
				count += 1;
		}
		else// look for elfs that are down
		{
			if (!_elfs[i]->_isUp)
				count += 1;
		}
	}
	return count;
}

int EP_Game::SetATime()
{
	double time;
	double randElement = rand() % 10 + 5;
	randElement = randElement / 10;
	time = randElement * 5;
	time = time / _difficulty;
	time = time * 60;
	int finalTime = (int)time;
	return finalTime;
}

vector<Elfs*> EP_Game::MakeElfList(bool state)
{
	vector<Elfs*> elfList;

	for (int i = 0; i < ELF_NUMBER; i++)
	{
		if (_elfs[i]->_isUp == state)
		{
			elfList.push_back(_elfs[i]);
		}
	}

	return elfList;
}

void EP_Game::ScrambleList(vector<Elfs*>& elfList)
{
	//http://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
	auto engine = std::default_random_engine{};
	std::shuffle(std::begin(elfList), std::end(elfList), engine);// always randomises into the same patern
	int q = 11;//for a break point
}

void EP_Game::EndGame()
{
	//Transitions from the game scene to the leaderboard scene
	cocos2d::Scene* nextScene = LeaderBoard::createScene();
	cocos2d::CCDirector::getInstance()->replaceScene(nextScene);
}

void EP_Game::UpdateScoreDisplay()
{
	std::ostringstream convert;
	convert << GameManager::GetInstance()->GetScore();
	_countStr = "Score: " + convert.str();
	_frameCounter->setString(_countStr);
}

//=========================================//

bool EP_Game::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	int itterator = 0;
	bool hit = false;

	cocos2d::Rect touchRect = cocos2d::Rect(
		touch->getLocation().x,
		touch->getLocation().y,
		50,
		50);

	while (itterator < ELF_NUMBER && hit == false)
	{
		if (_elfs[itterator]->_isUp)
		{
			cocos2d::Rect elfRect = cocos2d::Rect(
				_elfs[itterator]->_loadedNode->getPositionX(),
				_elfs[itterator]->_loadedNode->getPositionY(),
				100,
				100);

			if (elfRect.intersectsRect(touchRect))
			{
				_elfs[itterator]->_isUp = false;
				ElfHit(_elfs[itterator]);
			}

			//if (sprite->intersectsRect(touch))
		}

		itterator += 1;
	}
	return hit;
}

void EP_Game::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

void EP_Game::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

void EP_Game::onTouhCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{
}