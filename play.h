#pragma once
#include"tank.h"
#include"menu.h"
#include"map.h"
#include<conio.h>//�����������ͷ�ļ�
#include<thread>
#include"windows.h"
#include<time.h>

void tank_walk(tank_s* tank, DIRECTION direction, IMAGE* img);//�з�̹����ǰ��һ��

int play();
//����̹��ͼƬ��ʶ���λ

int do_tank_walk(tank_s* tank, DIRECTION direction, IMAGE* img,int step);//���ݼ�λ�ƶ�ͼƬ
//void tank_fire(tank_s* tank, bullet_s* bullet); //�з�̹�˿�����
void changed(tank_s* tank, DIRECTION direction, IMAGE* img);