#include"bullet.h"
#include"map.h"


/**********
ʵ���ӵ����к���ײ��⣬��������Ϸ���������1-��Ϸʧ�ܣ�0-������Ϸ
********/

int bullet_action(bullet_s* bullet,tank_s * enemy_tank,int key) {
	IMAGE blast[7];
	IMAGE home_destroy;
	loadimage(&home_destroy, _T("./res/img/home_destory.gif"), 50, 50);
	//loadimage(&blast[0], _T("./res/img/blast1.gif"), 50, 50);
	//loadimage(&blast[1], _T("./res/img/blast2.gif"), 50, 50);
	//loadimage(&blast[2], _T("./res/img/blast3.gif"), 50, 50);
	//loadimage(&blast[3], _T("./res/img/blast4.gif"), 50, 50);
	loadimage(&blast[4], _T("./res/img/blast5.gif"), 50, 50);
	//loadimage(&blast[5], _T("./res/img/blast6.gif"), 50, 50);
	loadimage(&blast[6], _T("./res/img/blast7.gif"), 50, 50);
	//loadimage(&blast[7], _T("./res/img/blast8.gif"), 50, 50);
	int x, y, x1, y1;
	//�ӵ�Ŀǰ���ڶ�ά���������
	x = bullet->pos_x / 25;  //���س���25��������
	y = bullet->pos_y / 25;

	//1.������һ�λ��Ƶ��ӵ�
	setfillcolor(BLACK);
	solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);

	//2.���ݷ�������ӵ���Ϸ̨�ϵ�����
	if (bullet->direction == UP) {
		bullet->pos_y -= 2;
		x1 = x + 1;
		y1 = y;

	}
	else if (bullet->direction == DOWN) {
		bullet->pos_y += 2;
		x1 = x + 1;  //һ���������������̹����ǰ��
		y1 = y;

	}
	else if (bullet->direction == LEFT) {
		bullet->pos_x -= 2;
		x1 = x;
		y1 = y + 1;

	}
	else if (bullet->direction == RIGHT) {
		bullet->pos_x += 2;
		x1 = x;
		y1 = y + 1;

	}
	else {
		return 0;//Ŀǰ���޴�

	}
	//һЩ�����ײ�ͱ߽�Ĵ��룬�Ȳ�Ҫ
	if (bullet->pos_x < 0 || bullet->pos_x > 650 || bullet->pos_y < 0 || bullet->pos_y > 650) {
		bullet->status = 0;
		//�ֿ��Է�����
		return 0;

	}
	//��ײ���
	if (map[y][x] == 4 || map[y1][x1] == 4) {
		//�Ƿ������ӥ����ӥ������4
		putimage(25 * 12, 25 * 24, &home_destroy);
		Sleep(1000);
		return 1;

	}
	//�����ҷ�̹��
	
	if (map[y][x] == 200 || map[y1][x1] == 200) {
		if (key == 1) {
			bullet->status = 0;
			return 0;

		}
		//�����ҷ�̹��
		PlaySound(TEXT("./res/music/blast.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return 1;

	}

	//�з�̹�˱�����
	if ((map[y][x] >= 100 && map[y][x] <= 109) || ((map[y1][x1] >= 100 && map[y1][x1] <= 109))) {
		if (key == 0 || key == 3) {
			bullet->status = 0;
			return 0;

		}
		tank_s* tank = NULL;
		bullet->status = 0; //���ӵ���ʧ
		if (map[y][x] >= 100 && map[y][x] <= 109) {

			tank = enemy_tank + (map[y][x] - 100);//�з�̹�˵ı��

		}
		else {

			tank = enemy_tank + (map[y1][x1] - 100);

		}
		tank->live = 0;//�ѵз�̹��
		set_prop_map(tank->x, tank->y, 0);
		//�ѵз�̹��ԭ�����ڵĵط���Ϊ0
		setfillcolor(BLACK);
		solidrectangle(tank->x * 25, tank->y * 25, tank->x * 25 + 50, tank->y * 25 + 50);
		//putimage(25 * tank->x, 25 * tank->y, &blast[0]);
		//
		//putimage(25 * tank->x, 25 * tank->y, &blast[1]);
		//putimage(25 * tank->x, 25 * tank->y, &blast[2]);
		//putimage(25 * tank->x, 25 * tank->y, &blast[3]);
		putimage(25 * tank->x, 25 * tank->y, &blast[4]);
		Sleep(50);
		solidrectangle(tank->x * 25, tank->y * 25, tank->x * 25 + 50, tank->y * 25 + 50);
		//putimage(25 * tank->x, 25 * tank->y, &blast[5]);
		putimage(25 * tank->x, 25 * tank->y, &blast[6]);
		Sleep(50);
		solidrectangle(tank->x * 25, tank->y * 25, tank->x * 25 + 50, tank->y * 25 + 50);
		PlaySound(TEXT("./res/music/blast.wav"), NULL, SND_FILENAME | SND_ASYNC);
		PlaySound(TEXT("./res/music/Get Daze.wav"), NULL, SND_FILENAME | SND_ASYNC);
		//putimage(25 * tank->x, 25 * tank->y, &blast[7]);
		return 0;

	}
	//
	//�ӵ����п�������ǽ
	if (map[y][x] == 1 && map[y1][x1] == 1) {
		map[y][x] = 0;
		map[y1][x1] = 0;
		bullet->status = 0;
		//�ӵ��ָ����ɷ����״̬
		setfillcolor(BLACK);
		solidrectangle(x * 25, y * 25 , x * 25 + 25, y * 25 + 25);
		//����һС��ǽ��ס
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);//������bug
		return 0;

	}
	else if (map[y][x] == 2) {
		//��ʯͷ����
		bullet->status = 0;
		return 0;
	}
	else if (map[y][x] == 6) {
		//�򵽱�־����
		bullet->status = 0;
		return 0;

	}
	if (map[y1][x1] == 1) {
		//�򵽿�������ǽ
		map[y1][x1] = 0;
		bullet->status = 0;
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25 , x1 * 25 + 25, y1 * 25 + 25);
		return 0;

	}
	else if (map[y][x] == 1) {
		//�򵽿�������ǽ
		map[y][x] = 0;
		bullet->status = 0;
		setfillcolor(BLACK);
		solidrectangle(x * 25, y * 25, x * 25 + 25, y * 25 + 25);
		return 0;

	}
	else if (map[y1][x1] == 2) {
		//��ʯͷ
		bullet->status = 0;
		return 0;

	}
	else if (map[y1][x1] == 6) {
		//��У��
		bullet->status = 0;
		return 0;

	}
	////����̹�˱�����
	
	if (map[y][x] == 666 || map[y1][x1] == 666) {
	//	if (key == 3) {
	//		bullet->status = 0;
	//		return 0;
	//	}
	//	//tank_s* tank = NULL;
		bullet->status = 0; //���ӵ���ʧ
	//	enemy_tank->live = 0;//�ѵз�̹��
	//	set_prop_map(enemy_tank->x, enemy_tank->y, 0);
	//	//�ѵз�̹��ԭ�����ڵĵط���Ϊ0
	//	setfillcolor(BLACK);
	//	solidrectangle(enemy_tank->x * 25, enemy_tank->y * 25, enemy_tank->x * 25 + 50, enemy_tank->y * 25 + 50);
	//	//putimage(25 * tank->x, 25 * tank->y, &blast[0]);
	//	//
	//	//putimage(25 * tank->x, 25 * tank->y, &blast[1]);
	//	//putimage(25 * tank->x, 25 * tank->y, &blast[2]);
	//	//putimage(25 * tank->x, 25 * tank->y, &blast[3]);
	//	putimage(25 *enemy_tank->x, 25 * enemy_tank->y, &blast[4]);
	//	Sleep(50);
	//	solidrectangle(enemy_tank->x * 25, enemy_tank->y * 25, enemy_tank->x * 25 + 50, enemy_tank->y * 25 + 50);
	//	//putimage(25 * enemy_tank->x, 25 * enemy_tank->y, &blast[5]);
	//	putimage(25 * enemy_tank->x, 25 * enemy_tank->y, &blast[6]);
	//	Sleep(50);
	//	solidrectangle(enemy_tank->x * 25, enemy_tank->y * 25, enemy_tank->x * 25 + 50, enemy_tank->y * 25 + 50);
	//	PlaySound(TEXT("./res/music/blast.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//	//putimage(25 * tank->x, 25 * tank->y, &blast[7]);
		return 0;

	}

	
	
	//3.���»����ӵ�
	if (bullet->status == 1) {

		setfillcolor(WHITE);
		solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);
		return 0;

	}

}

