#pragma once
#ifndef SNAKE_GAME_H_
#define SNAKE_GAME_H_

//Game������������Ϸ��һЩ״̬
class Game 
{
	Game() : m_game_score(0), m_game_maxscore(0), m_game_difficult(1) { }
private:
	int m_game_difficult;
	int m_game_score;
	int m_game_maxscore;
};
#endif // !SNAKE_USER_H_
