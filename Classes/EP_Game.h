#pragma once
#ifndef __EP_GAME_H__
#define __EP_GAME_H__
#define ELF_NUMBER 11
#define ELF_APPEAR 50
//=========================================//
//INCLUDES
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"
#include "LeaderBoard.h"
#include "Elf.h"
//=========================================//
using namespace std;
//=========================================//
class EP_Game : public cocos2d::Layer
{
private:
	GameManager* _gameManager;
	//Hardcoded values for game enemies
	Elf* _elfs[ELF_NUMBER]; //One for each hole in the game board
	Elf*  _elves[ELF_APPEAR]; //How many times '_elfs' will genereate an elf
	//Variables for Game
	float _speed;
	bool _running;
	//cocos2d calls for scene and window size
	cocos2d::Size _winSize;
	cocos2d::Scene* _scene;
	cocos2d::Node* _rootNode;
public:
	//Constructor - Destructor
	EP_Game(GameManager* previousGame);
	~EP_Game();
	//Sets up the Game Scene
	static cocos2d::Scene* createGame();
	cocos2d::Scene* GetScene();
	//Game Related Functions
	void StartGame();
	void update(float deltaTime);
	void EndGame();
};
#endif