void tank_fire(tank_s* tank, bullet_s* bullet, int need_sound) {
	if (bullet->status == 1) {

		if (need_sound) PlaySound(TEXT("./res/music/fire2.wav"), NULL, SND_FILENAME | SND_ASYNC);

		if (tank->direction == UP) {
			bullet->pos_x = tank->x * 25 + 23;
			bullet->pos_y = tank->y * 25 - 3;

		}
		else if (tank->direction == LEFT) {
			bullet->pos_x = tank->x * 25 - 3;
			bullet->pos_y = tank->y * 25 + 23;

		}
		else if (tank->direction == DOWN) {
			bullet->pos_x = tank->x * 25 + 23;
			bullet->pos_y = tank->y * 25 + 53;

		}
		else if (tank->direction == RIGHT) {
			bullet->pos_x = tank->x * 25 + 53;
			bullet->pos_y = tank->y * 25 + 23;

		}

	}

}

void clean(bullet_s* enemy_bullet, bullet_s* my_bullet) {//�ӵ�������Ŀǰδʵ�ֹ���
	if (enemy_bullet->pos_x == my_bullet->pos_x && enemy_bullet->pos_y == my_bullet->pos_y ) {

		enemy_bullet->status = 0;
		my_bullet->status = 0;
		setfillcolor(BLACK);
		solidrectangle(my_bullet->pos_x, my_bullet->pos_y, my_bullet->pos_x + 3, my_bullet->pos_y + 3);
		solidrectangle(enemy_bullet->pos_x, enemy_bullet->pos_y, enemy_bullet->pos_x + 3, enemy_bullet->pos_y + 3);

	}

}