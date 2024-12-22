#include"play.h"
#include"bullet.h"
#include"map.h"
#define ENEMY_NUM 10

//std::thread myThread(bullet_action);


int do_tank_walk(tank_s* tank, DIRECTION direction, IMAGE* img,int step ) {
	//实现坦克移动的函数SS
	int new_x = tank->x;
	int new_y = tank->y;

	int old_prop = map[tank->y][tank->x];
	//地图上原本的值，为了后续移动后改变数组的数据

	//if (step == 1) {
	    //前进一步
		//把原来的位置清楚
		//map[tank->y][tank->x] = 0;
		//map[tank->y][tank->x + 1] = 0;
		//map[tank->y + 1][tank->x] = 0;
		//map[tank->y + 1][tank->x + 1] = 0;
		setfillcolor(BLACK);

		//用黑色矩形覆盖掉

		solidrectangle(tank->x * 25, tank->y * 25, tank->x * 25 + 50, tank->y * 25 + 50);

	if (step == 1) {

		//前进一步
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
			return 0;//无效的方向

		}
	}
	if (step) {

		//新的位置
		map[new_y][new_x] = old_prop;
		map[new_y][new_x + 1] = old_prop;
		map[new_y + 1][new_x] = old_prop;
		map[new_y + 1][new_x + 1] = old_prop;
		tank->x = new_x;
		tank->y = new_y;
		tank->direction = direction;
		//改变坦克的方向

	}

	//把坦克的贴图放在这里
	putimage(tank->x * 25, tank->y * 25, img);
	//前两项是像素点
	return 1;

}

