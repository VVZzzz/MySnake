#pragma once
#ifndef SNAKE_FOOD_H_
#define SNAKE_FOOD_H_

#include "snakemacros.h"
class Food {
public:
	Food() = default;
	~Food() = default;
	void Food_Gnerate();
	Position get_foodpos();
private:
	Position foodpos;
};
#endif
