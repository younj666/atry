#include"play.h"
#include"bullet.h"
#include"map.h"
#define ENEMY_NUM 10

//std::thread myThread(bullet_action);


int do_tank_walk(tank_s* tank, DIRECTION direction, IMAGE* img,int step ) {
	//ʵ��̹���ƶ��ĺ���SS
	int new_x = tank->x;
	int new_y = tank->y;

	int old_prop = map[tank->y][tank->x];
	//��ͼ��ԭ����ֵ��Ϊ�˺����ƶ���ı����������

	//if (step == 1) {
	    //ǰ��һ��
		//��ԭ����λ�����
		//map[tank->y][tank->x] = 0;
		//map[tank->y][tank->x + 1] = 0;
		//map[tank->y + 1][tank->x] = 0;
		//map[tank->y + 1][tank->x + 1] = 0;
		setfillcolor(BLACK);

		//�ú�ɫ���θ��ǵ�

		solidrectangle(tank->x * 25, tank->y * 25, tank->x * 25 + 50, tank->y * 25 + 50);

	if (step == 1) {

		//ǰ��һ��
		map[tank->y][tank->x] = 0;
		map[tank->y][tank->x + 1] = 0;
		map[tank->y + 1][tank->x] = 0;
		map[tank->y + 1][tank->x + 1] = 0;

		if (direction == UP) {
			new_y -= 1;

		}

		else if (direction == DOWN) {
			new_y += 1;

		}

		else if (direction == LEFT) {
			new_x -= 1;

		}

		else if (direction == RIGHT) {
			new_x += 1;

		}

		else {
			return 0;//��Ч�ķ���

		}
	}
	if (step) {

		//�µ�λ��
		map[new_y][new_x] = old_prop;
		map[new_y][new_x + 1] = old_prop;
		map[new_y + 1][new_x] = old_prop;
		map[new_y + 1][new_x + 1] = old_prop;
		tank->x = new_x;
		tank->y = new_y;
		tank->direction = direction;
		//�ı�̹�˵ķ���

	}

	//��̹�˵���ͼ��������
	putimage(tank->x * 25, tank->y * 25, img);
	//ǰ���������ص�
	return 1;

}