//实现人机移动的函数
void tank_walk(tank_s* tank, DIRECTION direction, IMAGE* img) {
	switch (direction) {
	case LEFT://左//满足这三个条件代表左边是空地，可以移动
		if (tank->direction == LEFT && (tank->x - 1) >= 0 && map[tank->y][tank->x - 1] == 0 && map[tank->y + 1][tank->x - 1] == 0) {
			
			//my_tank.direction = LEFT;
			/*************
			实现移动
			**************/

			do_tank_walk(tank, LEFT, img, 1);

		}

		else if (tank->direction != LEFT) {
			tank->direction = LEFT;
			do_tank_walk(tank, LEFT, img, 0);

		}

		break;
	case UP://上
		if (tank->direction == UP && (tank->y - 1) >= 0 && map[tank->y - 1][tank->x] == 0 && map[tank->y - 1][tank->x + 1] == 0) {
			
			//tank->direction = UP;
			/*************
			实现移动
			**************/

			do_tank_walk(tank, UP, img, 1);

		}

		else if (tank->direction != UP) {
			tank->direction = UP;
			do_tank_walk(tank, UP, img, 0);

		}

		break;

	case DOWN://下
		if (tank->direction == DOWN && (tank->y + 2) <= 25 && map[tank->y + 2][tank->x] == 0 && map[tank->y + 2][tank->x + 1] == 0) {
			
			//tank->direction = DOWN;
			/*************
			实现移动
			**************/

			do_tank_walk(tank, DOWN, img, 1);

		}

		else if (tank->direction != DOWN) {
			tank->direction = DOWN;
			do_tank_walk(tank, DOWN, img, 0);

		}

		break;

	case RIGHT://右

		if (tank->direction == RIGHT && (tank->x + 2) <= 25 && map[tank->y][tank->x + 2] == 0 && map[tank->y + 1][tank->x + 2] == 0) {
			
			//tank->direction = RIGHT;
			/*************
			实现移动
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
//改变炮塔方向的函数
//实现人机移动的函数
void changed(tank_s* tank, DIRECTION direction, IMAGE* img) {
	switch (direction) {
	case LEFT://左//满足这三个条件代表左边是空地，可以移动
		

			//my_tank.direction = LEFT;
			/*************
			实现移动
			**************/

			//do_tank_walk(tank, LEFT, img, 0);
		

		if (tank->direction != LEFT) {
			tank->direction = LEFT;
			do_tank_walk(tank, LEFT, img, 0);

		}

		break;
	case UP://上
		//if (tank->direction == UP && (tank->y - 1) >= 0 && map[tank->y - 1][tank->x] == 0 && map[tank->y - 1][tank->x + 1] == 0) {

			//tank->direction = UP;
			/*************
			实现移动
			**************/

		//	do_tank_walk(tank, UP, img, 1);
		//}

		 if (tank->direction != UP) {
			tank->direction = UP;
			do_tank_walk(tank, UP, img, 0);

		}

		break;

	case DOWN://下
		//if (tank->direction == DOWN && (tank->y + 2) <= 25 && map[tank->y + 2][tank->x] == 0 && map[tank->y + 2][tank->x + 1] == 0) {

			//tank->direction = DOWN;
			/*************
			实现移动
			**************/

		//	do_tank_walk(tank, DOWN, img, 1);

		//}

		 if (tank->direction != DOWN) {
			tank->direction = DOWN;
			do_tank_walk(tank, DOWN, img, 0);

		}

		break;

	case RIGHT://右

		//if (tank->direction == RIGHT && (tank->x + 2) <= 25 && map[tank->y][tank->x + 2] == 0 && map[tank->y + 1][tank->x + 2] == 0) {

			//tank->direction = RIGHT;
			/*************
			实现移动
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
* 算法仍需设计，单数攻击我方坦克，双数攻击老鹰
***********/
//控制敌方坦克移动的函数，向着我方坦克移动
/**********
* 根据目标位置，调整敌方坦克的方向
***********/

DIRECTION enemy_direction(tank_s* tank, int x, int y) {
	int r = rand() % 100;   //没包含库文件啊？
	if (tank->x > x) {
		//目标在左边
		if (tank->y > y) {

			//目标在左上方
			if (r <= 50) return UP;
			else return LEFT;

		}

		else {

			//目标在左下方
			if (r <= 50) return DOWN;
			else return LEFT;

		}

	}
	else {

		//目标在右边
		if (tank->y > y) {
			//目标在右上方
			if (r <= 50) return UP;
			else return RIGHT;

		}

		else {

			//目标在右下方
			if (r <= 50) return DOWN;
			else return RIGHT;

		}

	}


}

void tank_fire(tank_s* tank, bullet_s* bullet) {
	if (bullet->status == 0) {
		//敌方坦克不需要音频
		
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
*实现游戏场景
**************************/


int play() {
	tank_s my_tank;
	
	//我方坦克
	bullet_s my_bullet;
	//我方坦克放的子弹
	
	tank_s enemy_tank[ENEMY_NUM];
	
	//敌方坦克
	bullet_s enemy_bullet[ENEMY_NUM];
	
	//敌方坦克发射的子弹
	//快速敌方坦克
	tank_s fast_tank[ENEMY_NUM];
	
	bullet_s fast_bullet[ENEMY_NUM];
	IMAGE my_tank_img[4];
	IMAGE enemy_tank_img[4];
	IMAGE fast_tank_img[4];
	int key;
	int times = 0; 
	//记录当前程序的休眠次数，每次10ms，到500ms时让敌方坦克动一下
	
	int enemy_total = 0;

	//初始化随机数种子
	srand(time(NULL)); //时间戳

	//HHOOK keyboardHook;    // 键盘钩子的句柄

	//加载我方坦克的图片
	loadimage(&my_tank_img[UP], _T("./res/img/tank_up.jpg"), 50, 50);
	loadimage(&my_tank_img[DOWN], _T("./res/img/tank_down.jpg"), 50, 50);
	loadimage(&my_tank_img[LEFT], _T("./res/img/tank_left.jpg"), 50, 50);
	loadimage(&my_tank_img[RIGHT], _T("./res/img/tank_right.jpg"), 50, 50);

	//加载敌方坦克的图片
	loadimage(&enemy_tank_img[UP], _T("./res/img/enemy_tank_up.jpg"), 50, 50);
	loadimage(&enemy_tank_img[DOWN], _T("./res/img/enemy_tank_down.jpg"), 50, 50);
	loadimage(&enemy_tank_img[LEFT], _T("./res/img/enemy_tank_left.jpg"), 50, 50);
	loadimage(&enemy_tank_img[RIGHT], _T("./res/img/enemy_tank_right.jpg"), 50, 50);

	//加载快速坦克
	loadimage(&fast_tank_img[UP], _T("./res/img/p2tankU.gif"), 50, 50);
	loadimage(&fast_tank_img[DOWN], _T("./res/img/p2tankD.gif"), 50, 50);
	loadimage(&fast_tank_img[LEFT], _T("./res/img/p2tankL.gif"), 50, 50);
	loadimage(&fast_tank_img[RIGHT], _T("./res/img/p2tankR.gif"), 50, 50);

	//loadimagefastst[0], _T("./res/img/blast1.gif"), 50, 50);
	//子弹初始化0不存在，1存在
	my_bullet.status = 0;
	//子弹尚不存在，状态为1时不可发射下一发，状态为0时可以发射下一发

	//我方坦克出场位置
	my_tank.x = 8;
	my_tank.y = 24;
	my_tank.live = 1; //出场时的状态
	my_tank.direction = UP;

	map[my_tank.y][my_tank.x] = 200;
	map[my_tank.y][my_tank.x + 1] = 200;
	map[my_tank.y + 1][my_tank.x] = 200;
	map[my_tank.y + 1][my_tank.x + 1] = 200;


	putimage(my_tank.x * 25, my_tank.y * 25, &my_tank_img[UP]);
	set_prop_map(my_tank.x, my_tank.y, 200/*要设定的值*/);
	//设置敌方坦克出场的位置
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
		//set_prop_map(enemy_tank[i].x, enemy_tank[i].y, 100 + i/*要设定的值*/);
		// //set_prop_map(enemy_tank[i].x, enemy_tank[i].y, 100 + i/*要设定的值*/);
		// //把敌方坦克的值设成100 + i
		enemy_bullet[i].status = 0;
		//子弹不存在，可以开下一发

	}

	//音乐响起来
	mciSendString(_T("open ./res/music/background.flac alias al wait"), NULL, 0, NULL);
	mciSendString(_T("play al"), 0, 0, 0);

	//前三辆坦克登场
	do_tank_walk(&enemy_tank[0], DOWN, &enemy_tank_img[DOWN], 0);
	set_prop_map(enemy_tank[0].x, enemy_tank[0].y, 100 /*要设定的值*/);
	//把敌方坦克的值设成100 + i
	do_tank_walk(&enemy_tank[1], DOWN, &enemy_tank_img[DOWN], 0);
	set_prop_map(enemy_tank[1].x, enemy_tank[1].y, 101/*要设定的值*/);
	//把敌方坦克的值设成100 + i
	do_tank_walk(&enemy_tank[2], DOWN, &enemy_tank_img[DOWN], 0);
	set_prop_map(enemy_tank[2].x, enemy_tank[2].y, 102/*要设定的值*/);
	//把敌方坦克的值设成100 + i

	enemy_total = 3;

	//快速坦克设为666
	fast_tank[0].direction = LEFT;
	fast_tank[0].live = 1;
	fast_bullet[0].status = 0;
	fast_tank[0].x = 12;
	fast_tank[0].y = 13;
	do_tank_walk(&fast_tank[0], LEFT, &fast_tank_img[LEFT], 0);

	putimage(fast_tank[0].x * 25, fast_tank[0].y * 25, &fast_tank_img[LEFT]);
	set_prop_map(fast_tank[0].x, fast_tank[0].y, 666/*要设定的值*/);

	
	while (1) {
		//12.7发射子弹和坦克移动不能并行
		//原本转向时会自己走一格，现在要优化
		if (_kbhit()) {//有键按下返回1
			key = _getch();

			switch (key) {
			case 'a'://左
				//满足这三个条件代表左边是空地，可以移动
				//tank_walk(&my_tank,LEFT,&my_tank_img[LEFT]);
				if (my_tank.direction == LEFT && (my_tank.x - 1) >= 0 && map[my_tank.y][my_tank.x - 1] == 0 && map[my_tank.y + 1][my_tank.x - 1] == 0) {

					//my_tank.direction = LEFT;
					/*************
					实现移动
					**************/

					do_tank_walk(&my_tank, LEFT, &my_tank_img[my_tank.direction], 1);

				}

				else if (my_tank.direction != LEFT) {

					my_tank.direction = LEFT;
					
					// PlaySound(TEXT("./res/music/moving.mp3"), NULL, SND_FILENAME | SND_ASYNC);
					
					do_tank_walk(&my_tank, LEFT, &my_tank_img[my_tank.direction], 0);

				}


				break;

			case'w'://上
				//tank_walk(&my_tank,UP,&my_tank_img[UP]);
				if (my_tank.direction == UP && (my_tank.y - 1) >= 0 && map[my_tank.y - 1][my_tank.x] == 0 && map[my_tank.y - 1][my_tank.x + 1] == 0) {

					//my_tank.direction = UP;
					/*************
					实现移动
					**************/

					do_tank_walk(&my_tank, UP, &my_tank_img[my_tank.direction], 1);

				}

				else if (my_tank.direction != UP) {

					my_tank.direction = UP;
					do_tank_walk(&my_tank, UP, &my_tank_img[my_tank.direction], 0);

				}

				break;

			case's'://下

				//tank_walk(&my_tank,DOWN,&my_tank_img[DOWN]);
				if (my_tank.direction == DOWN && (my_tank.y + 2) <= 25 && map[my_tank.y + 2][my_tank.x] == 0 && map[my_tank.y + 2][my_tank.x + 1] == 0) {

					//my_tank.direction = DOWN;
					/*************
					实现移动
					**************/

					do_tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.direction], 1);

				}

				else if (my_tank.direction != DOWN) {

					my_tank.direction = DOWN;
					do_tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.direction], 0);

				}

				break;

			case'd'://右
				//tank_walk(&my_tank,RIGHT,&my_tank_img[RIGHT]);
				if (my_tank.direction == RIGHT && (my_tank.x + 2) <= 25 && map[my_tank.y][my_tank.x + 2] == 0 && map[my_tank.y + 1][my_tank.x + 2] == 0) {

					//my_tank.direction = RIGHT;
					
					/*************
					实现移动
					**************/

					do_tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.direction], 1);

				}

				else if (my_tank.direction != RIGHT) {

					my_tank.direction = RIGHT;
					do_tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.direction], 0);

				}

				break;

			case'j'://开火
			{
				if (my_bullet.status == 1)
					//已经有子弹存在，不可以发射下一发
					break;
				//tank_fire(&my_tank, &my_bullet);
				
				//方向设置
				my_bullet.direction = my_tank.direction;
								
				my_bullet.status = 1;
				//为了测试就直接不改变状态了
				tank_fire(&my_tank, &my_bullet, 1);	

				//初始化子弹坐标，播放音频			
				//bullet_action(&my_bullet);
				break;
				//bullet_action(&my_bullet);//实现子弹发射清除的函数


			}

			case'p':
				//暂停
				system("pause");
				break;

			default:

				//其他输入无需处理
				break;

			}

			//switch的括号

		}

		//if的括号
		if (times % 100 == 0) {

			//2ms调转坦克方向一次
			for (int i = 0; i < enemy_total; i++) {
				if (enemy_tank[i].live == 0) continue;
				if (i % 2 == 0) {

					//偶数，攻击我方老巢（向我方老巢前进）
					DIRECTION d = enemy_direction(&enemy_tank[i], 12, 24);
					tank_walk(&enemy_tank[i], d, &enemy_tank_img[d]);

				}

				else {

					//攻击我方坦克（向我方坦克前进）
					DIRECTION d = enemy_direction(&enemy_tank[i], my_tank.x, my_tank.y);
					tank_walk(&enemy_tank[i], d, &enemy_tank_img[d]);

				}

				tank_fire(&enemy_tank[i], &enemy_bullet[i]);

			}

		}
		else if (times % 50 == 0) {

			//0.5ms移动地方还生存的坦克
			for (int i = 0; i < enemy_total; i++) {

				if (enemy_tank[i].live) {
					tank_walk(&enemy_tank[i], enemy_tank[i].direction, &enemy_tank_img[enemy_tank[i].direction]);

				}

			}

		}
		//对快速坦克的操控
		if (times % 50 == 0) {
		
			//
				if (fast_tank[0].live == 0) return 0;
				
		//	//偶数，攻击我方老巢（向我方老巢前进）
		   //DIRECTION d = enemy_direction(&enemy_tank[i], 12, 24);
				//	tank_walk(&enemy_tank[i], d, &enemy_tank_img[d]);
		
				//}
		
				//else {
				//攻击我方坦克（向我方坦克前进）

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
		//待优化，敌人子弹打不死自己，我们的子弹也打不死自己
		//我方子弹运动效果
		//强无敌，已经实现功能

		if (my_bullet.status == 1) {
			//bullet_action(&my_bullet, enemy_tank);
			if (bullet_action(&my_bullet, enemy_tank, 1)) return 1; 
			//输了
			
			//clean(enemy_bullet, &my_bullet);

		}

		/*****************
		* 敌方子弹运动效果
		*****************/

		for (int i = 0; i < ENEMY_NUM; i++) {

			if (enemy_bullet[i].status == 1) {
				//1是还在空中飞
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

			//判断出场的二维数组是否已经有坦克存在（待优化）
			set_prop_map(enemy_tank[enemy_total].x, enemy_tank[enemy_total].y, 100 + enemy_total/*要设定的值*/);
			
			//把敌方坦克的值设成100 + i
			set_prop_map(enemy_tank[enemy_total].x, enemy_tank[enemy_total].y, 100 + enemy_total/*要设定的值*/);
			enemy_total++;
		
		}
		if (fast_bullet[0].status == 1) {

		//1是还在空中飞，就继续循环让子弹飞
		//	//bullet_action(&enemy_bullet[i], enemy_tank);
		//	//bullet_action(&enemy_bullet[i], enemy_tank);
			if (bullet_action(&fast_bullet[0], enemy_tank, 3)) return 1;

		}

		//
		//
		/**************************
		* 判断敌方坦克是否全部被消灭
		***************************/
		int isWin = 1;
		//判断游戏进度

		for (int i = 0; i < ENEMY_NUM; i++) {
			if (enemy_tank[i].live == 1) {
				isWin = 0;

			}

		}
		if (isWin) {
			//播放胜利音乐，退出游戏
			PlaySound(TEXT("./res/music/Get Daze.wav"), NULL, SND_FILENAME | SND_ASYNC);
			return 0;

		}


		//控制循环的速度
		Sleep(1);
		times++;
		//代表经过10ms了

	}
	//while的括号

}
//最后的括号
