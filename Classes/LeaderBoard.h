#pragma once
#ifndef __LEADERBOARD_SCENE_H__
#define __LEADERBOARD_SCENE_H__
//=========================================//
//INCLUDES
#include <iostream>
#include <fstream>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"
#include "MainMenu.h"
#include "CCFileUtils.h"
#include <string.h>
#include <sstream>
//=========================================//
using namespace std;
//=========================================//
class LeaderBoard : public cocos2d::Layer
{
private:
	//cocos2d
	cocos2d::Node* _rootNode;
	cocos2d::ui::Button* _return;
	cocos2d::ui::Text* _mail;
	cocos2d::ui::Text* _total;
	//Message variables
	bool mSet;
	string mPoor;
	string mOkay;
	string mGood;
	string sTotal;
public:
	//Implements the "createScene();"
	CREATE_FUNC(LeaderBoard);
	//Sets up the Leaderboard scene
	static cocos2d::Scene* createScene();
	//Basically a cocos constructor
	virtual bool init();
	//Custom Methods
	void ReturnButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	int Threshold(/*_score*/);
	void Messanger(/*_score*/);
};
#endif //__LEADERBOARD_SCENE_H__