//ʵ���˻��ƶ��ĺ���
void tank_walk(tank_s* tank, DIRECTION direction, IMAGE* img) {
	switch (direction) {
	case LEFT://��//����������������������ǿյأ������ƶ�
		if (tank->direction == LEFT && (tank->x - 1) >= 0 && map[tank->y][tank->x - 1] == 0 && map[tank->y + 1][tank->x - 1] == 0) {
			
			//my_tank.direction = LEFT;
			/*************
			ʵ���ƶ�
			**************/

			do_tank_walk(tank, LEFT, img, 1);

		}

		else if (tank->direction != LEFT) {
			tank->direction = LEFT;
			do_tank_walk(tank, LEFT, img, 0);

		}

		break;
	case UP://��
		if (tank->direction == UP && (tank->y - 1) >= 0 && map[tank->y - 1][tank->x] == 0 && map[tank->y - 1][tank->x + 1] == 0) {
			
			//tank->direction = UP;
			/*************
			ʵ���ƶ�
			**************/

			do_tank_walk(tank, UP, img, 1);

		}

		else if (tank->direction != UP) {
			tank->direction = UP;
			do_tank_walk(tank, UP, img, 0);

		}

		break;

	case DOWN://��
		if (tank->direction == DOWN && (tank->y + 2) <= 25 && map[tank->y + 2][tank->x] == 0 && map[tank->y + 2][tank->x + 1] == 0) {
			
			//tank->direction = DOWN;
			/*************
			ʵ���ƶ�
			**************/

			do_tank_walk(tank, DOWN, img, 1);

		}

		else if (tank->direction != DOWN) {
			tank->direction = DOWN;
			do_tank_walk(tank, DOWN, img, 0);

		}

		break;

	case RIGHT://��

		if (tank->direction == RIGHT && (tank->x + 2) <= 25 && map[tank->y][tank->x + 2] == 0 && map[tank->y + 1][tank->x + 2] == 0) {
			
			//tank->direction = RIGHT;
			/*************
			ʵ���ƶ�
			**************/

			do_tank_walk(tank, RIGHT, img, 1);

		}

		else if (tank->direction != RIGHT) {
			tank->direction = RIGHT;
			do_tank_walk(tank, RIGHT, img, 0);

		}

		break;

	}
}
//�ı���������ĺ���
//ʵ���˻��ƶ��ĺ���
void changed(tank_s* tank, DIRECTION direction, IMAGE* img) {
	switch (direction) {
	case LEFT://��//����������������������ǿյأ������ƶ�
		

			//my_tank.direction = LEFT;
			/*************
			ʵ���ƶ�
			**************/

			//do_tank_walk(tank, LEFT, img, 0);
		

		if (tank->direction != LEFT) {
			tank->direction = LEFT;
			do_tank_walk(tank, LEFT, img, 0);

		}

		break;
	case UP://��
		//if (tank->direction == UP && (tank->y - 1) >= 0 && map[tank->y - 1][tank->x] == 0 && map[tank->y - 1][tank->x + 1] == 0) {

			//tank->direction = UP;
			/*************
			ʵ���ƶ�
			**************/

		//	do_tank_walk(tank, UP, img, 1);
		//}

		 if (tank->direction != UP) {
			tank->direction = UP;
			do_tank_walk(tank, UP, img, 0);

		}

		break;

	case DOWN://��
		//if (tank->direction == DOWN && (tank->y + 2) <= 25 && map[tank->y + 2][tank->x] == 0 && map[tank->y + 2][tank->x + 1] == 0) {

			//tank->direction = DOWN;
			/*************
			ʵ���ƶ�
			**************/

		//	do_tank_walk(tank, DOWN, img, 1);

		//}

		 if (tank->direction != DOWN) {
			tank->direction = DOWN;
			do_tank_walk(tank, DOWN, img, 0);

		}

		break;

	case RIGHT://��

		//if (tank->direction == RIGHT && (tank->x + 2) <= 25 && map[tank->y][tank->x + 2] == 0 && map[tank->y + 1][tank->x + 2] == 0) {

			//tank->direction = RIGHT;
			/*************
			ʵ���ƶ�
			**************/

		///	do_tank_walk(tank, RIGHT, img, 1);
		//}

		if (tank->direction != RIGHT) {
			tank->direction = RIGHT;
			do_tank_walk(tank, RIGHT, img, 0);

		}

		break;

	}
}

/***********
* �㷨������ƣ����������ҷ�̹�ˣ�˫��������ӥ
***********/
//���Ƶз�̹���ƶ��ĺ����������ҷ�̹���ƶ�
/**********
* ����Ŀ��λ�ã������з�̹�˵ķ���
***********/

DIRECTION enemy_direction(tank_s* tank, int x, int y) {
	int r = rand() % 100;   //û�������ļ�����
	if (tank->x > x) {
		//Ŀ�������
		if (tank->y > y) {

			//Ŀ�������Ϸ�
			if (r <= 50) return UP;
			else return LEFT;

		}

		else {

			//Ŀ�������·�
			if (r <= 50) return DOWN;
			else return LEFT;

		}

	}
	else {

		//Ŀ�����ұ�
		if (tank->y > y) {
			//Ŀ�������Ϸ�
			if (r <= 50) return UP;
			else return RIGHT;

		}

		else {

			//Ŀ�������·�
			if (r <= 50) return DOWN;
			else return RIGHT;

		}

	}


}

