#include"menu.h"

void menu()
{
	
	//��ʾlogo
	IMAGE logo_image;
	//����һ�������������ͼƬ
	loadimage(&logo_image, _T("./res/img/logo.bmp"), 433, 147);
	//��ͼƬ���ؽ�ȥ�����޶��ߴ�(ͼƬԭ��С��
	putimage(110, 20, &logo_image);//��ˢ������λ�ã�


	//ʵ�ֵ�����ť
	setlinecolor(WHITE);
	setfillcolor(BLACK);
	fillrectangle(230, 200, 310, 240);
	settextstyle(25, 0, _T("����"));
	outtextxy(240, 210, _T("˵ ��"));
	fillrectangle(350, 200, 430, 240);
	outtextxy(360, 210, _T("�� ʼ"));



	//outtextxy()
	//�ж����״̬
	MOUSEMSG mouse;
	IMAGE illustrate_img;
	loadimage(&illustrate_img, _T("./res/img/illustrate.jpg"), 300, 300);
	//int finished = 0;
	while (true) {

		mouse = GetMouseMsg();

		switch (mouse.uMsg) {
		case WM_MOUSEMOVE://�ƶ����
			if ((mouse.x > 230 && mouse.x < 310) && (mouse.y > 200 && mouse.y < 240)) {
				putimage(150, 250, &illustrate_img);

			}
			else {
				solidrectangle(150, 250, 450, 550); 
				//����ɫ���Σ�ʵ��˵��ͼƬ���ڸ�

			}

			break;

		case WM_LBUTTONDOWN://�����������

			if ((mouse.x > 350 && mouse.x < 430) && (mouse.y > 200 && mouse.y < 240)) { //������Ϊ��ǿ�ɶ���
				cleardevice();
				//����
				PlaySound(TEXT("./res/music/start.wav"), NULL, SND_FILENAME | SND_ASYNC);
				return;
				//finished = 1;//����ѭ����
				//break;

			}

		}

	}

}