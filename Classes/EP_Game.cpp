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
		_elfs[i]->_isAlive = false;
		_elfs[i]->_isUp = false;
		_elfs[i]->_position.x = 0.0f;
		_elfs[i]->_position.y = 0.0f;
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
		_elfs[i]->_position = _elfs[i]->_loadedNode->getPosition();
		_elfs[i]->_startingYPos = _elfs[i]->_position.y;
	}
	
	
	_running = true;
	_frameCount = 0;

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
		GameManager::GetInstance()->AddToScore(10);

		for (int i = 0; i < ELF_NUMBER; i++)
		{
			float previousX = _elfs[i]->_loadedNode->getPositionY();
			_elfs[i]->_loadedNode->setPositionY(previousX + 1);
		}

		//TRANSITION TEST 
		if (GameManager::GetInstance()->GetScore() >= 500)
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