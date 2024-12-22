#pragma once
#include<graphics.h>

//定义地图数组
extern int map[26][26];//extren告诉编译器，这个变量不在这里定义
extern int map2[26][26];

extern int map3[26][26];
extern int map4[26][26];
//void init_map();//初始化地图

void init_map_2(int* map, int rows, int cols);//为了适应不同的地图,优化为传入指针

void set_prop_map(int x, int y, int val/*要设定的值*/);

//为了重新开始游戏，把已经改变了的地图重置
void refresh();
