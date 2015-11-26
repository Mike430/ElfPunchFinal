#include "LeaderBoard.h"
//=========================================//
LeaderBoard::LeaderBoard(GameManager* gameManager)
{
	//Scene Setter
	_scene = LeaderBoard::createLeader();
	_rootNode = cocos2d::CSLoader::createNode("LeaderBoard.csb");
	_scene->addChild(_rootNode);
	//Hire a Manager
	_gameManager = gameManager;
	//Button Setter
	_return = (cocos2d::ui::Button*)_rootNode->getChildByName("ReturnToStartScreen");
	//Button Presser
	_return->addTouchEventListener(CC_CALLBACK_2(LeaderBoard::ReturnButtonPressed, this));
}
//=========================================//
LeaderBoard::~LeaderBoard()
{
	//TO BE CONTINUED....
}
//=========================================//
cocos2d::Scene* LeaderBoard::createLeader()
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
cocos2d::Scene* LeaderBoard::GetScene()
{
	return this->_rootNode->getScene();
}
//=========================================//
void LeaderBoard::ReturnButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{
	MainMenu* nextScene = new MainMenu(_gameManager);
	cocos2d::CCDirector::getInstance()->replaceScene(nextScene->GetScene());
}