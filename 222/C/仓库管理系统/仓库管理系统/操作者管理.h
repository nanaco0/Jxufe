void show_user()
{
	fileread();
	system("cls");
	int i;
	printf("\t\t\t***************** 欢迎来到仓库管理系统 *****************\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                    操作员管理功能                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|               该仓库普通操作员名单如下:              |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|  %-16s","编号");
	printf("%-10s", "用户");
	printf("%-16s", "手机号");
	printf("%-10s|", "密码");
	printf("\n");

	for (i = 0; i < N; i++)
	{
		if (strcmp(users[i].user_account, "") != 0)
		{
			printf("\t\t\t|  %-16s", users[i].user_id);
			printf("%-10s", users[i].user_account);
			printf("%-16s", users[i].user_phone);
			printf("%-10s|", users[i].user_password);
			printf("\n");
		}
		else
		{
			break;
		}
	}
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
}
