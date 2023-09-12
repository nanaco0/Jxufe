void sold_cargos()
{
	fileread();
	system("cls");
	int i, j, sel;
	struct cargoSold tem_cargosSold;
	printf("\n");
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t|                    »¶Ó­À´µ½ÏúÊÛ¹¦ÄÜ                  |\n");
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t|              ¸Ã²Ö¿âµ±Ç°¿ÉÊÛ»õÎïÁÐ±íÈçÏÂ:             |\n");
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t|      %-16s", "±àºÅ");
	printf("%-10s", "»õÎïÃû³Æ");
	printf("%-10s", "¿â´æÊýÁ¿");
	printf("%-10s  |", "Ä¬ÈÏµ¥Î»");
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
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t");

there:
	printf("\n\n\n");
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t|                ½ÓÏÂÀ´Çë¼ÌÐøÑ¡ÔñÄúµÄ²Ù×÷:             |\n");
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t|                 1   ÌîÐ´ÏúÊÛ¼ÇÂ¼                     |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 2   ÍË³öÏúÊÛ¹¦ÄÜ                     |\n");
	printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
	printf("\t\t\t|                 ÇëÊäÈëÄúµÄÑ¡Ôñ¡¾1-2¡¿£º              |");
	printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
	scanf("%d", &sel);

	while (sel != 1 && sel != 2)
	{
		printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		printf("\t\t\t|          ÊäÈë´íÎó,ÇëÖØÐÂÊäÈëÄúµÄÑ¡Ôñ¡¾1-2¡¿£º        |");
		printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
		scanf("%d", &sel);
	}

	if (sel == 1)
	{
		int flag = 0;
		printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		printf("\t\t\t|                    ÊäÈëÊÛ³ö»õÎïÃû³Æ:                 |");
		printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
		scanf("%s", tem_cargosSold.cargoSold_name);
		printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		printf("\t\t\t|                    ÊäÈëÊÛ³ö»õÎïÊýÁ¿:                 |");
		printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
		scanf("%d", &tem_cargosSold.cargoSold_quantity);
		printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		printf("\t\t\t|                    ÊäÈëÊÛ³ö»õÎïµØÖ·:                 |");
		printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
		scanf("%s", tem_cargosSold.cargoSold_place);

		printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		printf("\t\t\t|                    ÊäÈëÊÛ³ö»õÎï±àºÅ:                 |");
		printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
		scanf("%s", tem_cargosSold.cargoSold_id);

		printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		printf("\t\t\t|                    ÊäÈëÊÛ³öÖ°¹¤ID:                   |");
		printf("\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n\t\t\t");
		scanf("%s", tem_cargosSold.user_id);
		for (i = 0; i < P; i++)
		{
			if (strcmp(tem_cargosSold.cargoSold_name, cargos[i].cargo_name) == 0)
			{
				if (tem_cargosSold.cargoSold_quantity > cargos[i].cargo_quantity)
				{
					printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
					printf("\t\t\t|                 µ±Ç°¿â´æ²»×ã,±¾´ÎÏúÊÛÊ§°Ü             |\n");
					printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
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
			printf("\n\n\n\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
			printf("\t\t\t|                   ¸Ã²Ö¿âÃ»ÓÐÕâÖÖ»õÎï!                |\n");
			printf("\t\t\t|¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª|\n");
		}
		filesave();
		goto there;
	}
	else if (sel == 2)
	{
		admin_menu();
	}
}