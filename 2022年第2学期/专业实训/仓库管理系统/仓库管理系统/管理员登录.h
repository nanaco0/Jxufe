void admin_login()
{
	system("cls");
	int i, sel, sell, flag = 0;
	struct admin temAdmin;
	printf("\t\t\t***************** 欢迎来到仓库管理系统 *****************\n\n\n");
	printf("\t\t\t|———————————————————————————|\n");
	printf("\t\t\t|                    请选择您的操作:                   |\n");
	printf("\t\t\t|———————————————————————————|\n\n\n");

	printf("\t\t\t|———————————————————————————|\n");
	printf("\t\t\t|                  |仓库管理员登录界面|                |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  1   开始登录                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  2   返回上一级菜单                  |\n");
	printf("\t\t\t|———————————————————————————|\n");
	printf("\n\n\n\t\t\t|———————————————————————————|\n");
	printf("\t\t\t|                 请输入您的选择【1-2】：              |");
	printf("\n\t\t\t|———————————————————————————|\n\t\t\t");
	scanf("%d", &sel);
	getchar();
	while (sel < 1 || sel > 2)
	{
		printf("\n\n\n\t\t\t|———————————————————————————|\n");
		printf("\t\t\t|            输入错误,请重新输入您的选择【1-2】：         |");
		printf("\n\t\t\t|———————————————————————————|\n\t\t\t");
		scanf("%d", &sel);
	}
	if (sel == 1)
	{
		printf("\n\n\n\t\t\t|———————————————————————————|\n");
		printf("\t\t\t|                    请填写登录信息:                   |\n");
		printf("\t\t\t|———————————————————————————|\n");

	here:
		printf("\t\t\t输入用户名:");
		scanf("%s", &temAdmin.admin_account);
		printf("\t\t\t输入密码:");
		scanf("%s", &temAdmin.admin_password);
		for (i = 0; i < M; i++)
		{
			if (strcmp(admins[i].admin_account, temAdmin.admin_account) == 0 && strcmp(admins[i].admin_password, temAdmin.admin_password) == 0)
			{
				flag = 1;
				// 如果不是可以使用的用户名，直接退出注册，返回到主界面
				printf("\t\t\t登录成功,即将跳转至系统管理界面\n");
				int j = 6;
				printf("\t\t\t");
				while (j-- >= 1)
				{
					printf(".");
					Sleep(50);
				}
				admin_menu();
			}
		}
		if (flag == 0)
		{
			system("cls");
			printf("\n\n\n\t\t\t|———————————————————————————|\n");
			printf("\t\t\t|你输入的用户名或密码有误,你可以选择:                  |\n");
			printf("\t\t\t|———————————————————————————|\n");
			printf("\t\t\t|                 1 重新填写登录信息                   |\n");
			printf("\t\t\t|                 2 返回上一级菜单                     |\n");
			printf("\t\t\t|———————————————————————————|\n");
			printf("\n\n\n\t\t\t|———————————————————————————|\n");
			printf("\t\t\t|                 请输入您的选择【1-2】：              |");
			printf("\n\t\t\t|———————————————————————————|\n\t\t\t");
			scanf("%d", &sell);
			getchar();
			while (sell < 1 || sell > 2)
			{
				printf("\n\n\n\t\t\t|———————————————————————————|\n");
				printf("\t\t\t|            输入错误,请重新输入您的选择【1-2】：         |");
				printf("\n\t\t\t|———————————————————————————|\n\t\t\t");
				scanf("%d", &sell);
			}
			switch (sell)
			{
			case 1:
				goto here;
				break;
			case 2:
				menu();
				break;
			}
		}
	}
	else if (sel == 2)
	{
		menu();
	}

	// 因为新用户注册成功，所以用户注册信息需要重新全部保存
	filesave();
	printf("\t\t\t");
	system("pause");
}
