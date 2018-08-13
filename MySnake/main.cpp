#include "game.h"
int main()
{
	
	Game mygame;
	mygame.GameInit();
	mygame.GamePlay();
	
	/*
	Tool_GotoXY(0, 0);
	cout << "¡ú" << endl;
	char c;
	while (std::cin>>c) {
	}
	Tool_GotoXY(2, 0);
	cout << "¡ú" << endl;
	*/
	system("pause");
	return 0;
}