// 计算跳转表
void computeLPSArray(char* pattern, int pattern_length, int* lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;

	while (i < pattern_length)
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// KMP匹配
int KMPSearch(char* pattern, char* text)
{
	int pattern_length = strlen(pattern);
	int text_length = strlen(text);

	// 创建跳转表
	int* lps = (int*)malloc(pattern_length * sizeof(int));
	computeLPSArray(pattern, pattern_length, lps);

	int i = 0;
	int j = 0;

	while (i < text_length)
	{
		if (pattern[j] == text[i])
		{
			j++;
			i++;
		}

		if (j == pattern_length)
		{
			free(lps);
			return 1; // 匹配成功
		}

		if (i < text_length && pattern[j] != text[i])
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
			}
		}
	}

	free(lps);
	return 0; // 匹配失败
}

void stock_cargos()
{
	fileread();
	system("cls");
	int i, sel;
	struct cargo tem_cargos;

	FILE* fp = fopen("./采购清单.txt", "r");
	if (fp == NULL)
	{
		printf("无法读取文件。\n");
		exit(0);
	}

	// 获取文件大小
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	// 动态分配字符数组
	char* buffer = (char*)malloc((file_size + 1) * sizeof(char));
	if (buffer == NULL)
	{
		printf("内存分配失败。\n");
		exit(0);
	}

	// 逐字符读取并存储在数组中
	int j = 0;
	int c;
	while ((c = fgetc(fp)) != EOF)
	{
		buffer[j++] = c;
	}
	buffer[j] = '\0';

	// 输出数组内容
	// printf("读取的内容为：\n");
	// printf("%s\n", buffer);

	printf("\t\t\t***************** 欢迎来到仓库管理系统 *****************\n\n\n");
	printf("\t\t\t|———————————————————————————|\n");
	printf("\t\t\t|                        进货功能                      |\n");
	printf("\t\t\t|———————————————————————————|\n");
	printf("\n");
here2:
	for (i = 0; i < P; i++)
	{
		if (strcmp(cargos[i].cargo_name, "") == 0)
		{
			printf("\t\t\t|———————————————————————————|\n");
			printf("\t\t\t|                接下来请继续选择您的操作:             |\n");
			printf("\t\t\t|———————————————————————————|\n");
			printf("\t\t\t|                 1   进货                             |\n");
			printf("\t\t\t|------------------------------------------------------|\n");
			printf("\t\t\t|                 2   退出进货功能                     |\n");
			printf("\t\t\t|———————————————————————————|\n");
			printf("\t\t\t|                 请输入您的选择【1-2】：              |\n");
			printf("\t\t\t|———————————————————————————|\n\t\t\t");
			scanf("%d", &sel);

			while (sel != 1 && sel != 2)
			{
				printf("\t\t\t|———————————————————————————|\n");
				printf("\t\t\t|                 请输入您的选择【1-2】：              |");
				printf("\n\t\t\t|———————————————————————————|\n\t\t\t");
				scanf("%d", &sel);
			}

			if (sel == 1)
			{
				int flag = 0;
				printf("\n\n\n\t\t\t|———————————————————————————|\n");
				printf("\t\t\t|                    输入进货货物名称:                 |");
				printf("\n\t\t\t|———————————————————————————|\n\t\t\t");
				scanf("%s", tem_cargos.cargo_name);

				// 使用KMP进行匹配
				int match = KMPSearch(tem_cargos.cargo_name, buffer);
				if (match)
				{
					printf("\n\n\n\t\t\t|———————————————————————————|\n");
					printf("\t\t\t|                    输入进货货物数量:                 |");
					printf("\n\t\t\t|———————————————————————————|\n\t\t\t");
					scanf("%d", &tem_cargos.cargo_quantity);
					printf("\n\n\n\t\t\t|———————————————————————————|\n");
					printf("\t\t\t|                    输入进货货物单位:                 |");
					printf("\n\t\t\t|———————————————————————————|\n\t\t\t");
					getchar();
					gets(tem_cargos.cargo_unit);
					for (i = 0; i < P; i++)
					{
						if (strcmp(tem_cargos.cargo_name, cargos[i].cargo_name) == 0)
						{
							cargos[i].cargo_quantity += tem_cargos.cargo_quantity;
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						for (i = 0; i < P; i++)
						{
							if (strcmp(cargos[i].cargo_name, "") == 0)
							{
								cargos [i] = tem_cargos;
								break;
							}
						}
					}
					filesave();
				}
				else
				{
					printf("\n\n\n\t\t\t|———————————————————————————|\n");
					printf("\t\t\t|                  该货品不在采购清单内。              |");
					printf("\n\t\t\t|———————————————————————————|\n\t\t\t");

					printf("\t\t\t\n");
					goto here2;
				}
			}
			else if (sel == 2)
			{
				admin_menu();
			}
		}
	}

	// 释放内存并关闭文件
	free(buffer);
	fclose(fp);
}