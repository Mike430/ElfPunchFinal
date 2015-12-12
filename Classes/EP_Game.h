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
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include "GameManager.h"
//#include "Elf.h"
#include "LeaderBoard.h"
//=========================================//
using namespace std;
//=========================================//

struct Elfs
{
	cocos2d::Node* _loadedNode;
	cocos2d::Vec2 _posDownY;
	cocos2d::Vec2 _posUpY;

	float _startingYPos;
	bool _isUp;
	int _timeLeft;
};

class EP_Game : public cocos2d::Layer
{
private:
	int _numOfElfs; // number of times the elfs will poke up
	float _speed;
	bool _running;
	bool _gameOver;
	int _frameCount;
	std::string _countStr;
	int _elfUpdateIndex;

	GameManager* _gameManager;
	Elfs* _elfs[ELF_NUMBER];
	cocos2d::ui::Text* _frameCounter;
	cocos2d::Sprite* _backdrop;
	cocos2d::Size _winSize;
	cocos2d::Node* _rootNode;
public:
	//Variables
	int _difficulty; //in range 1(easy) to 5(BRÜTAL)
	bool _allElvesDown;
	int _elfsUp;
	int _elfsDown;

	//Manditory cocos methods for initialisation
	CREATE_FUNC(EP_Game);
	static cocos2d::Scene* createScene();
	virtual bool init();

	//Custom Methods
	void update(float);
	void UpdateElves(float deltaTime);
	int SetATime();
	void EndGame();
	void UpdateScoreDisplay();
	
	void ElfPopUp(Elfs* elf);
	void ElfHit(Elfs* elf);
	void ElfPopDown(Elfs* elf);
	
	int CountElvesState(bool upOrDown);
	vector<Elfs*> MakeElfList(bool state);
	void ScrambleList(vector<Elfs*>& elfList);
	void UpdateElf(Elfs* elf, float deltaTime, bool state);

	//Callbacks
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouhCancelled(cocos2d::Touch*, cocos2d::Event*);
};

#endif //__EP_GAME_H__