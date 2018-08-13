#pragma once
#ifndef SNAKE_SNAKE_H_
#define SNAKE_SNAKE_H_
#include <Windows.h>
#include <deque>
#include "snakemacros.h"

//Snake����Ҫ����snake��״̬������
//ʹ��deque����snake�����������,��Ϊ����֧��������ʺͶ�ͷβ���/ɾ��Ԫ��
using std::deque;
class Snake
{
public:
	Snake() = default;
	void Snake_init();
	// const deque<Position> &get_posdeque() { return m_snake_posdeque; }
	Position get_bodyfirst() {
		if (m_snake_num > 0) {
			// if (m_snake_updown2left == 1) return m_snake_posdeque[2];
			return m_snake_posdeque[1];
		}
		else
			return Position(-1, -1);
	}
	Position get_headpos() { return m_snake_posdeque.front(); }
	Position get_tailpos() { return m_snake_posdeque.back(); }
	int get_length() { return m_snake_num; }
	int get_direction() { return m_snake_runmode; }
	int get_speed() { return m_snake_speed; }
	const string get_headchar() { return m_snake_phead; }
	int get_updown2left() { return m_snake_updown2left; }
	void Snake_move();
	void Snake_changedirect(int mode);
	void Snake_expand();
	bool Snake_ishit();
	bool Snake_meetfood(Position foodpos);

private:
	deque<Position> m_snake_posdeque;
	string m_snake_phead;  //snakeͷ��
	int m_snake_num;               //sanke���岿��0�ĸ���
	int m_snake_runmode;           //snake�������е�״̬ 
	int m_snake_speed;             //snake�������ٶ�
	int m_snake_updown2left;	   //snake������תΪ����,��������תΪ�����µı�־
	Position m_snake_oldtail;      //sanke�ɵ�β��λ��

};
#endif // !SNAKE_SNAKE_H_
