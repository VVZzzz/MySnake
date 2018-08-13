#pragma once
#ifndef SNAKE_MAP_H_
#define SNAKE_MAP_H_
#include <iostream>
#include <string>
#include <Windows.h>
#include "snakemacros.h"
#include "snake.h"

//Map�ฺ����ʾ�����е�һ��Ԫ�ذ�����snake score food �߽� ��ʼ��ʾ��Ϣ
//����snake food �ײ�������α仯,�ڸ��Ե����н���ʵ�� 

class Map 
{
public:
	void MapInit();        //��ʼ������߽�
	void MapInforInit();   //��ʼ�Ľ�����Ϣ
	void MapInforErase();  //���������Ϣ	
	void MapRetryInit();   //Retry������Ϣ
	
	void MapScoreUpdate(int s);  //���½����Ϸ�����Ϣ
	void MapHighScoreUpdate(int s);
							     //���½�����snake��Ϣ
	void MapSnakeUpdate(Snake & snake, Position oldsnaketail,bool isExpand);  

	void MapFoodUpdate(Position oldfoodpos, Position newfoodpos);

};
#endif // !SNAKE_MAP_H_
