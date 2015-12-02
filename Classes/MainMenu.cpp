#include "MainMenu.h"

bool MainMenu::init()
{
	if (!Layer::init())
		return false;

	_rootNode = cocos2d::CSLoader::createNode("MainMenu.csb");
	this->addChild(_rootNode);

	//_gameManager = gameManager;

	_backdrop = (cocos2d::Sprite*)_rootNode->getChildByName("Default");
	_begin = (cocos2d::ui::Button*)_rootNode->getChildByName("BEGIN");
	_settings = (cocos2d::ui::Button*)_rootNode->getChildByName("SETTINGS");
	_credits = (cocos2d::ui::Button*)_rootNode->getChildByName("CREDITS");
	_exit = (cocos2d::ui::Button*)_rootNode->getChildByName("EXIT");

	_begin->addTouchEventListener(CC_CALLBACK_2(MainMenu::BeginButtonPressed, this));
	// CAUTION, THE METHODS BELOW ARE NOT WORKING FOR A REASON I'VE YET TO WORK OUT
	//_settings->addTouchEventListener(CC_CALLBACK_2(MainMenu::SettingsButtonPressed, this));
	//_credits->addTouchEventListener(CC_CALLBACK_2(MainMenu::CreditsButtonPressed, this));
	//_exit->addTouchEventListener(CC_CALLBACK_2(MainMenu::ExitButtonPressed, this));

	this->scheduleUpdate();

	return true;
}

cocos2d::Scene* MainMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = cocos2d::Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenu::create();

	// add layer as a child to scene
	scene->addChild(layer);

	return scene;
}


void MainMenu::BeginButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	//EP_Game* nextScene = new EP_Game(_gameManager);
	//cocos2d::CCDirector::getInstance()->replaceScene(nextScene->GetScene());
}

void MainMenu::SettingsButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
}

void MainMenu::CreditsButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
}

void MainMenu::ExitButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
}