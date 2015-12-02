#include "EP_Game.h"

cocos2d::Scene* EP_Game::createScene()
{
	// 'scene' is an autorelease object
	auto scene = cocos2d::Scene::create();

	// 'layer' is an autorelease object
	auto layer = EP_Game::create();

	// add layer as a child to scene
	scene->addChild(layer);

	return scene;
}

bool EP_Game::init()
{
	if (!Layer::init())
		return false;

	_rootNode = cocos2d::CSLoader::createNode("GameScene.csb");
	this->addChild(_rootNode);

	// get components from level
	_backdrop = (cocos2d::Sprite*)_rootNode->getChildByName("GameBoardScreen_1");
	_frameCounter = (cocos2d::ui::Text*)_rootNode->getChildByName("Frame_Counter");

	srand(time(NULL));
	_winSize = cocos2d::Director::getInstance()->getVisibleSize();
	//_gameManager = GameManager::GetInstance();
	_running = true;
	_frameCount = 0;

	this->scheduleUpdate();

	return true;
}

void EP_Game::update(float deltaTime)
{
	if (_running)
	{
		// Update the game
		_frameCount += 1;

		if (_frameCount >= 1000)
			_frameCount = 0;

		std::ostringstream convert;
		convert << _frameCount;
		_countStr = "Frame_Count: " + convert.str();
		_frameCounter->setString(_countStr);
	}
	if (_gameOver)
	{
		// Load leaderboard
	}
}