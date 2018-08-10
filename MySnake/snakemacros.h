#pragma once
#ifndef SNAKE_MACROS_H_
#define SNAKE_MACROS_H_

//������������Map�����ڵ���Ϣ
using std::string;
using std::cout;
using std::endl;
using std::deque;

//map macros
const int GKINT_AREAWIDTH = 50;
const int GKINT_AREAHEIGHT = 30;
const int GKINT_INITPOSX = GKINT_AREAWIDTH / 2 - 5;
const int GKINT_INITPOSY = GKINT_AREAHEIGHT / 2 - 5;
const int GKINT_SCOREPOSX = GKINT_AREAWIDTH + 5;
const int GKINT_SCOREPOSY = GKINT_AREAHEIGHT / 2 - 5;

//snake
const char GKCHAR_HEADUP[] = "��";
const char GKCHAR_HEADDOWN[] = "��";
const char GKCHAR_HEADLEFT[] = "��";
const char GKCHAR_HEADRIGHT[] = "��";
const string GSTR_HEAD = "��������";

//game
const unsigned GKUNI_UPMOVE = 0;
const unsigned GKUNI_DOWNMOVE = 1;
const unsigned GKUNI_LEFTMOVE = 2;
const unsigned GKUNI_RIGHTMOVE = 3;

struct Position
{
	Position() : m_posx(0), m_posy(0) { }
	Position(int x, int y) : m_posx(x), m_posy(y) { }
	Position &operator=(Position &rhs);
	int m_posx, m_posy;
};

inline
Position &Position::operator=(Position &rhs)
{
	m_posx = rhs.m_posx;
	m_posy = rhs.m_posy;
}

inline 
bool operator==(Position &lhs, Position &rhs)
{
	return (lhs.m_posx == rhs.m_posx) && (lhs.m_posy == rhs.m_posy);
}

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
#endif // !SNAKE_MACROS_H_