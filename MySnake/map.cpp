#include "map.h"

void Map::MapInit()
{
	Tool_GotoXY(0, 0);
	cout << string(GKINT_AREAWIDTH, '--') << endl;
	for (int i = 0; i < GKINT_AREAHEIGHT-1; ++i)
		cout << '|' << string(GKINT_AREAWIDTH - 2, ' ') 
		            << '|' << endl;
	cout << string(GKINT_AREAWIDTH, '--') << endl;
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
	Tool_GotoXY(0 , GKINT_AREAHEIGHT + 2 );
}

void Map::MapInforErase()
{
	/*
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
	Tool_GotoXY(0, GKINT_AREAHEIGHT + 2);
	*/
	for (int i = 1; i < GKINT_AREAHEIGHT - 1; i++) {
		for (int j = 1; j < GKINT_AREAWIDTH - 1; j++) {
			Tool_GotoXY(j, i);
			cout << ' ';
		}
	}
}

void Map::MapRetryInit() {
	Tool_GotoXY(GKINT_AREAWIDTH / 2, GKINT_AREAHEIGHT / 2);
	std::cout << "Game Over!";
	Tool_GotoXY(GKINT_AREAWIDTH / 2, GKINT_AREAHEIGHT / 2 + 1);
	std::cout << "1.Retry";
	Tool_GotoXY(GKINT_AREAWIDTH / 2, GKINT_AREAHEIGHT / 2 + 2);
	std::cout << "2.Exit";

	//重新定位光标至最后一行
	Tool_GotoXY(0, GKINT_AREAHEIGHT + 2);

}

void Map::MapScoreUpdate(int s) {
	Tool_GotoXY(GKINT_SCOREPOSX, GKINT_SCOREPOSY);
	cout << "score: " << s << endl;
	Tool_GotoXY(0, GKINT_AREAHEIGHT + 2);
}

void Map::MapHighScoreUpdate(int s) {
	Tool_GotoXY(GKINT_SCOREPOSX, GKINT_SCOREPOSY + 1);
	cout << "high score: " << s << endl;
	Tool_GotoXY(0, GKINT_AREAHEIGHT + 2);
}

void Map::MapSnakeUpdate(Snake & snake, Position oldsnaketail, bool isExpand) {
	if (!isExpand) {
		Tool_GotoXY(oldsnaketail.m_posx, oldsnaketail.m_posy);
		std::cout << ' ';
	}
	Position head = snake.get_headpos();
	if (snake.get_updown2left() == 1)
		Tool_GotoXY(head.m_posx - 1, head.m_posy);
	else if (snake.get_updown2left() == 2) {
		Tool_GotoXY(head.m_posx - 1, head.m_posy + 1);
		cout << ' ';
		Tool_GotoXY(head.m_posx, head.m_posy);
	}
	else if (snake.get_updown2left() == 3) {
		Tool_GotoXY(head.m_posx - 1, head.m_posy - 1);
		cout << ' ';
		Tool_GotoXY(head.m_posx, head.m_posy);
	}
	else 
		Tool_GotoXY(head.m_posx, head.m_posy);
	std::cout << snake.get_headchar();
	if (snake.get_length() > 0) {
		Tool_GotoXY(snake.get_bodyfirst().m_posx,snake.get_bodyfirst().m_posy);
		std::cout << 'o';
	}
}

void Map::MapFoodUpdate(Position oldfoodpos, Position newfoodpos) {
	Tool_GotoXY(oldfoodpos.m_posx, oldfoodpos.m_posy);
	std::cout << ' ';
	Tool_GotoXY(newfoodpos.m_posx, newfoodpos.m_posy);
	std::cout << '*';
}
