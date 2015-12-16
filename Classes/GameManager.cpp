#include "GameManager.h"

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager()
{
	//Default Setting
	_score = 0;
	_numOfElfs = 50;
	_difficulty = 30.0f;
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
	_instance->_score += (increment * _multiplier);
}

void GameManager::ResetScore()
{
	_instance->_score = 0;
}

int GameManager::GetMultiplier()
{
	return _multiplier;
}

void GameManager::AddToMultiplier()// 1, 2, 4, 8, 16, 32, 64, 128, etc
{
	if (_multiplier == 1)
		_multiplier = 2;
	else
		_multiplier = _multiplier * 2;
}

void GameManager::TakeFromMultiplier()// etc, 128, 64, 32, 16, 8, 4, 2, 1 and no less
{
	if (_multiplier <= 1)
		_multiplier = 1;
	else
		_multiplier = _multiplier / 2;
}

void GameManager::ResetMultiplier()
{
	_multiplier = 1;
	_multiplierItt = 1;
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


// Difficulty
//======================================================================
void GameManager::SetDifficulty(float newDifficulty)
{
	_difficulty = newDifficulty;
}

float GameManager::GetDifficulty()
{
	return _difficulty;
}

// GameState
//======================================================================
void GameManager::SetGameOver(bool state)
{
	_gameOver = state;
}

bool GameManager::GetGameOver()
{
	return _gameOver;
}