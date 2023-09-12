// ������ת��
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

// KMPƥ��
int KMPSearch(char* pattern, char* text)
{
	int pattern_length = strlen(pattern);
	int text_length = strlen(text);

	// ������ת��
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
			return 1; // ƥ��ɹ�
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
	return 0; // ƥ��ʧ��
}

void stock_cargos()
{
	fileread();
	system("cls");
	int i, sel;
	struct cargo tem_cargos;

	FILE* fp = fopen("./�ɹ��嵥.txt", "r");
	if (fp == NULL)
	{
		printf("�޷���ȡ�ļ���\n");
		exit(0);
	}

	// ��ȡ�ļ���С
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	// ��̬�����ַ�����
	char* buffer = (char*)malloc((file_size + 1) * sizeof(char));
	if (buffer == NULL)
	{
		printf("�ڴ����ʧ�ܡ�\n");
		exit(0);
	}

	// ���ַ���ȡ���洢��������
	int j = 0;
	int c;
	while ((c = fgetc(fp)) != EOF)
	{
		buffer[j++] = c;
	}
	buffer[j] = '\0';

	// �����������
	// printf("��ȡ������Ϊ��\n");
	// printf("%s\n", buffer);

	printf("\t\t\t***************** ��ӭ�����ֿ����ϵͳ *****************\n\n\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                        ��������                      |\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\n");
here2:
	for (i = 0; i < P; i++)
	{
		if (strcmp(cargos[i].cargo_name, "") == 0)
		{
			printf("\t\t\t|������������������������������������������������������|\n");
			printf("\t\t\t|                �����������ѡ�����Ĳ���:             |\n");
			printf("\t\t\t|������������������������������������������������������|\n");
			printf("\t\t\t|                 1   ����                             |\n");
			printf("\t\t\t|------------------------------------------------------|\n");
			printf("\t\t\t|                 2   �˳���������                     |\n");
			printf("\t\t\t|������������������������������������������������������|\n");
			printf("\t\t\t|                 ����������ѡ��1-2����              |\n");
			printf("\t\t\t|������������������������������������������������������|\n\t\t\t");
			scanf("%d", &sel);

			while (sel != 1 && sel != 2)
			{
				printf("\t\t\t|������������������������������������������������������|\n");
				printf("\t\t\t|                 ����������ѡ��1-2����              |");
				printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
				scanf("%d", &sel);
			}

			if (sel == 1)
			{
				int flag = 0;
				printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
				printf("\t\t\t|                    ���������������:                 |");
				printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
				scanf("%s", tem_cargos.cargo_name);

				// ʹ��KMP����ƥ��
				int match = KMPSearch(tem_cargos.cargo_name, buffer);
				if (match)
				{
					printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
					printf("\t\t\t|                    ���������������:                 |");
					printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
					scanf("%d", &tem_cargos.cargo_quantity);
					printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
					printf("\t\t\t|                    ����������ﵥλ:                 |");
					printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
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
					printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
					printf("\t\t\t|                  �û�Ʒ���ڲɹ��嵥�ڡ�              |");
					printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");

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

	// �ͷ��ڴ沢�ر��ļ�
	free(buffer);
	fclose(fp);
}