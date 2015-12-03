#pragma once
#ifndef __EP_GAME_H__
#define __EP_GAME_H__
#define ELF_NUMBER 11
//=========================================//
//INCLUDES
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <string.h>
#include <sstream>
#include "GameManager.h"
#include "Elf.h"
#include "LeaderBoard.h"
//=========================================//
using namespace std;
//=========================================//
class EP_Game : public cocos2d::Layer
{
private:
	GameManager* _gameManager;
	Elf* _elfs[ELF_NUMBER]; // one for each hole in the game board
	int _numOfElfs; // number of times the elfs will poke up
	float _speed;
	bool _running;
	bool _gameOver;

	int _frameCount;
	std::string _countStr;

	cocos2d::ui::Text* _frameCounter;
	cocos2d::Sprite* _backdrop;
	cocos2d::Size _winSize;
	cocos2d::Node* _rootNode;
public:
	//Implements the "createScene();"
	CREATE_FUNC(EP_Game);
	//Sets up the Leaderboard scene
	static cocos2d::Scene* createScene();
	//Basically a cocos constructor
	virtual bool init();
	//Custom Methods
	void update(float);
	void EndGame();
};

#endif //__EP_GAME_H__