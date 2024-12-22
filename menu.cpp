#include"menu.h"

void menu()
{
	
	//显示logo
	IMAGE logo_image;
	//定义一个变量，来存放图片
	loadimage(&logo_image, _T("./res/img/logo.bmp"), 433, 147);
	//把图片加载进去，并限定尺寸(图片原大小）
	putimage(110, 20, &logo_image);//粉刷匠（定位置）


	//实现导航按钮
	setlinecolor(WHITE);
	setfillcolor(BLACK);
	fillrectangle(230, 200, 310, 240);
	settextstyle(25, 0, _T("宋体"));
	outtextxy(240, 210, _T("说 明"));
	fillrectangle(350, 200, 430, 240);
	outtextxy(360, 210, _T("开 始"));



	//outtextxy()
	//判断鼠标状态
	MOUSEMSG mouse;
	IMAGE illustrate_img;
	loadimage(&illustrate_img, _T("./res/img/illustrate.jpg"), 300, 300);
	//int finished = 0;
	while (true) {

		mouse = GetMouseMsg();

		switch (mouse.uMsg) {
		case WM_MOUSEMOVE://移动鼠标
			if ((mouse.x > 230 && mouse.x < 310) && (mouse.y > 200 && mouse.y < 240)) {
				putimage(150, 250, &illustrate_img);

			}
			else {
				solidrectangle(150, 250, 450, 550); 
				//画黑色矩形，实现说明图片的遮盖

			}

			break;

		case WM_LBUTTONDOWN://鼠标左键被点击

			if ((mouse.x > 350 && mouse.x < 430) && (mouse.y > 200 && mouse.y < 240)) { //加括号为增强可读性
				cleardevice();
				//清屏
				PlaySound(TEXT("./res/music/start.wav"), NULL, SND_FILENAME | SND_ASYNC);
				return;
				//finished = 1;//控制循环体
				//break;

			}

		}

	}

}