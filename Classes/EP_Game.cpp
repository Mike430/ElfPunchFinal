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
	
	
	//_gameManager = GameManager::GetInstance();
	
	
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

		//TRANSITION TEST 
		if (_frameCount >= 500)
		{
			EndGame();
		}

		std::ostringstream convert;
		convert << _frameCount;
		_countStr = "Frame_Count: " + convert.str();
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