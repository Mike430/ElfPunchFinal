#pragma once
#ifndef __EP_GAME_H__
#define __EP_GAME_H__
#define ELF_NUMBER 11

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"
#include "Elf.h"

using namespace std;



class EP_Game : public cocos2d::Layer
{
private:
	GameManager* _gameManager;
	Elf* _elfs[ELF_NUMBER]; // one for each hole in the game board
	int _numOfElfs; // number of times the elfs will poke up
	float _speed;
	bool _running;
	bool _gameOver;

	cocos2d::Size _winSize;
	cocos2d::Node* _rootNode;
public:
	CREATE_FUNC(EP_Game);
	static cocos2d::Scene* createScene();
	virtual bool init();
	void update(float);
};

#endif