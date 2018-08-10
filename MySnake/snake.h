#ifndef SNAKE_SNAKE_H_
#define SNAKE_SNAKE_H_
#pragma once

#include <Windows.h>
#include <deque>
#include "snakemacros.h"

//Snake类主要保存snake的状态及更新
//使用deque保存snake各个点的坐标,因为可以支持随机访问和对头尾添加/删除元素
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
	const char *m_snake_phead;  //snake头部
	int m_snake_num;               //sanke身体部分0的个数
	int m_snake_runmode;           //snake正在运行的状态 
	int m_snake_speed;             //snake的运行速度
	Position m_snake_oldtail;      //sanke旧的尾部位置

};
#endif // !SNAKE_SNAKE_H_
