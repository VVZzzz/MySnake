#pragma once
#ifndef SNAKE_GAME_H_
#define SNAKE_GAME_H_
#include "map.h"
#include "snake.h"
#include "food.h"

//Game������������Ϸ��һЩ״̬
class Game 
{
public:
	Game() = default;
	~Game() = default;
	void GameInit();
	void GamePlay();
	void GameEnd();

	void GameSetClock(int);
	int getGameScore();
	int getGameHighestScore();
private:
	int m_game_clock;
	int m_game_score;
	int m_game_maxscore;
	bool m_game_end;
	Map map;
	Snake snake;
	Food food;
};
#endif // !SNAKE_USER_H_
