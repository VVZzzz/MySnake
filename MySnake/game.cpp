#include <math.h>
#include "game.h"

void Game::GameInit() {
	//改变控制台大小
	//system("mode con:cols=100 lines=30");
	//隐藏光标
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);

	m_game_end = false;
	m_game_score = 0;
	m_game_maxscore = max(m_game_maxscore, m_game_score);
	map.MapInit();
	map.MapInforInit();
	int level;
	while (std::cin>>level) {
		if (level >= 4) {
			m_game_end = true;
			break;
		}
		else if (level<4) {
			GameSetClock(pow(2, level));
			snake.Snake_init();
			food.Food_Gnerate();
			break;
		}

	}

}

void Game::GamePlay() {
	while (1) {
		if (m_game_end) {
			return;
		}

		//首先清空界面,在依次更新food snake score等
		map.MapInforErase();
		map.MapFoodUpdate(food.get_foodpos(), food.get_foodpos());
		map.MapSnakeUpdate(snake, snake.get_tailpos(), false);
		map.MapScoreUpdate(m_game_score);
		map.MapHighScoreUpdate(m_game_maxscore);

		while (1) {
			Sleep(500 / m_game_clock);  //等待...ms
			// 得到oldTail
			Position oldTail = snake.get_tailpos();
			int key = 0;
			bool isExpand = false;
			//_kbhit()等待键盘输入
			if (_kbhit()) {
				key = _getch();
				if (key==224) {
					key = _getch();
					switch (key) {
					case 72:
						snake.Snake_changedirect(GKUNI_UPMOVE);
						break;
					case 80:
						snake.Snake_changedirect(GKUNI_DOWNMOVE);
						break;
					case 75:
						snake.Snake_changedirect(GKUNI_LEFTMOVE);
						break;
					case 77:
						snake.Snake_changedirect(GKUNI_RIGHTMOVE);
						break;
					default:
						break;
					}
				}
			}
			snake.Snake_move();
			//ishit
			if (snake.Snake_ishit()) 
				break;
			if (snake.Snake_meetfood(food.get_foodpos())) {
				m_game_score++;
				map.MapScoreUpdate(m_game_score);
				snake.Snake_expand();
				Position oldfoodpos = food.get_foodpos();
				food.Food_Gnerate();
				map.MapFoodUpdate(oldfoodpos, food.get_foodpos());
				isExpand = true;
			}
			map.MapSnakeUpdate(snake, oldTail, isExpand);
		}
		m_game_maxscore = max(m_game_score, m_game_maxscore);
		map.MapHighScoreUpdate(m_game_maxscore);
		Sleep(500);
		map.MapRetryInit();
		int option;
		while (std::cin>>option) {
			if (option == 2) return;
			if (option==1) {
				GameInit();
				break;
			}
		}
	}
}

void Game::GameSetClock(int clock) {
	m_game_clock = clock;
}

int Game::getGameScore() {
	return m_game_score;
}

int Game::getGameHighestScore() {
	return m_game_maxscore;
}
