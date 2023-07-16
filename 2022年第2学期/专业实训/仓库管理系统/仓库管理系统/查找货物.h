#pragma once
void search_cargo()
{
	fileread();
	system("cls");
	int sel, j, num = sizeof(cargos) / sizeof(struct cargo);
	char searchName[20],searchID[20];
	struct cargo temCargo;
	printf("\t\t\t***************** ��ӭ�����ֿ����ϵͳ *****************\n\n\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                    ��ѡ�����Ĳ���:                   |\n");
	printf("\t\t\t|������������������������������������������������������|\n\n\n");

	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                    ���һ��﹦��                      |\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                  1   ����������                      |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  2   ����Ų���                      |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  3   �������˵�                      |\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                 ����������ѡ��1-3����              |");
	printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
	scanf("%d", &sel);
	getchar();
	while (sel < 1 || sel>3)
	{
		printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
		printf("\t\t\t|           �������,��������������ѡ��1-3����        |");
		printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
		scanf("%d", &sel);
	}
	if (sel == 1)
	{
		printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
		printf("\t\t\t|                     ����д��������:                  |");
		printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
		scanf("%s", &searchName);

		int found = 0;
		for (int i = 0; i < P; i++)
		{
			if (kmpSearch(cargos[i].cargo_name, searchName) != -1)
			{
				found = 1;
				j = i;
			}
		}
		if (found)
		{
			printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
			printf("\t\t\t|                     �û�����Ϣ����:                  |");
			printf("\n\t\t\t|������������������������������������������������������|\n");

			printf("\t\t\t|  %-16s", "���");
			printf("%-12s", "��������");
			printf("%-12s", "�������");
			printf("%-10s  |", "Ĭ�ϵ�λ");
			printf("\n");
			printf("\t\t\t|  %-16s", cargos[j].cargo_id);
			printf("%-12s", cargos[j].cargo_name);
			printf("%-12d", cargos[j].cargo_quantity);
			printf("%-10s  |", cargos[j].cargo_unit);
			printf("\n\t\t\t|������������������������������������������������������|\n");

		}
		else
		{
			printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
			printf("\t\t\t|                   û��ƥ��Ļ�����Ϣ��               |");
			printf("\n\t\t\t|������������������������������������������������������|\n");
		}

	}
	else if (sel == 2)
	{
		printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
		printf("\t\t\t|                     ����д������:                  |");
		printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
		printf("\t\t\t");
		scanf("%s", &searchID);

		int found = 0;
		for (int i = 0; i < P; i++)
		{
			if (kmpSearch(cargos[i].cargo_id, searchID) != -1)
			{
				found = 1;
				j = i;
			}
		}
		if (found)
		{
			printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
			printf("\t\t\t|                     �û�����Ϣ����:                  |");
			printf("\n\t\t\t|������������������������������������������������������|\n");
	
			printf("\t\t\t|      %-16s", "���");
			printf("%-10s", "��������");
			printf("%-10s", "�������");
			printf("%-10s  |", "Ĭ�ϵ�λ");
			printf("\n");
			printf("\t\t\t|      %-16s", cargos[j].cargo_id);
			printf("%-10s", cargos[j].cargo_name);
			printf("%-10d", cargos[j].cargo_quantity);
			printf("%-10s  |", cargos[j].cargo_unit);
			printf("\n\t\t\t|������������������������������������������������������|\n");
		}
		else
		{
			printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
			printf("\t\t\t|                   û��ƥ��Ļ�����Ϣ��               |");
			printf("\n\t\t\t|������������������������������������������������������|\n");
		}

	}
	else if (sel == 3)
	{
		menu();
	}

	printf("\t\t\t");
	system("pause");
}

void computeNextArray(char pattern[], int next[]) {
	int len = strlen(pattern);
	int i = 0, j = -1;
	next[0] = -1;

	while (i < len) {
		if (j == -1 || pattern[i] == pattern[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

// KMP�㷨���Һ���


int kmpSearch(char text[], char pattern[]) {
	int textLen = strlen(text);
	int patternLen = strlen(pattern);
	int* next = (int*)malloc((patternLen + 1) * sizeof(int)); // ��̬�����ڴ�


	computeNextArray(pattern, next);

	int i = 0, j = 0;
	while (i < textLen && j < patternLen) {
		if (j == -1 || text[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}

	free(next); // �ͷŶ�̬������ڴ�


	if (j == patternLen) {
		return i - j; // ����ƥ�����ʼλ��

	}
	else {
		return -1; // û���ҵ�ƥ�������

	}
}
