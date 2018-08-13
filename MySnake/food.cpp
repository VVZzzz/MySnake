#include "food.h"

void Food::Food_Gnerate() {
	//生成food随机坐标
	srand(unsigned int(time(NULL)));
	int newx = rand() % (GKINT_AREAWIDTH - 2) + 1;
	int newy = rand() % (GKINT_AREAHEIGHT - 2) + 1;
	foodpos.m_posx = newx;
	foodpos.m_posy = newy;
}

Position Food::get_foodpos() {
	return foodpos;
}

