void sold_cargos()
{
	fileread();
	system("cls");
	int i, j, sel;
	struct cargoSold tem_cargosSold;
	printf("\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                    ��ӭ�������۹���                  |\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|              �òֿ⵱ǰ���ۻ����б�����:             |\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|      %-16s", "���");
	printf("%-10s", "��������");
	printf("%-10s", "�������");
	printf("%-10s  |", "Ĭ�ϵ�λ");
	printf("\n");

	for (i = 0; i < P; i++)
	{
		if (strcmp(cargos[i].cargo_name, "") != 0)
		{
			printf("\t\t\t|      %-16s", cargos[i].cargo_id);
			printf("%-10s", cargos[i].cargo_name);
			printf("%-10d", cargos[i].cargo_quantity);
			printf("%-10s  |", cargos[i].cargo_unit);
			printf("\n");
		}
		else
			break;
	}
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t");

there:
	printf("\n\n\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                �����������ѡ�����Ĳ���:             |\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                 1   ��д���ۼ�¼                     |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 2   �˳����۹���                     |\n");
	printf("\t\t\t|������������������������������������������������������|\n");
	printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
	printf("\t\t\t|                 ����������ѡ��1-2����              |");
	printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
	scanf("%d", &sel);

	while (sel != 1 && sel != 2)
	{
		printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
		printf("\t\t\t|          �������,��������������ѡ��1-2����        |");
		printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
		scanf("%d", &sel);
	}

	if (sel == 1)
	{
		int flag = 0;
		printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
		printf("\t\t\t|                    �����۳���������:                 |");
		printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
		scanf("%s", tem_cargosSold.cargoSold_name);
		printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
		printf("\t\t\t|                    �����۳���������:                 |");
		printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
		scanf("%d", &tem_cargosSold.cargoSold_quantity);
		printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
		printf("\t\t\t|                    �����۳������ַ:                 |");
		printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
		scanf("%s", tem_cargosSold.cargoSold_place);

		printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
		printf("\t\t\t|                    �����۳�������:                 |");
		printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
		scanf("%s", tem_cargosSold.cargoSold_id);

		printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
		printf("\t\t\t|                    �����۳�ְ��ID:                   |");
		printf("\n\t\t\t|������������������������������������������������������|\n\t\t\t");
		scanf("%s", tem_cargosSold.user_id);
		for (i = 0; i < P; i++)
		{
			if (strcmp(tem_cargosSold.cargoSold_name, cargos[i].cargo_name) == 0)
			{
				if (tem_cargosSold.cargoSold_quantity > cargos[i].cargo_quantity)
				{
					printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
					printf("\t\t\t|                 ��ǰ��治��,��������ʧ��             |\n");
					printf("\t\t\t|������������������������������������������������������|\n");
					goto there;
				}
				else
				{
					strcpy(tem_cargosSold.cargoSold_unit, cargos[i].cargo_unit);
					cargos[i].cargo_quantity -= tem_cargosSold.cargoSold_quantity;
					for (j = 0; j < P; j++)
					{
						if (strcmp(cargoSolds[j].cargoSold_name, "") == 0)
						{
							cargoSolds[j] = tem_cargosSold;
							break;
						}
					}
				}
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("\n\n\n\t\t\t|������������������������������������������������������|\n");
			printf("\t\t\t|                   �òֿ�û�����ֻ���!                |\n");
			printf("\t\t\t|������������������������������������������������������|\n");
		}
		filesave();
		goto there;
	}
	else if (sel == 2)
	{
		admin_menu();
	}
}