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
	//float _posDownY;
	//float _posUpY;

	float _startingYPos;
	bool _isAlive;// should the elf have it's update method used?
	bool _isUp;// should the elf be up or down it's hole on the table?
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
	int _elfsUp;
	int _elfsDown;

	//Manditory cocos methods for initialisation
	CREATE_FUNC(EP_Game);
	static cocos2d::Scene* createScene();
	virtual bool init();

	//Custom Methods
	void update(float);
	void UpdateElves();
	void EndGame();
	void UpdateScoreDisplay();
	void ElfPopUp(Elfs* elf);
	void ElfHit(Elfs* elf);
	void ElfPopDown(Elfs* elf);
	int CountElvesState(bool upOrDown);
	vector<Elfs*> MakeElfList();
	vector<Elfs*> ScrambleList(vector<Elfs*> elfList);

	//Callbacks
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouhCancelled(cocos2d::Touch*, cocos2d::Event*);
};

#endif //__EP_GAME_H__