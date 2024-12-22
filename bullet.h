#pragma once
#include"tank.h"
#include<graphics.h>
#include<windows.h>
#pragma comment(lib, "winmm.lib")

//#include <mmsystem.h>


//子弹结构体
struct bullet_s {

	int pos_x;//子弹在戏台上的横坐标(像素）
	int pos_y;//子弹在戏台上的纵坐标（像素）
	DIRECTION direction; //子弹方向
	int status; //子弹存在 //可扩展爆炸状态1-可发射0-不可
	int canfire;

};

int bullet_action(bullet_s* bullet, tank_s *enemy_tank,int key);

void tank_fire(tank_s* tank, bullet_s* bullet, int need_sound);

void clean(bullet_s* enemy_bullet, bullet_s* my_bullet);