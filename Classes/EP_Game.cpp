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
	//Sound Setter
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("res/Game.wav", true);
	// get components from level
	_backdrop = (cocos2d::Sprite*)_rootNode->getChildByName("GameBoardScreen_1");
	_scoreLabel = (cocos2d::ui::Text*)_rootNode->getChildByName("Score");
	_multiplierLabel = (cocos2d::ui::Text*)_rootNode->getChildByName("Multiplier");
	_elfCounterLabel = (cocos2d::ui::Text*)_rootNode->getChildByName("ElvesLeft");
	//Random Generator
	srand(time(NULL));
	//Get the view pane size
	_winSize = cocos2d::Director::getInstance()->getVisibleSize();
	
	// Set up this class before you set up the elves
	_elvesInitialized = false;
	_running = true;
	_elfUpdateIndex = 0;

	_allElvesDown = true;
	_elfsUp = 0;
	_elfsDown = 11;

	for (int i = 0; i < ELF_NUMBER; i++)
	{
		_elves[i] = Elf::create();
		_rootNode->addChild(_elves[i]);
	}

	_elves[0]->Setup(100.0f, 714.0f, 1);
	_elves[2]->Setup(100.0f, 541.0f, 3);
	_elves[5]->Setup(100.0f, 370.0f, 6);
	_elves[8]->Setup(100.0f, 197.0f, 9);

	_elves[1]->Setup(540.0f, 714.0f, 2);
	_elves[4]->Setup(540.0f, 541.0f, 5);
	_elves[7]->Setup(540.0f, 370.0f, 8);
	_elves[10]->Setup(540.0f, 197.0f, 11);

	_elves[3]->Setup(320.0f, 616.0f, 4);
	_elves[6]->Setup(320.0f, 444.0f, 7);
	_elves[9]->Setup(320.0f, 272.0f, 10);

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
		//GameManager::GetInstance()->AddToScore(1);

		int count = 0;
		for (int i = 0; i < ELF_NUMBER; i++)
		{
			if (!_elves[i]->_isUp) count += 1;
		}

		if (count == ELF_NUMBER)
			_allElvesDown = true;
		else
			_allElvesDown = false;

		UpdateElves();

		UpdateScoreDisplay();
		UpdateMultiplierDisplay();
		UpdateElfCounterDisplay();

		//TRANSITION TEST 
		if (GameManager::GetInstance()->GetNumOfElfs() <= 0)
		{
			GameManager::GetInstance()->SetGameOver(true);
		}
	}

	if (GameManager::GetInstance()->GetGameOver())
	{
		EndGame();
	}
}

void EP_Game::UpdateElves()
{
	vector<Elf*> elfListDown = MakeElfList(false);
	ScrambleList(elfListDown);

	vector<Elf*> elfListUp;
	if (!_allElvesDown)
	{
		elfListUp = MakeElfList(true);
		ScrambleList(elfListUp);
		for (int i = 0; i < elfListUp.size(); i++)
		{
			elfListUp.at(i)->UpdateElf(elfListUp.at(i), true);
		}
	}

	for (int i = 0; i < elfListDown.size(); i++)
	{
		elfListDown.at(i)->UpdateElf(elfListDown.at(i), false);
	}
}

int EP_Game::CountElvesState(bool upOrDown)
{
	int count = 0;
	for (int i = 0; i < ELF_NUMBER; i++)
	{
		if (upOrDown)// look for elves that are up
		{
			if (_elves[i]->_isUp)
				count += 1;
		}
		else// look for elfs that are down
		{
			if (!_elves[i]->_isUp)
				count += 1;
		}
	}
	return count;
}

vector<Elf*> EP_Game::MakeElfList(bool state)
{
	vector<Elf*> elfList;

	for (int i = 0; i < ELF_NUMBER; i++)
	{
		if (_elves[i]->_isUp == state)
		{
			elfList.push_back(_elves[i]);
		}
	}

	return elfList;
}

void EP_Game::ScrambleList(vector<Elf*>& elfList)
{
	//http://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
	auto engine = std::default_random_engine{};
	std::shuffle(std::begin(elfList), std::end(elfList), engine);// always randomises into the same patern
	int q = 11;//for a break point
}

void EP_Game::EndGame()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("res/Game.wav");
	//Transitions from the game scene to the leaderboard scene
	cocos2d::Scene* nextScene = LeaderBoard::createScene();
	cocos2d::CCDirector::getInstance()->replaceScene(nextScene);
}

//=========================================//

void EP_Game::UpdateScoreDisplay()
{
	std::ostringstream convert;
	convert << GameManager::GetInstance()->GetScore();
	_scoreStr = "Score: " + convert.str();
	_scoreLabel->setString(_scoreStr);
}

void EP_Game::UpdateMultiplierDisplay()
{
	std::ostringstream convert;
	convert << GameManager::GetInstance()->GetMultiplier();
	_multiplierStr = "x" + convert.str();
	_multiplierLabel->setString(_multiplierStr);
}

void EP_Game::UpdateElfCounterDisplay()
{
	std::ostringstream convert;
	convert << GameManager::GetInstance()->GetNumOfElfs();
	_elvesLeftStr = "" + convert.str();
	_elfCounterLabel->setString(_elvesLeftStr);
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
		if (_elves[itterator]->_isUp)
		{
			cocos2d::Rect elfRect = cocos2d::Rect(
				_elves[itterator]->_rootNode->getPositionX(),
				_elves[itterator]->_rootNode->getPositionY(),
				100,
				100);

			if (elfRect.intersectsRect(touchRect))
			{
				_elves[itterator]->_isUp = false;
				_elves[itterator]->ElfHit(_elves[itterator]);
			}
			else
				GameManager::GetInstance()->TakeFromMultiplier();

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