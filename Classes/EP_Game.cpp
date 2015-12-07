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

		cocos2d::Vec2 up = cocos2d::Vec2(posX, posY_Up);
		cocos2d::Vec2 down = cocos2d::Vec2(posX, posY_Down);

		_elfs[i]->_posUpY = up;
		_elfs[i]->_posDownY = down;

		_elfs[i]->_isAlive = false;
		_elfs[i]->_isUp = false;
	}
	
	
	_running = true;
	_frameCount = 0;
	_elfUpdateIndex = 0;

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
		GameManager::GetInstance()->AddToScore(1);

		if (_frameCount == 10)
		{
			if (!_elfs[_elfUpdateIndex]->_isUp)
			{
				cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(0.1, _elfs[_elfUpdateIndex]->_posUpY);
				_elfs[_elfUpdateIndex]->_loadedNode->runAction(moveTo);
				_elfs[_elfUpdateIndex]->_isUp = true;
			}
			else
			{
				cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(0.1, _elfs[_elfUpdateIndex]->_posDownY);
				_elfs[_elfUpdateIndex]->_loadedNode->runAction(moveTo);
				_elfs[_elfUpdateIndex]->_isUp = false;
			}

			_elfUpdateIndex += 1;
			if (_elfUpdateIndex >= 11)
				_elfUpdateIndex = 0;

			_frameCount = 0;
		}

		//TRANSITION TEST 
		if (GameManager::GetInstance()->GetScore() >= 1000)
		{
			EndGame();
		}

		std::ostringstream convert;
		convert << GameManager::GetInstance()->GetScore();
		_countStr = "Score: " + convert.str();
		_frameCounter->setString(_countStr);
	}
	if (_gameOver)
	{
		//EndGame();
	}
}
//=========================================//
void EP_Game::EndGame()
{
	//Transitions from the game scene to the leaderboard scene
	cocos2d::Scene* nextScene = LeaderBoard::createScene();
	cocos2d::CCDirector::getInstance()->replaceScene(nextScene);
}