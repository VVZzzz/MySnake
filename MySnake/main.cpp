#include <iostream>
#include <string>
#include <wchar.h>
#include "map.h"

int main()
{
	Map map;
	map.MapInit();
	map.MapInforInit();
	map.MapInforErase();
	system("pause");
	return 0;
}