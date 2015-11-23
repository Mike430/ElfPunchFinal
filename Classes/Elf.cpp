#include "Elf.h"


Elf::Elf()
{
	_isAlive = false;
	_isUp = false;
	_timeLeftUp = 0.0f;
}

/*Elf* Elf::ElfInit()
{
	// Set up the sprites and get the positions
}*/

Elf::~Elf()
{
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