//̹�˵�xy�������ڵ��к��У��ӵ���xy�������ڵ����ص�
#pragma once
/*#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3*/

enum DIRECTION {

	UP, DOWN, LEFT, RIGHT

};

struct tank_s {

	int x;//����̹���ڵ�ͼ���������ڵ��У�ȡ���Ͻ�������
	int y;//����̹���ڵ�ͼ���������ڵ���
	DIRECTION direction; //̹�˵ķ����ϡ��¡�����
	int live;      //�Ƿ����棬 1-����  0-����

};