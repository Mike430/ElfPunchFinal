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
#include "Elf.h"
#include "LeaderBoard.h"
#include "SimpleAudioEngine.h"
//=========================================//
using namespace std;
//=========================================//

class EP_Game : public cocos2d::Layer
{
private:
	bool _elvesInitialized;
	bool _running;
	int _frameCount;
	std::string _countStr;
	int _elfUpdateIndex;

	cocos2d::ui::Text* _frameCounter;
	cocos2d::Sprite* _backdrop;
	cocos2d::Size _winSize;
	cocos2d::Node* _rootNode;
public:
	//Variables
	Elf* _elves[ELF_NUMBER];
	bool _allElvesDown;
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
	
	int CountElvesState(bool upOrDown);
	vector<Elf*> MakeElfList(bool state);
	void ScrambleList(vector<Elf*>& elfList);

	//Callbacks
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouhCancelled(cocos2d::Touch*, cocos2d::Event*);
};

#endif //__EP_GAME_H__