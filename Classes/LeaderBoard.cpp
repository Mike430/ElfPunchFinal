//INCLUDES
#include "LeaderBoard.h"
//=========================================//
cocos2d::Scene* LeaderBoard::createScene()
{
	// 'scene' is an autorelease object
	auto scene = cocos2d::Scene::create();
	// 'layer' is an autorelease object
	auto layer = LeaderBoard::create();
	// add layer as a child to scene
	scene->addChild(layer);
	//RETURN
	return scene;
}
//=========================================//
bool LeaderBoard::init()
{
	//A call to super? C++ doesn't have one so this is needed.
	if (!Layer::init())
	{
		return false;
	}
	//Scene Setter
	_rootNode = cocos2d::CSLoader::createNode("LeaderBoard.csb");
	this->addChild(_rootNode);
	//Button Setter
	_return = (cocos2d::ui::Button*)_rootNode->getChildByName("ReturnToStartScreen");
	//Button Presser
	_return->addTouchEventListener(CC_CALLBACK_2(LeaderBoard::ReturnButtonPressed, this));
	//INIT ENDS IN RETURN TRUE
	return true;
}
//=========================================//
void LeaderBoard::ReturnButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type)
{
	/*'Should' make it so when the button pressed on the leaderboard
	Scene changes back to the main menu*/
	cocos2d::Scene* nextScene = MainMenu::createScene();
	cocos2d::CCDirector::getInstance()->replaceScene(nextScene);
}
//=========================================//