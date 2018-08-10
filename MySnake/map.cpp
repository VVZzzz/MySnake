#include "map.h"

void Map::MapInit()
{
	cout << string(GKINT_AREAWIDTH, '_') << endl;
	for (int i = 0; i < GKINT_AREAHEIGHT; ++i)
		cout << '|' << string(GKINT_AREAWIDTH - 2, ' ') 
		            << '|' << endl;
	cout << string(GKINT_AREAWIDTH, '-') << endl;
}



void Map::MapInforInit()
{
	Tool_GotoXY(GKINT_INITPOSX, GKINT_INITPOSY + 2);
	cout << "Snake Game"<< endl;
	Tool_GotoXY(GKINT_INITPOSX, GKINT_INITPOSY + 4);
	cout << "1. easy " << endl;
	Tool_GotoXY(GKINT_INITPOSX, GKINT_INITPOSY + 6);
	cout << "2. normal " << endl;
	Tool_GotoXY(GKINT_INITPOSX, GKINT_INITPOSY + 8);
	cout << "3. hard " << endl;
	Tool_GotoXY(GKINT_INITPOSX, GKINT_INITPOSY + 10);
	cout << "4. exit " << endl;

	//重新定位光标至最后一行
	Tool_GotoXY(0 , GKINT_AREAHEIGHT + 1 );
}

void Map::MapInforErase()
{
	Tool_GotoXY(GKINT_INITPOSX, GKINT_INITPOSY + 2);
	cout << string(10,' ') << endl;
	Tool_GotoXY(GKINT_INITPOSX, GKINT_INITPOSY + 4);
	cout << string(10, ' ') << endl;
	Tool_GotoXY(GKINT_INITPOSX, GKINT_INITPOSY + 6);
	cout << string(10, ' ') << endl;
	Tool_GotoXY(GKINT_INITPOSX, GKINT_INITPOSY + 8);
	cout << string(10, ' ') << endl;
	Tool_GotoXY(GKINT_INITPOSX, GKINT_INITPOSY + 10);
	cout << string(10, ' ') << endl;

	//重新定位光标至最后一行
	Tool_GotoXY(0, GKINT_AREAHEIGHT + 1);
}

void Map::MapScoreUpdate(int s)
{
	Tool_GotoXY(GKINT_SCOREPOSX, GKINT_SCOREPOSY);
	cout << "score: " << s << endl;
}