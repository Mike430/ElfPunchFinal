#pragma once
#ifndef __ELF_NODE_H__
#define __ELF_NODE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include "GameManager.h"

// I could use the cocos2d namespace here
// but I deliberatly will not so as to avoid ambiguity **mark**

class Elf : public cocos2d::Node
{
private:
	cocos2d::Vec2 _posDownY;
	cocos2d::Vec2 _posUpY;

	cocos2d::Sprite* _missed;
	cocos2d::Sprite* _hit;
	cocos2d::Sprite* _common;
	cocos2d::Sprite* _rare;
public:
	// Variables
	cocos2d::Node* _rootNode;
	bool _isUp;
	int _name;
	float _startingYPos;
	int _timeLeft;

	// Create Methods
	Elf();
	~Elf();
	virtual bool init();
	static Elf* create();
	void Setup(float x, float y, int name);

	// Game Methods
	void UpdateElf(Elf* elf, bool state);
	void ElfPopUp(Elf* elf);
	void ElfHit(Elf* elf);
	void ElfPopDown(Elf* elf);
	int SetATime();
};

#endif