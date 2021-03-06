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
void LeaderBoard::Messanger()
{
	mSet = false;
	//Messages to be displayed
	mPoor = "Welp, everyone start\n somewhere, try again?";
	mOkay = "That was an alright\n attempt, go again!";
	mGood = "Well Done that was...\n good... have another go!";
	mGreat = "Well I'm impressed\n , can you top it?";
	mMarvel = "Astonishing, Magestic,\n I have no words!";
	mGodlike = "gg, brb, gotta make\n a game worthy such skill";
	//Message Colours
	red = cocos2d::Color3B(255, 0, 0);
	black = cocos2d::Color3B(0, 0, 0);
	blue = cocos2d::Color3B(0, 0, 255);
	//Work out what message to send
	int mNum = Threshold();
	//Here will be the score display
	
	//Int to String conversion
	std::ostringstream change;
	change << GameManager::GetInstance()->GetScore();
	sTotal = change.str();
	_total->setString(sTotal);

	//Here will be the message display
	if (mNum == 1)
	{
		_mail->setString(mPoor);
		_mail->setColor(red);
	}
	else if (mNum == 2)
	{
		_mail->setString(mOkay);
		_mail->setColor(black);
	}
	else if (mNum == 3)
	{
		_mail->setString(mGood);
		_mail->setColor(blue);
	}
	else
	{
		_mail->setString("DispError");
		_mail->setColor(red);
	}
}
//=========================================//
int LeaderBoard::Threshold()
{
	int T = 0;
	int tMoney = GameManager::GetInstance()->GetScore();

	//Here will be a caluelator to determine what string to send.
	if (tMoney <= 500)
	{
		T = 1;
	}
	else if ((tMoney >= 501) && (tMoney <= 1000))
	{
		T = 2;
	}
	else if ((tMoney >= 1001) && (tMoney <= 2000))
	{
		T = 3;
	}
	else if ((tMoney >= 2001) && (tMoney <= 5000))
	{
		T = 4;
	}
	else if ((tMoney >= 5001) && (tMoney <= 8000))
	{
		T = 5;
	}
	else if  (tMoney >= 8001)
	{
		T = 6;
	}
	else
	{
		T = 0;
	}

	return T;
}
//=========================================//