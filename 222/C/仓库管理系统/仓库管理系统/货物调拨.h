void sold_cargos()
{
	fileread();
	system("cls");
	int i, j, sel;
	struct cargoSold tem_cargosSold;
	printf("\n");
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t|                    散哭栖欺��弁孔嬬                  |\n");
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t|              乎花垂輝念辛弁歯麗双燕泌和:             |\n");
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t|      %-16s", "園催");
	printf("%-10s", "歯麗兆各");
	printf("%-10s", "垂贋方楚");
	printf("%-10s  |", "潮範汽了");
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
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t");

there:
	printf("\n\n\n");
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t|                俊和栖萩写偬僉夲艇議荷恬:             |\n");
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t|                 1   野亟��弁芝村                     |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 2   曜竃��弁孔嬬                     |\n");
	printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
	printf("\t\t\t|                 萩補秘艇議僉夲‐1-2／��              |");
	printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
	scanf("%d", &sel);

	while (sel != 1 && sel != 2)
	{
		printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		printf("\t\t\t|          補秘危列,萩嶷仟補秘艇議僉夲‐1-2／��        |");
		printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
		scanf("%d", &sel);
	}

	if (sel == 1)
	{
		int flag = 0;
		printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		printf("\t\t\t|                    補秘弁竃歯麗兆各:                 |");
		printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
		scanf("%s", tem_cargosSold.cargoSold_name);
		printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		printf("\t\t\t|                    補秘弁竃歯麗方楚:                 |");
		printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
		scanf("%d", &tem_cargosSold.cargoSold_quantity);
		printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		printf("\t\t\t|                    補秘弁竃歯麗仇峽:                 |");
		printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
		scanf("%s", tem_cargosSold.cargoSold_place);

		printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		printf("\t\t\t|                    補秘弁竃歯麗園催:                 |");
		printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
		scanf("%s", tem_cargosSold.cargoSold_id);

		printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		printf("\t\t\t|                    補秘弁竃岼垢ID:                   |");
		printf("\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n\t\t\t");
		scanf("%s", tem_cargosSold.user_id);
		for (i = 0; i < P; i++)
		{
			if (strcmp(tem_cargosSold.cargoSold_name, cargos[i].cargo_name) == 0)
			{
				if (tem_cargosSold.cargoSold_quantity > cargos[i].cargo_quantity)
				{
					printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
					printf("\t\t\t|                 輝念垂贋音怎,云肝��弁払移             |\n");
					printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
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
			printf("\n\n\n\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
			printf("\t\t\t|                   乎花垂短嗤宸嶽歯麗!                |\n");
			printf("\t\t\t|！！！！！！！！！！！！！！！！！！！！！！！！！！！|\n");
		}
		filesave();
		goto there;
	}
	else if (sel == 2)
	{
		admin_menu();
	}
}