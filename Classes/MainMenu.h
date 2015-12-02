#pragma once
#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"
#include "EP_Game.h"

class MainMenu : public cocos2d::Layer
{
private:
	//GameManager* _gameManager;
	cocos2d::Sprite* _backdrop;
	cocos2d::Node* _rootNode;

	cocos2d::ui::Button* _begin;
	cocos2d::ui::Button* _settings;
	cocos2d::ui::Button* _credits;
	cocos2d::ui::Button* _exit;
public:
	CREATE_FUNC(MainMenu);
	static cocos2d::Scene* createScene();
	virtual bool init();

	void BeginButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void SettingsButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void CreditsButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void ExitButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
};

#endif // __HELLOWORLD_SCENE_H__