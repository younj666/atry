#pragma once
#include<graphics.h>

//�����ͼ����
extern int map[26][26];//extren���߱���������������������ﶨ��
extern int map2[26][26];

extern int map3[26][26];
extern int map4[26][26];
//void init_map();//��ʼ����ͼ

void init_map_2(int* map, int rows, int cols);//Ϊ����Ӧ��ͬ�ĵ�ͼ,�Ż�Ϊ����ָ��

void set_prop_map(int x, int y, int val/*Ҫ�趨��ֵ*/);

//Ϊ�����¿�ʼ��Ϸ�����Ѿ��ı��˵ĵ�ͼ����
void refresh();
