#pragma once
#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__
//=========================================//
//INCLUDES
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"
#include "EP_Game.h"
#include "LeaderBoard.h"
//=========================================//
class MainMenu : public cocos2d::Layer
{
private:
	GameManager* _gameManager;
	//cocos2d scene
	cocos2d::Scene* _scene;
	cocos2d::Node* _rootNode;
	//cocos2d Buttons
	cocos2d::ui::Button* _begin;
	cocos2d::ui::Button* _settings;
	cocos2d::ui::Button* _credits;
	cocos2d::ui::Button* _exit;
public:
	//Constructor - Destructor
	MainMenu(GameManager* gameManager);
	~MainMenu();
	//Setsu up the MainMenu scene
	static cocos2d::Scene* createMenu();
	cocos2d::Scene* GetScene();
	//Buttons taking to different scenes in the game
	void BeginButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);//GAME_SCENE
	void SettingsButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);//OPTIONS_SCENE
	void CreditsButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);//CREDITS/LEADERBOARD SCENE
	void ExitButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);//CLOSE_APPLICATION
};
#endif // __MAIN_MENU_SCENE_H__