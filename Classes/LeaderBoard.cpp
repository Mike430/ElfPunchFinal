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
	//Label Setter
	_mail = (cocos2d::ui::Text*)_rootNode->getChildByName("Message");
	_total = (cocos2d::ui::Text*)_rootNode->getChildByName("HighScore");
	//Label Makers
	Messanger();
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
void LeaderBoard::Messanger(/*_score*/)
{
	mSet = false;
	//Messages to be displayed
	mPoor = "Well that was a poor attempt, try again!";
	mOkay = "That was an alright attempt, go again!";
	mGood = "Well Done that was great, have another go!";
	//Work out what message to send
	int mNum = Threshold(/*_score*/);
	//Here will be the score display
	
//_score will need to be converted from int to a string
//sTotal will be the int _score converted into a string.
	std::ostringstream change;
	change << 123456;  //GameManager::GetInstance()->GetScore();
	sTotal = change.str();
	_total->setString(sTotal);

	//Here will be the message display
	if (mNum == 1)
	{
		_mail->setString(mPoor);
	}
	else if (mNum == 2)
	{
		_mail->setString(mOkay);
	}
	else if (mNum == 3)
	{
		_mail->setString(mGood);
	}
	else
	{
		_mail->setString("DispError");
	}
}
//=========================================//
int LeaderBoard::Threshold(/*_score*/)
{
	int T = 0;
	
	//Here will be a caluelator to determine what string to send.

	//CASCADING IF STATMENTS

	return T;
}
//=========================================//