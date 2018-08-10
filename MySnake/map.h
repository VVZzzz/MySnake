#pragma once
#ifndef SNAKE_MAP_H_
#define SNAKE_MAP_H_
#include <iostream>
#include <string>
#include <Windows.h>
#include "snakemacros.h"

//Map类负责显示画面中的一切元素包括：snake score food 边界 初始提示信息
//对于snake food 底层数据如何变化,在各自的类中进行实现 

class Map 
{
public:
	void MapInit();  //初始化区域边界
	void MapInforInit();  //初始的界面信息
	
	void MapInforErase();  //清除界面信息	

	void MapScoreUpdate(int s);  //初始分数信息

};
#endif // !SNAKE_MAP_H_
