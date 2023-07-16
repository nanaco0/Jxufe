#pragma once
void user_registers()
{

	system("cls");
	int i, sel;
	struct user temUser;
	printf("\t\t\t***************** 欢迎来到仓库管理系统 *****************\n\n\n");
	printf("\t\t\t|———————————————————————————|\n");
	printf("\t\t\t|                    请选择您的操作:                   |\n");
	printf("\t\t\t|———————————————————————————|\n\n\n");

	printf("\t\t\t|———————————————————————————|\n");
	printf("\t\t\t|                 |仓库操作员注册界面|                 |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  1   开始注册                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  2   返回上一级菜单                  |\n");
	printf("\t\t\t|———————————————————————————|\n");
	printf("\n\n\n\t\t\t|———————————————————————————|\n");
	printf("\t\t\t|———————————————————————————|\n");
	printf("\t\t\t|                 请输入您的选择【1-2】：              |\n");
	printf("\t\t\t|———————————————————————————|\n\t\t\t");
	scanf("%d", &sel);
	getchar();
	while (sel < 1 || sel > 2)
	{
		printf("\n\n\n\t\t\t|———————————————————————————|\n");
		printf("\t\t\t|          输入错误,请重新输入您的选择【1-2】：        |");
		printf("\n\t\t\t|———————————————————————————|\n\t\t\t");
		scanf("%d", &sel);
	}
	if (sel == 1)
	{
		printf("\n\n\n\t\t\t-------------------------------------------\n");
		printf("\t\t\t请填写注册信息:\n");
		printf("\t\t\t-------------------------------------------\n");
		printf("\t\t\t输入用户名:");
		scanf("%s", &temUser.user_account);
		printf("\t\t\t输入手机号:");
		scanf("%s", &temUser.user_phone);
		printf("\t\t\t输入密码(含有数字和字母的六位及以上的密码):");
		scanf("%s", &temUser.user_password);
		for (i = 0; i < N; i++)
		{
			while (strcmp(users[i].user_account, temUser.user_account) == 0)
			{
				// 如果不是可以使用的用户名，直接退出注册，返回到主界面
				printf("\n\n\n\t\t\t-------------------------------------------\n");
				printf("\t\t\t该用户名已被注册！请重新填写注册信息:\n");
				printf("\t\t\t-------------------------------------------\n");
				printf("\t\t\t输入用户名:");
				scanf("%s", &temUser.user_account);
				printf("\t\t\t输入手机号:");
				scanf("%s", &temUser.user_phone);
				printf("\t\t\t输入密码:");
				scanf("%s", &temUser.user_password);
			}
		}
		for (i = 0; i < N; i++)
		{
			if (strcmp(users[i].user_account, "") == 0)
			{
				users[i] = temUser;
				break;
			}
		}
		int length = strlen(temUser.user_password);
		int hasDigit = 0;
		int hasLetter = 0;

		if (length < 6)
		{
			// 密码长度小于6位，不符合要求
			printf("\n\n\n\t\t\t-------------------------------------------\n");
			printf("\t\t\t密码长度小于6位，不符合要求！请重新填写注册信息:\n");
			printf("\t\t\t-------------------------------------------\n");
			printf("\t\t\t输入用户名:");
			scanf("%s", &temUser.user_account);
			printf("\t\t\t输入手机号:");
			scanf("%s", &temUser.user_phone);
			printf("\t\t\t输入密码:");
			scanf("%s", &temUser.user_password);
		}

		for (int i = 0; i < length; i++)
		{
			if (isdigit(temUser.user_password[i]))
			{
				hasDigit = 1;
			}
			else if (isalpha(temUser.user_password[i]))
			{
				hasLetter = 1;
			}
		}

		if (hasDigit && hasLetter)
		{
			printf("\t\t\t-------------------------------------------\n");
			printf("\t\t\t密码符合要求~\n");
			printf("\t\t\t-------------------------------------------\n");
		}
		else
		{
			printf("\t\t\t-------------------------------------------\n");
			printf("\t\t\t密码密码不包含数字或字母，不符合要求！请重新填写注册信息:\n");
			printf("\t\t\t-------------------------------------------\n");
			printf("\t\t\t输入用户名:");
			scanf("%s", &temUser.user_account);
			printf("\t\t\t输入手机号:");
			scanf("%s", &temUser.user_phone);
			printf("\t\t\t输入密码:");
			scanf("%s", &temUser.user_password);
		}
		printf("\n\n\t\t\t-------------------------------------------\n");
		printf("\t\t\t注册成功！！！\n");
		printf("\n\n\t\t\t-------------------------------------------\n");

		// 生成ID
		int serial_number = 1;
		// 获取当前日期和时间
		time_t now = time(NULL);
		struct tm* current_time = localtime(&now);
		// 格式化年月日
		sprintf(temUser.user_id, "%04d%02d%02d%02d", current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday, serial_number);
		// 存储生成的字符串
		printf("\n\n\t\t\t-------------------------------------------\n");
		printf("\t\t\t您的ID是：%s", temUser.user_id);
		printf("\n\n\t\t\t-------------------------------------------\n");
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
