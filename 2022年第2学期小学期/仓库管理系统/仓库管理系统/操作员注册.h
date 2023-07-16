#pragma once
void user_registers()
{

	system("cls");
	int i, sel;
	struct user temUser;
	printf("\t\t\t***************** ��ӭ�����ֿ����ϵͳ *****************\n\n\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                    ��ѡ�����Ĳ���:                   |\n");
	printf("\t\t\t|������������������������������������������������������|\n\n\n");

	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                 |�ֿ����Աע�����|                 |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  1   ��ʼע��                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  2   ������һ���˵�                  |\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                 ����������ѡ��1-2����              |\n");
	printf("\t\t\t|������������������������������������������������������|\n\t\t\t");
	scanf("%d", &sel);
	getchar();
	while (sel < 1 || sel > 2)
	{
		printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
		printf("\t\t\t|          �������,��������������ѡ��1-2����        |");
		printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
		scanf("%d", &sel);
	}
	if (sel == 1)
	{
		printf("\n\n\n\t\t\t-------------------------------------------\n");
		printf("\t\t\t����дע����Ϣ:\n");
		printf("\t\t\t-------------------------------------------\n");
		printf("\t\t\t�����û���:");
		scanf("%s", &temUser.user_account);
		printf("\t\t\t�����ֻ���:");
		scanf("%s", &temUser.user_phone);
		printf("\t\t\t��������(�������ֺ���ĸ����λ�����ϵ�����):");
		scanf("%s", &temUser.user_password);
		for (i = 0; i < N; i++)
		{
			while (strcmp(users[i].user_account, temUser.user_account) == 0)
			{
				// ������ǿ���ʹ�õ��û�����ֱ���˳�ע�ᣬ���ص�������
				printf("\n\n\n\t\t\t-------------------------------------------\n");
				printf("\t\t\t���û����ѱ�ע�ᣡ��������дע����Ϣ:\n");
				printf("\t\t\t-------------------------------------------\n");
				printf("\t\t\t�����û���:");
				scanf("%s", &temUser.user_account);
				printf("\t\t\t�����ֻ���:");
				scanf("%s", &temUser.user_phone);
				printf("\t\t\t��������:");
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
			// ���볤��С��6λ��������Ҫ��
			printf("\n\n\n\t\t\t-------------------------------------------\n");
			printf("\t\t\t���볤��С��6λ��������Ҫ����������дע����Ϣ:\n");
			printf("\t\t\t-------------------------------------------\n");
			printf("\t\t\t�����û���:");
			scanf("%s", &temUser.user_account);
			printf("\t\t\t�����ֻ���:");
			scanf("%s", &temUser.user_phone);
			printf("\t\t\t��������:");
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
			printf("\t\t\t�������Ҫ��~\n");
			printf("\t\t\t-------------------------------------------\n");
		}
		else
		{
			printf("\t\t\t-------------------------------------------\n");
			printf("\t\t\t�������벻�������ֻ���ĸ��������Ҫ����������дע����Ϣ:\n");
			printf("\t\t\t-------------------------------------------\n");
			printf("\t\t\t�����û���:");
			scanf("%s", &temUser.user_account);
			printf("\t\t\t�����ֻ���:");
			scanf("%s", &temUser.user_phone);
			printf("\t\t\t��������:");
			scanf("%s", &temUser.user_password);
		}
		printf("\n\n\t\t\t-------------------------------------------\n");
		printf("\t\t\tע��ɹ�������\n");
		printf("\n\n\t\t\t-------------------------------------------\n");

		// ����ID
		int serial_number = 1;
		// ��ȡ��ǰ���ں�ʱ��
		time_t now = time(NULL);
		struct tm* current_time = localtime(&now);
		// ��ʽ��������
		sprintf(temUser.user_id, "%04d%02d%02d%02d", current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday, serial_number);
		// �洢���ɵ��ַ���
		printf("\n\n\t\t\t-------------------------------------------\n");
		printf("\t\t\t����ID�ǣ�%s", temUser.user_id);
		printf("\n\n\t\t\t-------------------------------------------\n");
	}
	else if (sel == 2)
	{
		menu();
	}

	// ��Ϊ���û�ע��ɹ��������û�ע����Ϣ��Ҫ����ȫ������
	filesave();
	printf("\t\t\t");
	system("pause");
}
