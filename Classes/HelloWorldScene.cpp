#include "HelloWorldScene.h"
#include "EP_Game.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("SplashScreen.csb");
    addChild(rootNode);

	//Music Pre-Loaders
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("res/Menu.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("res/Game.wav");

	//gameManager = new GameManager();
	//_gameManager->SetNumOfElfs(50);// parse in an integer that represents the number of times in one game an elf will pop up
	//_gameManager->SetSpeed(40.0f);// parse in a percentage
	//_gameManager->ResetScore();

	_begin = (ui::Button*)rootNode->getChildByName("BEGIN");
	//_settings = (ui::Button*)rootNode->getChildByName("SETTINGS");
	//_credits = (ui::Button*)rootNode->getChildByName("CREDITS");
	//_exit = (ui::Button*)rootNode->getChildByName("EXIT");

	_begin->addTouchEventListener(CC_CALLBACK_2(HelloWorld::BeginButtonPressed, this));
	//_settings->addTouchEventListener(CC_CALLBACK_2(HelloWorld::SettingsButtonPressed, this));
	//_credits->addTouchEventListener(CC_CALLBACK_2(HelloWorld::CreditsButtonPressed, this));
	//_exit->addTouchEventListener(CC_CALLBACK_2(HelloWorld::ExitButtonPressed, this));

	//Mike Branch Test

    return true;
}

void HelloWorld::BeginButtonPressed(Ref* sender, cocos2d::ui::Widget::TouchEventType type)
{
	//GameManager* gameManager = new GameManager();
	//gameManager->SetNumOfElfs(50);// parse in an integer that represents the number of times in one game an elf will pop up
	//gameManager->SetSpeed(40.0f);// parse in a percentage
	//gameManager->ResetScore();
	Scene* mainMenu = MainMenu::createScene();
	CCDirector::getInstance()->replaceScene(mainMenu);
}