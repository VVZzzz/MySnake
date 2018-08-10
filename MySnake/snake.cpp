#include "snakemacros.h"
#include "snake.h"
#include "map.h"
//void Snake::UpdateSnake(unsigned movemode)
//{
//	Position oldheadpos = m_headpos;
//	switch (movemode)
//	{
//	case 0:
//		--m_headpos.m_posy;
//		m_phead = GKCHAR_HEADUP;
//	case 1:
//		++m_headpos.m_posy;
//		m_phead = GKCHAR_HEADDOWN;
//	case 2:
//		--m_headpos.m_posx;
//		m_phead = GKCHAR_HEADLEFT;
//	case 3:
//		++m_headpos.m_posx;
//		m_phead = GKCHAR_HEADRIGHT;
//	default:
//		break;
//	}
//	
//	//newhead设为相应的方向
//	Tool_GotoXY(m_headpos.m_posx, m_headpos.m_posy);
//	cout << *m_phead;
//	//oldhead设为body'0'
//	Tool_GotoXY(oldheadpos.m_posx, oldheadpos.m_posy);
//	cout << "0";
//	//tail设为' '
//	Tool_GotoXY(m_tailpos.m_posx, m_tailpos.m_posx);
//
//}

void Snake::Snake_move()
{
	m_snake_oldtail = m_snake_posdeque.back();  //更新oldtailpos
	m_snake_posdeque.pop_back();                //将尾部位置删去
	Position temp_headpos = m_snake_posdeque.front();
	switch (m_snake_runmode)
	{
	case GKUNI_UPMOVE:
		m_snake_posdeque.push_front(Position(temp_headpos.m_posx, --temp_headpos.m_posy));
		break;
	case GKUNI_DOWNMOVE:
		m_snake_posdeque.push_front(Position(temp_headpos.m_posx, ++temp_headpos.m_posy));
		break;
	case GKUNI_LEFTMOVE:
		m_snake_posdeque.push_front(Position(--temp_headpos.m_posx, temp_headpos.m_posy));
		break;
	case GKUNI_RIGHTMOVE:
		m_snake_posdeque.push_front(Position(++temp_headpos.m_posx, temp_headpos.m_posy));
		break;
	default:
		break;
	}
}

//改变sanke运行方向并更新snake的head字符串
void Snake::Snake_changedirect(int mode)
{
	if (mode == GKUNI_UPMOVE&&m_snake_runmode == GKUNI_DOWNMOVE) return;
	if (mode == GKUNI_DOWNMOVE&&m_snake_runmode == GKUNI_UPMOVE) return;
	if (mode == GKUNI_LEFTMOVE&&m_snake_runmode == GKUNI_RIGHTMOVE) return;
	if (mode == GKUNI_RIGHTMOVE&&m_snake_runmode == GKUNI_LEFTMOVE) return;
	m_snake_runmode = mode;
	m_snake_phead = GSTR_HEAD[mode];
}

void Snake::Snake_expand() {
	m_snake_num++;
	m_snake_posdeque.push_back(m_snake_oldtail);
}

bool Snake::Snake_ishit() {
	Position head = m_snake_posdeque.front();
	if (head.m_posx <= 0 || head.m_posx >= GKINT_AREAWIDTH)
		return true;
	
	return false;
}

