void show_user()
{
	fileread();
	system("cls");
	int i;
	printf("\t\t\t***************** ��ӭ�����ֿ����ϵͳ *****************\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                    ����Ա������                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|               �òֿ���ͨ����Ա��������:              |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|  %-16s","���");
	printf("%-10s", "�û�");
	printf("%-16s", "�ֻ���");
	printf("%-10s|", "����");
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
