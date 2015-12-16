//INCLUDE
#include "MainMenu.h"
//=========================================//
cocos2d::Scene* MainMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = cocos2d::Scene::create();
	// 'layer' is an autorelease object
	auto layer = MainMenu::create();
	// add layer as a child to scene
	scene->addChild(layer);
	//RETURN
	return scene;
}
//=========================================//
bool MainMenu::init()
{
	//A call to super? C++ doesn't have one so this is needed.
	if (!Layer::init())
	{
		return false;
	}
	//Scene Setter
	_rootNode = cocos2d::CSLoader::createNode("MainMenu.csb");
	this->addChild(_rootNode);
	_nextScene = nullptr;
	//Sound Setter
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("res/Menu.wav", true);

	//_gameManager = GameManager::GetInstance();

	//Button Setters
	_backdrop = (cocos2d::Sprite*)_rootNode->getChildByName("Default");
	_begin = (cocos2d::ui::Button*)_rootNode->getChildByName("BEGIN");
	_settings = (cocos2d::ui::Button*)_rootNode->getChildByName("SETTINGS");
	_credits = (cocos2d::ui::Button*)_rootNode->getChildByName("CREDITS");
	_exit = (cocos2d::ui::Button*)_rootNode->getChildByName("EXIT");
	//Button Pressers
	_begin->addTouchEventListener(CC_CALLBACK_2(MainMenu::BeginButtonPressed, this));
	//_settings->addTouchEventListener(CC_CALLBACK_2(MainMenu::SettingsButtonPressed, this));
	_credits->addTouchEventListener(CC_CALLBACK_2(MainMenu::CreditsButtonPressed, this));
	//_exit->addTouchEventListener(CC_CALLBACK_2(MainMenu::ExitButtonPressed, this));
	GameManager::GetInstance()->SetGameOver(false);
	GameManager::GetInstance()->SetNumOfElfs(250);
	GameManager::GetInstance()->SetDifficulty(5);//highest
	

	//INIT ENDS IN RETURN TRUE
	return true;
}
//=========================================//
void MainMenu::BeginButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("res/Menu.wav");
	GameManager::GetInstance()->ResetScore();
	
	if (_nextScene == nullptr)
	{
		_nextScene = EP_Game::createScene();
		cocos2d::CCDirector::getInstance()->replaceScene(_nextScene);
	}
}
//=========================================//
void MainMenu::SettingsButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
}
//=========================================//
void MainMenu::CreditsButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic("res/Menu.wav");
	/*DOES NOT LEAD TO CREDITS, temporary link to leaderboard for test purposes.
	A new button is needed  so credits/leaderboard can be accessed seperately*/
	cocos2d::Scene* nextScene = LeaderBoard::createScene();
	cocos2d::CCDirector::getInstance()->replaceScene(nextScene);
}
//=========================================//
void MainMenu::ExitButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
}