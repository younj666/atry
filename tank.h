//坦克的xy代表所在的行和列，子弹的xy代表所在的像素点
#pragma once
/*#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3*/

enum DIRECTION {

	UP, DOWN, LEFT, RIGHT

};

struct tank_s {

	int x;//代表坦克在地图数组中所在的列，取左上角来代表
	int y;//代表坦克在地图数组中所在的行
	DIRECTION direction; //坦克的方向，上、下、左、右
	int live;      //是否生存， 1-活着  0-挂了

};