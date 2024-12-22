#pragma once
#include"tank.h"
#include"menu.h"
#include"map.h"
#include<conio.h>//检测键盘输入的头文件
#include<thread>
#include"windows.h"
#include<time.h>

void tank_walk(tank_s* tank, DIRECTION direction, IMAGE* img);//敌方坦克往前走一步

int play();
//加载坦克图片，识别键位

int do_tank_walk(tank_s* tank, DIRECTION direction, IMAGE* img,int step);//根据键位移动图片
//void tank_fire(tank_s* tank, bullet_s* bullet); //敌方坦克开火方向
void changed(tank_s* tank, DIRECTION direction, IMAGE* img);