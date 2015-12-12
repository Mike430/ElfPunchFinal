#include "Elf.h"


Elf* Elf::create()
{
	Elf* newElf = new Elf();
	if (newElf->init())
	{
		newElf->autorelease();
		return newElf;
	}
	else
	{
		CC_SAFE_DELETE(newElf);
		return nullptr;
	}
	return newElf;
}

bool Elf::init()
{
	if (!Node::init())
	{
		return false;
	}

	_isAlive = false;
	_isUp = false;
	_timeLeftUp = 0.0f;
	_elfType = 0; // 0 = common, 1 = rare ()
	_startingYPos = 0.0f;
	
	return true;
}


void Elf::ElfUpdate(float deltaTime)
{
	_timeLeftUp -= deltaTime;
	if(_timeLeftUp <= 0.0f)
	{
		if (_isUp)
			GetDown(); // start moving the elf downwards
		else
		{
			if (_position.y < _startingYPos)
				// when the elf is back in his hole stop updating
				_isAlive = false;
		}
	}
}


void Elf::GetUp(float maxTimeUp)
{
	_isAlive = true;
	_isUp = true;
	_timeLeftUp = maxTimeUp;
}

void Elf::GetDown()
{
	_isUp = false;
}