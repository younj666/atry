//#include<graphics.h>
#include"menu.h"
#include"map.h"
#include<conio.h>//检测键盘输入的头文件
#include"tank.h"
#include"play.h"
#include"bullet.h"
#include<windows.h>
#define SUCCESS 0
#define FAILURE 1

void game_over(int result);

void main(void) {
	int result = SUCCESS;
	AGAIN:

	//搭建舞台
	initgraph(650, 650);
	
	
	//开始场景，显示菜单
	menu();

	//初始化地图
	init_map_2(&map[0][0], 26, 26);

	//画坦克和一些操作函数
	//判断play的结果，返回1说明我方失败，返回0说明我方胜利
	result = play();

	//显示游戏的结果
	game_over(result);

	//是否继续游戏
	
	int ret = MessageBox(NULL, TEXT("是否重新开始"), TEXT("请选择"), MB_YESNO | MB_ICONQUESTION); //这里可以改成导入第二关

	if (ret == IDYES) {
		cleardevice();
		//重置地图
		refresh();
		//重新导入地图，进入第二关，考虑怎么实现？
		goto AGAIN;

	}

	
	
	
	

	//防止窗口消失
	system("pause");

	closegraph();
	exit(0);

	//return 0;

}
void game_over(int result) {

	IMAGE img;

	if (result == SUCCESS) {
		loadimage(&img, _T("./res/img/vectory.jpeg"), 500, 250);
		putimage(80, 200, &img);

	}
	else {
		loadimage(&img, _T("./res/img/big-gameover.gif"), 500, 250);
		putimage(80, 200, &img);

	}

	_getch();

}
//"./res/img/big-gameover.gif"

//可以进一步加代码的部分
//下一关
//双人模式
//优化一些代码
//数字定义成宏
//
//很简单，加上敌方坦克爆炸效果，已实现
//几张图放出来然后再涂掉就行
//加上移速和打炮更快的坦克
//我方老鹰被击打后的变化效果,已实现
//加道具
//已经解决自己的子弹打不死自己完美
//打击绿色坦克，敌方第一个坦克爆了哈哈
//在判断击中快速坦克那里有问题
//炮台老是打到