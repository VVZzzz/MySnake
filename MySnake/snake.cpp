#include "snakemacros.h"
#include "snake.h"
#include "map.h"

void Snake::Snake_init() {
	srand(unsigned int(time(NULL)));
	int direction = rand() % 4;
	Position init_pos(GKINT_AREAWIDTH / 2, GKINT_AREAHEIGHT / 2);
	m_snake_runmode = direction;
	m_snake_phead = &GSTR_HEAD[direction];
	m_snake_speed = 1;
	m_snake_num = 0;
	m_snake_posdeque.resize(1);
	m_snake_posdeque[0] = init_pos;
	m_snake_oldtail = init_pos;
}

void Snake::Snake_move()
{
	Position temp_headpos = m_snake_posdeque.front();
	m_snake_oldtail = m_snake_posdeque.back();  //更新oldtailpos
	m_snake_posdeque.pop_back();                //将尾部位置删去
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
	m_snake_phead = &GSTR_HEAD[mode];
}

void Snake::Snake_expand() {
	m_snake_num++;
	m_snake_posdeque.push_back(m_snake_oldtail);
}

bool Snake::Snake_ishit() {
	Position head = m_snake_posdeque.front();
	if (head.m_posx <= 0 || head.m_posx >= GKINT_AREAWIDTH)
		return true;
	if (head.m_posy <= 0 || head.m_posy >= GKINT_AREAHEIGHT) 
		return true;
	//和蛇身体相撞
	for (size_t i = 1; i < m_snake_posdeque.size();i++) {
		if (head == m_snake_posdeque[i])
			return true;
	}
	return false;
}

bool Snake::Snake_meetfood(Position foodpos) {
	return m_snake_posdeque.front() == foodpos;
}

