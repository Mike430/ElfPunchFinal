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
	static GameManager* _gameManager;
	cocos2d::Sprite* _backdrop;
	cocos2d::Node* _rootNode;
	//Cocos2d Buttons
	cocos2d::ui::Button* _begin;
	cocos2d::ui::Button* _settings;
	cocos2d::ui::Button* _credits;
	cocos2d::ui::Button* _exit;
public:
	cocos2d::Scene* _nextScene;
	//Implements the "createScene()"
	CREATE_FUNC(MainMenu);
	//Sets up the scene
	static cocos2d::Scene* createScene();
	//Basically a cocos constructor
	virtual bool init();
	//Custom Methods
	void BeginButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void SettingsButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void CreditsButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void ExitButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
};
#endif // __MAIN_MENU_H__