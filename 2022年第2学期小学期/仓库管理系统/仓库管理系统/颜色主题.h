#pragma once
void default_style()
{
	system("color 0F");
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 更换黑色主题成功~                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
	menu();
}

void white_style() 
{
	system("color F0");
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 更换白色主题成功~                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
	menu();
}

void blue_style()
{
	system("color 9F");
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 更换蓝色主题成功~                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
	menu();
}

void yellow_style()
{
	system("color E0");
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 更换黄色主题成功~                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
	menu();
}

void green_style()
{
	system("color BF");
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 更换绿色主题成功~                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
	menu();
}

void purple_style()
{
	system("color DF");
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 更换紫色主题成功~                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
	menu();
}

void gray_style()
{
	system("color 8F");
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 更换灰色主题成功~                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
	menu();
}

void red_style()
{
	system("color CF");
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 更换红色主题成功~                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
	menu();
}
void color_style() 
{
	int sel;
	system("cls");

	printf("\t\t\t***************** 欢迎来到仓库管理系统 *****************\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                    请选择您的操作:                   |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                      选择主题功能                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  1   默认黑色                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  2   简洁白色                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  3   活力蓝色                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  4   明媚黄色                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  5   自然绿色                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  6   幽静紫色                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  7   低调灰色                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  8   吉祥红色                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  0   返回上一级菜单                  |\n");
	printf("\t\t\t|------------------------------------------------------|\n");

	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 请输入您的选择【0-8】：              |\n");
	printf("\t\t\t|------------------------------------------------------|\n\t\t\t");
	scanf("%d", &sel);
	getchar();

	while (sel < 0 || sel > 8)
	{
		printf("\t\t\t|------------------------------------------------------|\n");
		printf("\t\t\t|          输入错误,请重新输入您的选择【0-8】：        |\n");
		printf("\t\t\t|------------------------------------------------------|\n\t\t\t");
		scanf("%d", &sel);
	}

	switch (sel)
	{
	case 1:
		default_style();
		break;
	case 2:
		white_style();
		break;
	case 3:
		blue_style();
		break;
	case 4:
		yellow_style();
		break;
	case 5:
		green_style();
		break;
	case 6:
		purple_style();
		break;
	case 7:
		gray_style();
		break;
	case 8:
		red_style();
		break;
	case 0:
		menu();
		break;
	}
}

