#pragma once
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#define ELF_NUMBER 11


#include <cocos2d.h>
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"
#include "Elf.h"

class EP_Game
{
private:
	GameManager* _gameManager;
	Elf* _elfs[ELF_NUMBER]; // one for each hole in the game board
	int _numOfElfs; // number of times the elfs will poke up
	float _speed;
	bool _running;

	cocos2d::Scene* _scene;
	cocos2d::Node* _rootNode;
public:
	EP_Game(GameManager* previousGame);
	~EP_Game();
	// See HelloWorld.h for the original versions of these methods
	static cocos2d::Scene* createScene();
	void Init();
	cocos2d::Scene* GetScene();

	void StartGame();

	void update(float deltaTime);
};

#endif