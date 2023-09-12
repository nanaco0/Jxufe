#pragma once
void search_cargo()
{
	fileread();
	system("cls");
	int sel, j, num = sizeof(cargos) / sizeof(struct cargo);
	char searchName[20],searchID[20];
	struct cargo temCargo;
	printf("\t\t\t***************** »¶Ó­À´µ½²Ö¿â¹ÜÀíÏµÍ³ *****************\n\n\n");
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t|                    ÇëÑ¡ÔñÄúµÄ²Ù×÷:                   |\n");
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\n\n");

	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t|                    ²éÕÒ»õÎï¹¦ÄÜ                      |\n");
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t|                  1   »õÎïÃû²éÕÒ                      |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  2   »õÎïºÅ²éÕÒ                      |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  3   ·µ»ØÖ÷²Ëµ¥                      |\n");
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t|                 ÇëÊäÈëÄúµÄÑ¡Ôñ¡¾1-3¡¿£º              |");
	printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
	scanf("%d", &sel);
	getchar();
	while (sel < 1 || sel>3)
	{
		printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		printf("\t\t\t|           ÊäÈë´íÎó,ÇëÖØÐÂÊäÈëÄúµÄÑ¡Ôñ¡¾1-3¡¿£º        |");
		printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
		scanf("%d", &sel);
	}
	if (sel == 1)
	{
		printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		printf("\t\t\t|                     ÇëÌîÐ´»õÎïÃû³Æ:                  |");
		printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
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
			printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
			printf("\t\t\t|                     ¸Ã»õÎïÐÅÏ¢ÈçÏÂ:                  |");
			printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");

			printf("\t\t\t|  %-16s", "±àºÅ");
			printf("%-12s", "»õÎïÃû³Æ");
			printf("%-12s", "¿â´æÊýÁ¿");
			printf("%-10s  |", "Ä¬ÈÏµ¥Î»");
			printf("\n");
			printf("\t\t\t|  %-16s", cargos[j].cargo_id);
			printf("%-12s", cargos[j].cargo_name);
			printf("%-12d", cargos[j].cargo_quantity);
			printf("%-10s  |", cargos[j].cargo_unit);
			printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");

		}
		else
		{
			printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
			printf("\t\t\t|                   Ã»ÓÐÆ¥ÅäµÄ»õÎïÐÅÏ¢£¡               |");
			printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		}

	}
	else if (sel == 2)
	{
		printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		printf("\t\t\t|                     ÇëÌîÐ´»õÎï±àºÅ:                  |");
		printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
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
			printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
			printf("\t\t\t|                     ¸Ã»õÎïÐÅÏ¢ÈçÏÂ:                  |");
			printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	
			printf("\t\t\t|      %-16s", "±àºÅ");
			printf("%-10s", "»õÎïÃû³Æ");
			printf("%-10s", "¿â´æÊýÁ¿");
			printf("%-10s  |", "Ä¬ÈÏµ¥Î»");
			printf("\n");
			printf("\t\t\t|      %-16s", cargos[j].cargo_id);
			printf("%-10s", cargos[j].cargo_name);
			printf("%-10d", cargos[j].cargo_quantity);
			printf("%-10s  |", cargos[j].cargo_unit);
			printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		}
		else
		{
			printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
			printf("\t\t\t|                   Ã»ÓÐÆ¥ÅäµÄ»õÎïÐÅÏ¢£¡               |");
			printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
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

// KMPËã·¨²éÕÒº¯Êý


int kmpSearch(char text[], char pattern[]) {
	int textLen = strlen(text);
	int patternLen = strlen(pattern);
	int* next = (int*)malloc((patternLen + 1) * sizeof(int)); // ¶¯Ì¬·ÖÅäÄÚ´æ


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

	free(next); // ÊÍ·Å¶¯Ì¬·ÖÅäµÄÄÚ´æ


	if (j == patternLen) {
		return i - j; // ·µ»ØÆ¥ÅäµÄÆðÊ¼Î»ÖÃ

	}
	else {
		return -1; // Ã»ÓÐÕÒµ½Æ¥ÅäµÄÄÚÈÝ

	}
}
