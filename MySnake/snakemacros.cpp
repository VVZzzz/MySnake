#include "snakemacros.h"
void Tool_GotoXY(int x, int y)  //工具函数,将光标移动至XY
{
	COORD coord = { x, y };
	/*COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。其定义为：

	typedef struct _COORD {

	SHORT X; // horizontal coordinate

	SHORT Y; // vertical coordinate
	} COORD;*/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
