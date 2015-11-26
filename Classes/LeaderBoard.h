#pragma once
#ifndef __LEADERBOARD_SCENE_H__
#define __LEADERBOARD_SCENE_H__
//=========================================//
//INCLUDES
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"
#include "MainMenu.h"
//=========================================//
class LeaderBoard : public cocos2d::Layer
{
private:
	GameManager* _gameManager;
	cocos2d::Scene* _scene;
	cocos2d::Node* _rootNode;
	cocos2d::ui::Button* _return;
public:
	//Constructor-Destructor
	LeaderBoard(GameManager* gameManager);
	~LeaderBoard();
	//Sets up the Leaderboard scene
	static cocos2d::Scene* createLeader();
	cocos2d::Scene* GetScene();
	//"Should" make button on leaderboard return to main menu.
	void ReturnButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
};
#endif //__LEADERBOARD_SCENE_H__