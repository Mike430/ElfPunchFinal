#include "GameManager.h"


GameManager::GameManager()
{
	//Default Setting
	_score = 0;
	_numOfElfs = 50;
	_speed = 30.0f;
}


GameManager::~GameManager()
{
}


// Scoring
//======================================================================
int GameManager::GetScore()
{
	return _score;
}

void GameManager::AddToScore(int increment)
{
	_score += increment;
}

void GameManager::ResetScore()
{
	_score = 0;
}


// Elves
//======================================================================
void GameManager::SetNumOfElfs(int numOfElfs)
{
	_numOfElfs = numOfElfs;
}

int GameManager::GetNumOfElfs()
{
	return _numOfElfs;
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