//INCLUDES
#include "MainMenu.h"
//=========================================//
MainMenu::MainMenu(GameManager* gameManager)
{
	//Scene Setter
	_scene = MainMenu::createMenu();
	_rootNode = cocos2d::CSLoader::createNode("MainMenu.csb");
	_scene->addChild(_rootNode);
	//Game Manager
	_gameManager = gameManager;
	//Button Setter
	_begin = (cocos2d::ui::Button*)_rootNode->getChildByName("BEGIN");
	_settings = (cocos2d::ui::Button*)_rootNode->getChildByName("SETTINGS");
	_credits = (cocos2d::ui::Button*)_rootNode->getChildByName("CREDITS");
	_exit = (cocos2d::ui::Button*)_rootNode->getChildByName("EXIT");
	//Button Pressers
	_begin->addTouchEventListener(CC_CALLBACK_2(MainMenu::BeginButtonPressed, this));
	
	//=========================================////=========================================//
	/*	MIKE, the methods that are still commented will not work as they are empty.
	_credits now works as it has something in it.	*/
	// CAUTION, THE METHODS BELOW ARE NOT WORKING FOR A REASON I'VE YET TO WORK OUT
	//_settings->addTouchEventListener(CC_CALLBACK_2(MainMenu::SettingsButtonPressed, this));
	_credits->addTouchEventListener(CC_CALLBACK_2(MainMenu::CreditsButtonPressed, this));
	//_exit->addTouchEventListener(CC_CALLBACK_2(MainMenu::ExitButtonPressed, this));
	//=========================================////=========================================//
}
//=========================================//
MainMenu::~MainMenu()
{
	//TO BE CONTINUED....
}
//=========================================//
cocos2d::Scene* MainMenu::createMenu()
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
cocos2d::Scene* MainMenu::GetScene()
{
	return this->_rootNode->getScene();
}
//=========================================//
void MainMenu::BeginButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	EP_Game* nextScene = new EP_Game(_gameManager);
	cocos2d::CCDirector::getInstance()->replaceScene(nextScene->GetScene());
}
//=========================================//
void MainMenu::SettingsButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	//TO BE CONTINUED....
}
//=========================================//
void MainMenu::CreditsButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	/*DOES NOT LEAD TO CREDITS, temporary link to leaderboard for test purposes.
	A new button is needed  so credits/leaderboard can be accessed seperately*/
	LeaderBoard* nextScene = new LeaderBoard(_gameManager);
	cocos2d::CCDirector::getInstance()->replaceScene(nextScene->GetScene());
}
//=========================================//
void MainMenu::ExitButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	//TO BE CONTINUED....
}
//=========================================//