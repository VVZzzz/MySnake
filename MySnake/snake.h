#ifndef SNAKE_SNAKE_H_
#define SNAKE_SNAKE_H_
#pragma once

#include <Windows.h>
#include <deque>
#include "snakemacros.h"

//Snake����Ҫ����snake��״̬������
//ʹ��deque����snake�����������,��Ϊ����֧��������ʺͶ�ͷβ���/ɾ��Ԫ��
using std::deque;
class Snake
{
public:
	Snake() :m_snake_num(0), m_snake_runmode(0) { }
	const deque<Position> &get_posdeque() { return m_snake_posdeque; }
	Position get_headpos() { return m_snake_posdeque.front; }
	Position get_tailpos() { return m_snake_posdeque.back(); }
	int get_length() { return m_snake_num; }
	int get_direction() { return m_snake_runmode; }
	int get_speed() { return m_snake_speed; }
	void Snake_move();
	void Snake_changedirect(int mode);
	void Snake_expand();
	bool Snake_ishit();
private:
	deque<Position> m_snake_posdeque;
	const char *m_snake_phead;  //snakeͷ��
	int m_snake_num;               //sanke���岿��0�ĸ���
	int m_snake_runmode;           //snake�������е�״̬ 
	int m_snake_speed;             //snake�������ٶ�
	Position m_snake_oldtail;      //sanke�ɵ�β��λ��

};
#endif // !SNAKE_SNAKE_H_
