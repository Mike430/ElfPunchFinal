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
//=========================================//
class LeaderBoard : public cocos2d::Layer
{
private:
	//cocos2d
	cocos2d::Node* _rootNode;
	cocos2d::ui::Button* _return;
public:
	//Implements the "createScene();"
	CREATE_FUNC(LeaderBoard);
	//Sets up the Leaderboard scene
	static cocos2d::Scene* createScene();
	//Basically a cocos constructor
	virtual bool init();
	//Custom Methods
	void ReturnButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
};
#endif //__LEADERBOARD_SCENE_H__