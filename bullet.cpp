#include"bullet.h"
#include"map.h"


/**********
实现子弹运行和碰撞检测，并反馈游戏结果，返回1-游戏失败，0-继续游戏
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
	//子弹目前所在二维数组的坐标
	x = bullet->pos_x / 25;  //像素除上25等于坐标
	y = bullet->pos_y / 25;

	//1.擦除上一次绘制的子弹
	setfillcolor(BLACK);
	solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);

	//2.根据方向计算子弹在戏台上的坐标
	if (bullet->direction == UP) {
		bullet->pos_y -= 2;
		x1 = x + 1;
		y1 = y;

	}
	else if (bullet->direction == DOWN) {
		bullet->pos_y += 2;
		x1 = x + 1;  //一下消掉两格可以让坦克往前走
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
		return 0;//目前并无大碍

	}
	//一些检测碰撞和边界的代码，先不要
	if (bullet->pos_x < 0 || bullet->pos_x > 650 || bullet->pos_y < 0 || bullet->pos_y > 650) {
		bullet->status = 0;
		//又可以发射了
		return 0;

	}
	//碰撞检测
	if (map[y][x] == 4 || map[y1][x1] == 4) {
		//是否击中老鹰，老鹰现在是4
		putimage(25 * 12, 25 * 24, &home_destroy);
		Sleep(1000);
		return 1;

	}
	//击中我方坦克
	
	if (map[y][x] == 200 || map[y1][x1] == 200) {
		if (key == 1) {
			bullet->status = 0;
			return 0;

		}
		//击中我方坦克
		PlaySound(TEXT("./res/music/blast.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return 1;

	}

	//敌方坦克被击中
	if ((map[y][x] >= 100 && map[y][x] <= 109) || ((map[y1][x1] >= 100 && map[y1][x1] <= 109))) {
		if (key == 0 || key == 3) {
			bullet->status = 0;
			return 0;

		}
		tank_s* tank = NULL;
		bullet->status = 0; //让子弹消失
		if (map[y][x] >= 100 && map[y][x] <= 109) {

			tank = enemy_tank + (map[y][x] - 100);//敌方坦克的编号

		}
		else {

			tank = enemy_tank + (map[y1][x1] - 100);

		}
		tank->live = 0;//把敌方坦克
		set_prop_map(tank->x, tank->y, 0);
		//把敌方坦克原本存在的地方置为0
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
	//子弹击中可消除的墙
	if (map[y][x] == 1 && map[y1][x1] == 1) {
		map[y][x] = 0;
		map[y1][x1] = 0;
		bullet->status = 0;
		//子弹恢复到可反射的状态
		setfillcolor(BLACK);
		solidrectangle(x * 25, y * 25 , x * 25 + 25, y * 25 + 25);
		//把这一小块墙遮住
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);//这句可能bug
		return 0;

	}
	else if (map[y][x] == 2) {
		//打到石头上了
		bullet->status = 0;
		return 0;
	}
	else if (map[y][x] == 6) {
		//打到标志上了
		bullet->status = 0;
		return 0;

	}
	if (map[y1][x1] == 1) {
		//打到可消除的墙
		map[y1][x1] = 0;
		bullet->status = 0;
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25 , x1 * 25 + 25, y1 * 25 + 25);
		return 0;

	}
	else if (map[y][x] == 1) {
		//打到可消除的墙
		map[y][x] = 0;
		bullet->status = 0;
		setfillcolor(BLACK);
		solidrectangle(x * 25, y * 25, x * 25 + 25, y * 25 + 25);
		return 0;

	}
	else if (map[y1][x1] == 2) {
		//打到石头
		bullet->status = 0;
		return 0;

	}
	else if (map[y1][x1] == 6) {
		//打到校徽
		bullet->status = 0;
		return 0;

	}
	////快速坦克被击中
	
	if (map[y][x] == 666 || map[y1][x1] == 666) {
	//	if (key == 3) {
	//		bullet->status = 0;
	//		return 0;
	//	}
	//	//tank_s* tank = NULL;
		bullet->status = 0; //让子弹消失
	//	enemy_tank->live = 0;//把敌方坦克
	//	set_prop_map(enemy_tank->x, enemy_tank->y, 0);
	//	//把敌方坦克原本存在的地方置为0
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

	
	
	//3.重新绘制子弹
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

void clean(bullet_s* enemy_bullet, bullet_s* my_bullet) {//子弹抵消，目前未实现功能
	if (enemy_bullet->pos_x == my_bullet->pos_x && enemy_bullet->pos_y == my_bullet->pos_y ) {

		enemy_bullet->status = 0;
		my_bullet->status = 0;
		setfillcolor(BLACK);
		solidrectangle(my_bullet->pos_x, my_bullet->pos_y, my_bullet->pos_x + 3, my_bullet->pos_y + 3);
		solidrectangle(enemy_bullet->pos_x, enemy_bullet->pos_y, enemy_bullet->pos_x + 3, enemy_bullet->pos_y + 3);

	}

}