void tank_fire(tank_s* tank, bullet_s* bullet) {
	if (bullet->status == 0) {
		//�з�̹�˲���Ҫ��Ƶ
		
		//PlaySound(TEXT("./res/music/blast.wav"), NULL, SND_FILENAME | SND_ASYNC);
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

		bullet->direction = tank->direction;
		bullet->status = 1;

	}


}
/*************************
*ʵ����Ϸ����
**************************/


int play() {
	tank_s my_tank;
	
	//�ҷ�̹��
	bullet_s my_bullet;
	//�ҷ�̹�˷ŵ��ӵ�
	
	tank_s enemy_tank[ENEMY_NUM];
	
	//�з�̹��
	bullet_s enemy_bullet[ENEMY_NUM];
	
	//�з�̹�˷�����ӵ�
	//���ٵз�̹��
	tank_s fast_tank[ENEMY_NUM];
	
	bullet_s fast_bullet[ENEMY_NUM];
	IMAGE my_tank_img[4];
	IMAGE enemy_tank_img[4];
	IMAGE fast_tank_img[4];
	int key;
	int times = 0; 
	//��¼��ǰ��������ߴ�����ÿ��10ms����500msʱ�õз�̹�˶�һ��
	
	int enemy_total = 0;

	//��ʼ�����������
	srand(time(NULL)); //ʱ���

	//HHOOK keyboardHook;    // ���̹��ӵľ��

	//�����ҷ�̹�˵�ͼƬ
	loadimage(&my_tank_img[UP], _T("./res/img/tank_up.jpg"), 50, 50);
	loadimage(&my_tank_img[DOWN], _T("./res/img/tank_down.jpg"), 50, 50);
	loadimage(&my_tank_img[LEFT], _T("./res/img/tank_left.jpg"), 50, 50);
	loadimage(&my_tank_img[RIGHT], _T("./res/img/tank_right.jpg"), 50, 50);

	//���صз�̹�˵�ͼƬ
	loadimage(&enemy_tank_img[UP], _T("./res/img/enemy_tank_up.jpg"), 50, 50);
	loadimage(&enemy_tank_img[DOWN], _T("./res/img/enemy_tank_down.jpg"), 50, 50);
	loadimage(&enemy_tank_img[LEFT], _T("./res/img/enemy_tank_left.jpg"), 50, 50);
	loadimage(&enemy_tank_img[RIGHT], _T("./res/img/enemy_tank_right.jpg"), 50, 50);

	//���ؿ���̹��
	loadimage(&fast_tank_img[UP], _T("./res/img/p2tankU.gif"), 50, 50);
	loadimage(&fast_tank_img[DOWN], _T("./res/img/p2tankD.gif"), 50, 50);
	loadimage(&fast_tank_img[LEFT], _T("./res/img/p2tankL.gif"), 50, 50);
	loadimage(&fast_tank_img[RIGHT], _T("./res/img/p2tankR.gif"), 50, 50);

	//loadimagefastst[0], _T("./res/img/blast1.gif"), 50, 50);
	//�ӵ���ʼ��0�����ڣ�1����
	my_bullet.status = 0;
	//�ӵ��в����ڣ�״̬Ϊ1ʱ���ɷ�����һ����״̬Ϊ0ʱ���Է�����һ��

	//�ҷ�̹�˳���λ��
	my_tank.x = 8;
	my_tank.y = 24;
	my_tank.live = 1; //����ʱ��״̬
	my_tank.direction = UP;

	map[my_tank.y][my_tank.x] = 200;
	map[my_tank.y][my_tank.x + 1] = 200;
	map[my_tank.y + 1][my_tank.x] = 200;
	map[my_tank.y + 1][my_tank.x + 1] = 200;


	putimage(my_tank.x * 25, my_tank.y * 25, &my_tank_img[UP]);
	set_prop_map(my_tank.x, my_tank.y, 200/*Ҫ�趨��ֵ*/);
	//���õз�̹�˳�����λ��
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (i % 3 == 0) {

			enemy_tank[i].x = 0;
			enemy_tank[i].y = 0;


		}

		else if(i % 3 == 1) {

			enemy_tank[i].x = 20; 
			enemy_tank[i].y = 15;

		}


		else if (i % 3 == 2) {

			enemy_tank[i].x = 24;
			enemy_tank[i].y = 0;

		}

		enemy_tank[i].direction = DOWN;
		//enemy_tank[i].y = 0;
		enemy_tank[i].live = 1;
		//set_prop_map(enemy_tank[i].x, enemy_tank[i].y, 100 + i/*Ҫ�趨��ֵ*/);
		// //set_prop_map(enemy_tank[i].x, enemy_tank[i].y, 100 + i/*Ҫ�趨��ֵ*/);
		// //�ѵз�̹�˵�ֵ���100 + i
		enemy_bullet[i].status = 0;
		//�ӵ������ڣ����Կ���һ��

	}

	//����������
	mciSendString(_T("open ./res/music/background.flac alias al wait"), NULL, 0, NULL);
	mciSendString(_T("play al"), 0, 0, 0);

	//ǰ����̹�˵ǳ�
	do_tank_walk(&enemy_tank[0], DOWN, &enemy_tank_img[DOWN], 0);
	set_prop_map(enemy_tank[0].x, enemy_tank[0].y, 100 /*Ҫ�趨��ֵ*/);
	//�ѵз�̹�˵�ֵ���100 + i
	do_tank_walk(&enemy_tank[1], DOWN, &enemy_tank_img[DOWN], 0);
	set_prop_map(enemy_tank[1].x, enemy_tank[1].y, 101/*Ҫ�趨��ֵ*/);
	//�ѵз�̹�˵�ֵ���100 + i
	do_tank_walk(&enemy_tank[2], DOWN, &enemy_tank_img[DOWN], 0);
	set_prop_map(enemy_tank[2].x, enemy_tank[2].y, 102/*Ҫ�趨��ֵ*/);
	//�ѵз�̹�˵�ֵ���100 + i

	enemy_total = 3;

	//����̹����Ϊ666
	fast_tank[0].direction = LEFT;
	fast_tank[0].live = 1;
	fast_bullet[0].status = 0;
	fast_tank[0].x = 12;
	fast_tank[0].y = 13;
	do_tank_walk(&fast_tank[0], LEFT, &fast_tank_img[LEFT], 0);

	putimage(fast_tank[0].x * 25, fast_tank[0].y * 25, &fast_tank_img[LEFT]);
	set_prop_map(fast_tank[0].x, fast_tank[0].y, 666/*Ҫ�趨��ֵ*/);

	
	while (1) {
		//12.7�����ӵ���̹���ƶ����ܲ���
		//ԭ��ת��ʱ���Լ���һ������Ҫ�Ż�
		if (_kbhit()) {//�м����·���1
			key = _getch();

			switch (key) {
			case 'a'://��
				//����������������������ǿյأ������ƶ�
				//tank_walk(&my_tank,LEFT,&my_tank_img[LEFT]);
				if (my_tank.direction == LEFT && (my_tank.x - 1) >= 0 && map[my_tank.y][my_tank.x - 1] == 0 && map[my_tank.y + 1][my_tank.x - 1] == 0) {

					//my_tank.direction = LEFT;
					/*************
					ʵ���ƶ�
					**************/

					do_tank_walk(&my_tank, LEFT, &my_tank_img[my_tank.direction], 1);

				}

				else if (my_tank.direction != LEFT) {

					my_tank.direction = LEFT;
					
					// PlaySound(TEXT("./res/music/moving.mp3"), NULL, SND_FILENAME | SND_ASYNC);
					
					do_tank_walk(&my_tank, LEFT, &my_tank_img[my_tank.direction], 0);

				}


				break;

			case'w'://��
				//tank_walk(&my_tank,UP,&my_tank_img[UP]);
				if (my_tank.direction == UP && (my_tank.y - 1) >= 0 && map[my_tank.y - 1][my_tank.x] == 0 && map[my_tank.y - 1][my_tank.x + 1] == 0) {

					//my_tank.direction = UP;
					/*************
					ʵ���ƶ�
					**************/

					do_tank_walk(&my_tank, UP, &my_tank_img[my_tank.direction], 1);

				}

				else if (my_tank.direction != UP) {

					my_tank.direction = UP;
					do_tank_walk(&my_tank, UP, &my_tank_img[my_tank.direction], 0);

				}

				break;

			case's'://��

				//tank_walk(&my_tank,DOWN,&my_tank_img[DOWN]);
				if (my_tank.direction == DOWN && (my_tank.y + 2) <= 25 && map[my_tank.y + 2][my_tank.x] == 0 && map[my_tank.y + 2][my_tank.x + 1] == 0) {

					//my_tank.direction = DOWN;
					/*************
					ʵ���ƶ�
					**************/

					do_tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.direction], 1);

				}

				else if (my_tank.direction != DOWN) {

					my_tank.direction = DOWN;
					do_tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.direction], 0);

				}

				break;

			case'd'://��
				//tank_walk(&my_tank,RIGHT,&my_tank_img[RIGHT]);
				if (my_tank.direction == RIGHT && (my_tank.x + 2) <= 25 && map[my_tank.y][my_tank.x + 2] == 0 && map[my_tank.y + 1][my_tank.x + 2] == 0) {

					//my_tank.direction = RIGHT;
					
					/*************
					ʵ���ƶ�
					**************/

					do_tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.direction], 1);

				}

				else if (my_tank.direction != RIGHT) {

					my_tank.direction = RIGHT;
					do_tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.direction], 0);

				}

				break;

			case'j'://����
			{
				if (my_bullet.status == 1)
					//�Ѿ����ӵ����ڣ������Է�����һ��
					break;
				//tank_fire(&my_tank, &my_bullet);
				
				//��������
				my_bullet.direction = my_tank.direction;
								
				my_bullet.status = 1;
				//Ϊ�˲��Ծ�ֱ�Ӳ��ı�״̬��
				tank_fire(&my_tank, &my_bullet, 1);	

				//��ʼ���ӵ����꣬������Ƶ			
				//bullet_action(&my_bullet);
				break;
				//bullet_action(&my_bullet);//ʵ���ӵ���������ĺ���


			}

			case'p':
				//��ͣ
				system("pause");
				break;

			default:

				//�����������账��
				break;

			}

			//switch������

		}

		//if������
		if (times % 100 == 0) {

			//2ms��ת̹�˷���һ��
			for (int i = 0; i < enemy_total; i++) {
				if (enemy_tank[i].live == 0) continue;
				if (i % 2 == 0) {

					//ż���������ҷ��ϳ������ҷ��ϳ�ǰ����
					DIRECTION d = enemy_direction(&enemy_tank[i], 12, 24);
					tank_walk(&enemy_tank[i], d, &enemy_tank_img[d]);

				}

				else {

					//�����ҷ�̹�ˣ����ҷ�̹��ǰ����
					DIRECTION d = enemy_direction(&enemy_tank[i], my_tank.x, my_tank.y);
					tank_walk(&enemy_tank[i], d, &enemy_tank_img[d]);

				}

				tank_fire(&enemy_tank[i], &enemy_bullet[i]);

			}

		}
		else if (times % 50 == 0) {

			//0.5ms�ƶ��ط��������̹��
			for (int i = 0; i < enemy_total; i++) {

				if (enemy_tank[i].live) {
					tank_walk(&enemy_tank[i], enemy_tank[i].direction, &enemy_tank_img[enemy_tank[i].direction]);

				}

			}

		}
		//�Կ���̹�˵Ĳٿ�
		if (times % 50 == 0) {
		
			//
				if (fast_tank[0].live == 0) return 0;
				
		//	//ż���������ҷ��ϳ������ҷ��ϳ�ǰ����
		   //DIRECTION d = enemy_direction(&enemy_tank[i], 12, 24);
				//	tank_walk(&enemy_tank[i], d, &enemy_tank_img[d]);
		
				//}
		
				//else {
				//�����ҷ�̹�ˣ����ҷ�̹��ǰ����

				DIRECTION d = enemy_direction(&fast_tank[0], my_tank.x, my_tank.y);
				//tank_walk(&fast_tank[0], d, &fast_tank_img[d]);
				changed(&fast_tank[0], d, &fast_tank_img[d]);
		
		
				tank_fire(&fast_tank[0], &fast_bullet[0]);
			
		
		}

		////else if (times % 20 == 0) {
		//	if (fast_tank[0].live) {
		//		tank_walk(&fast_tank[0], fast_tank[0].direction, &fast_tank_img[fast_tank[0].direction]);
		//	}
		//}
		//
		//���Ż��������ӵ������Լ������ǵ��ӵ�Ҳ�����Լ�
		//�ҷ��ӵ��˶�Ч��
		//ǿ�޵У��Ѿ�ʵ�ֹ���

		if (my_bullet.status == 1) {
			//bullet_action(&my_bullet, enemy_tank);
			if (bullet_action(&my_bullet, enemy_tank, 1)) return 1; 
			//����
			
			//clean(enemy_bullet, &my_bullet);

		}

		/*****************
		* �з��ӵ��˶�Ч��
		*****************/

		for (int i = 0; i < ENEMY_NUM; i++) {

			if (enemy_bullet[i].status == 1) {
				//1�ǻ��ڿ��з�
				//bullet_action(&enemy_bullet[i], enemy_tank);

				if (bullet_action(&enemy_bullet[i], enemy_tank, 0)) return 1;
				//for (int j = 1; j < ENEMY_NUM; j++) {
				//	if (enemy_bullet[i].pos_x == enemy_bullet[j].pos_x) {
				//		enemy_bullet[i].status = 0;
				//		enemy_bullet[j].status = 0;
				//	}
				//}
				clean(&enemy_bullet[i], &my_bullet);

			}

		}
		if (times > 0 && times % 500 == 0 && enemy_total < ENEMY_NUM) {

			//�жϳ����Ķ�ά�����Ƿ��Ѿ���̹�˴��ڣ����Ż���
			set_prop_map(enemy_tank[enemy_total].x, enemy_tank[enemy_total].y, 100 + enemy_total/*Ҫ�趨��ֵ*/);
			
			//�ѵз�̹�˵�ֵ���100 + i
			set_prop_map(enemy_tank[enemy_total].x, enemy_tank[enemy_total].y, 100 + enemy_total/*Ҫ�趨��ֵ*/);
			enemy_total++;
		
		}
		if (fast_bullet[0].status == 1) {

		//1�ǻ��ڿ��зɣ��ͼ���ѭ�����ӵ���
		//	//bullet_action(&enemy_bullet[i], enemy_tank);
		//	//bullet_action(&enemy_bullet[i], enemy_tank);
			if (bullet_action(&fast_bullet[0], enemy_tank, 3)) return 1;

		}

		//
		//
		/**************************
		* �жϵз�̹���Ƿ�ȫ��������
		***************************/
		int isWin = 1;
		//�ж���Ϸ����

		for (int i = 0; i < ENEMY_NUM; i++) {
			if (enemy_tank[i].live == 1) {
				isWin = 0;

			}

		}
		if (isWin) {
			//����ʤ�����֣��˳���Ϸ
			PlaySound(TEXT("./res/music/Get Daze.wav"), NULL, SND_FILENAME | SND_ASYNC);
			return 0;

		}


		//����ѭ�����ٶ�
		Sleep(1);
		times++;
		//������10ms��

	}
	//while������

}
//��������
