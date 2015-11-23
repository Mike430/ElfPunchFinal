#include "EP_Game.h"
//CHRIS Don't forget to ADD, COMMIT, PUSH
//SIDE NOTE, totally almost forgot to mention -A

EP_Game::EP_Game(GameManager* previousGame)
{
	//Switch the scenes
	//_scene = cocos2d::Scene::create();
	//_rootNode = cocos2d::CSLoader::createNode("SecondScreen.csb");//root node is undefined
	//_scene->addChild(_rootNode);
	_scene = cocos2d::Scene::create();
	_rootNode = cocos2d::CSLoader::createNode("GameScene.csb");
	//_scene = _rootNode->getScene();// This does not work for reasons currently unknown
	_scene->addChild(_rootNode);
	//addChild(_rootNode);// This line stops the next scene from displaying for some reason
	this->scheduleUpdate();
	srand(time(NULL));
	_winSize = cocos2d::Director::getInstance()->getVisibleSize();

	//Extract information from the GameManager
	_gameManager = previousGame;
	_numOfElfs = _gameManager->GetNumOfElfs();
	_speed = _gameManager->GetSpeed();
	_gameManager->ResetScore();

	//Start the game
	_running = false;
	StartGame();
}

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

EP_Game::~EP_Game()
{
}

cocos2d::Scene* EP_Game::GetScene()
{
	return _rootNode->getScene();
	//return _scene;
}

void EP_Game::StartGame()
{
	Sleep(3000); // give a countdown to the game beginning
	_running = true;
}

void EP_Game::update(float deltaTime)
{
	if (_running)
	{
		// Update the game
		for (int i = 0; i < ELF_NUMBER; i++)
		{
			if (_elfs[i]->_isAlive)
			{
				_elfs[i]->ElfUpdate(deltaTime);
			}
			/*else
			{
				// in this part we will test the probability
				// of the elf waking up. Then call "elf[i]->GetUp();"
				// no need to set the elf's alive state here
			}*/
		}
	}
}