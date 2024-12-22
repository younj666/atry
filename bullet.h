#pragma once
#include"tank.h"
#include<graphics.h>
#include<windows.h>
#pragma comment(lib, "winmm.lib")

//#include <mmsystem.h>


//�ӵ��ṹ��
struct bullet_s {

	int pos_x;//�ӵ���Ϸ̨�ϵĺ�����(���أ�
	int pos_y;//�ӵ���Ϸ̨�ϵ������꣨���أ�
	DIRECTION direction; //�ӵ�����
	int status; //�ӵ����� //����չ��ը״̬1-�ɷ���0-����
	int canfire;

};

int bullet_action(bullet_s* bullet, tank_s *enemy_tank,int key);

void tank_fire(tank_s* tank, bullet_s* bullet, int need_sound);

void clean(bullet_s* enemy_bullet, bullet_s* my_bullet);