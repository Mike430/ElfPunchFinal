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