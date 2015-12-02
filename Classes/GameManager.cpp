#include "GameManager.h"

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager()
{
	//Default Setting
	_instance->_score = 0;
	_instance->_numOfElfs = 50;
	_instance->_speed = 30.0f;
}


GameManager::~GameManager()
{
	delete _instance;
	_instance = nullptr;
}

GameManager* GameManager::GetInstance()
{
	if (_instance == nullptr)
		_instance = new GameManager();

	return _instance;
}

// Scoring
//======================================================================
int GameManager::GetScore()
{
	return _instance->_score;
}

void GameManager::AddToScore(int increment)
{
	_instance->_score += increment;
}

void GameManager::ResetScore()
{
	_instance->_score = 0;
}


// Elves
//======================================================================
void GameManager::SetNumOfElfs(int numOfElfs)
{
	_instance->_numOfElfs = numOfElfs;
}

int GameManager::GetNumOfElfs()
{
	return _instance->_numOfElfs;
}


// Speed
//======================================================================
void GameManager::SetSpeed(float newSpeed)
{
	_speed = newSpeed;
}

float GameManager::GetSpeed()
{
	return _speed;
}