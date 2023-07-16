#pragma once
void search_cargo()
{
	fileread();
	system("cls");
	int sel, j, num = sizeof(cargos) / sizeof(struct cargo);
	char searchName[20],searchID[20];
	struct cargo temCargo;
	printf("\t\t\t***************** 散哭栖欺花垂砿尖狼由 *****************\n\n\n");
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t|                    萩僉夲艇議荷恬:                   |\n");
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\n\n");

	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t|                    臥孀歯麗孔嬬                      |\n");
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t|                  1   歯麗兆臥孀                      |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  2   歯麗催臥孀                      |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  3   卦指麼暇汽                      |\n");
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t|                 萩補秘艇議僉夲‐1-3／��              |");
	printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
	scanf("%d", &sel);
	getchar();
	while (sel < 1 || sel>3)
	{
		printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		printf("\t\t\t|           補秘危列,萩嶷仟補秘艇議僉夲‐1-3／��        |");
		printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
		scanf("%d", &sel);
	}
	if (sel == 1)
	{
		printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		printf("\t\t\t|                     萩野亟歯麗兆各:                  |");
		printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
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
			printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
			printf("\t\t\t|                     乎歯麗佚連泌和:                  |");
			printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");

			printf("\t\t\t|  %-16s", "園催");
			printf("%-12s", "歯麗兆各");
			printf("%-12s", "垂贋方楚");
			printf("%-10s  |", "潮範汽了");
			printf("\n");
			printf("\t\t\t|  %-16s", cargos[j].cargo_id);
			printf("%-12s", cargos[j].cargo_name);
			printf("%-12d", cargos[j].cargo_quantity);
			printf("%-10s  |", cargos[j].cargo_unit);
			printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");

		}
		else
		{
			printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
			printf("\t\t\t|                   短嗤謄塘議歯麗佚連��               |");
			printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		}

	}
	else if (sel == 2)
	{
		printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		printf("\t\t\t|                     萩野亟歯麗園催:                  |");
		printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
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
			printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
			printf("\t\t\t|                     乎歯麗佚連泌和:                  |");
			printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	
			printf("\t\t\t|      %-16s", "園催");
			printf("%-10s", "歯麗兆各");
			printf("%-10s", "垂贋方楚");
			printf("%-10s  |", "潮範汽了");
			printf("\n");
			printf("\t\t\t|      %-16s", cargos[j].cargo_id);
			printf("%-10s", cargos[j].cargo_name);
			printf("%-10d", cargos[j].cargo_quantity);
			printf("%-10s  |", cargos[j].cargo_unit);
			printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		}
		else
		{
			printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
			printf("\t\t\t|                   短嗤謄塘議歯麗佚連��               |");
			printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
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

// KMP麻隈臥孀痕方


int kmpSearch(char text[], char pattern[]) {
	int textLen = strlen(text);
	int patternLen = strlen(pattern);
	int* next = (int*)malloc((patternLen + 1) * sizeof(int)); // 強蓑蛍塘坪贋


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

	free(next); // 瞥慧強蓑蛍塘議坪贋


	if (j == patternLen) {
		return i - j; // 卦指謄塘議軟兵了崔

	}
	else {
		return -1; // 短嗤孀欺謄塘議坪否

	}
}
