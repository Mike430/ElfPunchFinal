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


	srand(time(NULL));
	_winSize = cocos2d::Director::getInstance()->getVisibleSize();
	//_gameManager = GameManager::GetInstance();
	_running = true;

	this->scheduleUpdate();

	return true;
}

void EP_Game::update(float deltaTime)
{
	if (_running)
	{
		// Update the game
	}
	if (_gameOver)
	{
		// Load leaderboard
	}
}