#pragma once
#ifndef __EP_GAME_H__
#define __EP_GAME_H__
#define ELF_NUMBER 11
#define ELF_APPEAR 50

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

	//int _numOfElfs; // number of times the elfs will poke up
	Elf*  _elves[ELF_APPEAR];//This ^ would be better hardcoded like this
	float _speed;
	bool _running;
	cocos2d::Size _winSize;

	cocos2d::Scene* _scene;
	cocos2d::Node* _rootNode;
public:
	EP_Game(GameManager* previousGame);
	~EP_Game();
	// See HelloWorld.h for the original versions of these methods
	static cocos2d::Scene* createScene();
	//virtual bool init();
	//void Init();
	cocos2d::Scene* GetScene();

	void StartGame();

	void update(float deltaTime);
};

#endif