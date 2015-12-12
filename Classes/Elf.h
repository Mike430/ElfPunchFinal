#pragma once
#ifndef __ELF_NODE_H__
#define __ELF_NODE_H__

#include <cocos2d.h>

// I could use the cocos2d namespace here
// but I deliberatly will not so as to avoid ambiguity **mark**

class Elf : public cocos2d::Node
{
private:
	float _timeLeftUp;
	short int _elfType; // rare or common?
	//int _elfSprite; // which common or rare sprite do we use?

	cocos2d::Vec2 _position;// primary example for ambiguity **mark**
	float _startingYPos;
	cocos2d::Sprite* _character;
public:
	// Variables
	bool _isAlive;// should the elf have it's update method used?
	bool _isUp;// should the elf be up or down it's hole on the table?

	// Methods
	virtual bool init();
	Elf* create();

	void ElfUpdate(float deltaTime);

	void GetUp(float maxTimeUp);
	void GetDown();
};

#endif