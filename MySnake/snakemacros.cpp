#include "snakemacros.h"
void Tool_GotoXY(int x, int y)  //���ߺ���,������ƶ���XY
{
	COORD coord = { x, y };
	/*COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ�䶨��Ϊ��

	typedef struct _COORD {

	SHORT X; // horizontal coordinate

	SHORT Y; // vertical coordinate
	} COORD;*/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
