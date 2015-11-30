//INCLUDES
#include "EP_Game.h"
//=========================================//
USING_NS_CC;
//=========================================//
EP_Game::EP_Game(GameManager* previousGame)
{
	//Scene Setter
	_scene = EP_Game::createGame();
	_rootNode = cocos2d::CSLoader::createNode("GameScene.csb");
	_scene->addChild(_rootNode);

	//tEST
	this->schedule(schedule_selector(EP_Game::update));

	//What does this do???
	//this->scheduleUpdate();




	//Create Random number.
	srand(time(NULL));
	//Get Device Screen Size
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
bool EP_Game::init()
{
	//this->scheduleUpdate();
	this->schedule(schedule_selector(EP_Game::update));
	return true;
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
	//TO BE CONTINUED....
}
//=========================================//
cocos2d::Scene* EP_Game::GetScene()
{
	return this->_rootNode->getScene();
}
//=========================================//
void EP_Game::StartGame()
{
	//Sleep(3000); // give a countdown to the game beginning
	_running = true;
	//update(float deltaTime);
}
//=========================================//
void EP_Game::update(float deltaTime)
{
	//Sleep(3000);
	EndGame();

/*
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
			}		

		}
*/

}
//=========================================//
void EP_Game::EndGame()
{
	_running = false;
	LeaderBoard* nextScene = new LeaderBoard(_gameManager);
	cocos2d::CCDirector::getInstance()->replaceScene(nextScene->GetScene());
}