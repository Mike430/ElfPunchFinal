#pragma once
#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "cocos2d.h"

class GameManager
{
private:
	int _score;
	int _numOfElfs;// number of times the elfs will poke up
	float _difficulty;// a percentage that will represent the rate at which elfs will appear
	bool _gameOver;
	static GameManager* _instance;

	GameManager();
public:
	static GameManager* GetInstance();
	~GameManager();

	// Scoring
	//======================================================================
	int GetScore();
	void AddToScore(int increment);
	void ResetScore();

	// Elves
	//======================================================================
	void SetNumOfElfs(int numOfElfs);
	int GetNumOfElfs();

	// Difficulty
	//======================================================================
	void SetDifficulty(float newDifficulty);
	float GetDifficulty();

	// GameState
	//======================================================================
	void SetGameOver(bool state);
	bool GetGameOver();
};

#endif // __GAMEMANAGER_H__