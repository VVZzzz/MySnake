#pragma once
#ifndef SNAKE_MAP_H_
#define SNAKE_MAP_H_
#include <iostream>
#include <string>
#include <Windows.h>
#include "snakemacros.h"

//Map�ฺ����ʾ�����е�һ��Ԫ�ذ�����snake score food �߽� ��ʼ��ʾ��Ϣ
//����snake food �ײ�������α仯,�ڸ��Ե����н���ʵ�� 

class Map 
{
public:
	void MapInit();  //��ʼ������߽�
	void MapInforInit();  //��ʼ�Ľ�����Ϣ
	
	void MapInforErase();  //���������Ϣ	

	void MapScoreUpdate(int s);  //��ʼ������Ϣ

};
#endif // !SNAKE_MAP_H_
