//INCLUDES
#include "EP_Game.h"
#include "LeaderBoard.h"
//=========================================//
EP_Game::EP_Game(GameManager* previousGame)
{
	//Scene Setter
	_scene = EP_Game::createGame();
	_rootNode = cocos2d::CSLoader::createNode("GameScene.csb");
	_scene->addChild(_rootNode);
	//_scene = _rootNode->getScene();// This does not work for reasons currently unknown


	//What does this do???
	this->scheduleUpdate();
	srand(time(NULL));
	_winSize = cocos2d::Director::getInstance()->getVisibleSize();



	//Extract information from the GameManager
	_gameManager = previousGame;
	_speed = _gameManager->GetSpeed();
	_gameManager->ResetScore();
	//Start the game
	_running = false;
	StartGame();
}
//=========================================//
cocos2d::Scene* EP_Game::createGame()
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
EP_Game::~EP_Game()
{
}
//=========================================//
cocos2d::Scene* EP_Game::GetScene()
{
	return this->_rootNode->getScene();
}
//=========================================//
void EP_Game::StartGame()
{
	Sleep(3000); // give a countdown to the game beginning
	_running = true;
}
//=========================================//
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



/*
//=========================================//
//==DELETED COMMENTS IN CASE STILL NEEDED==//
//=========================================//


*/