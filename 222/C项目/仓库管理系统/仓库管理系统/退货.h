void return_cargos()
{
	fileread();
	system("cls");
	int i, sel,result,j=-1;
	struct cargoSold tem_cargoSolds;
	printf("\t\t\t********************** 欢迎来到仓库管理系统 **********************\n\n\n");
	printf("\t\t\t|------------------------------------------------------------------|\n");
	printf("\t\t\t|                              退货功能                            |\n");
	printf("\t\t\t|------------------------------------------------------------------|\n");

	printf("\n\n\n\t\t\t|------------------------------------------------------------------|\n");
	printf("\t\t\t|                    该仓库当前销售记录列表如下：                  |\n");
	printf("\t\t\t|------------------------------------------------------------------|\n");
	printf("\t\t\t| %-14s", "编号");
	printf("%-10s", "货物名称");
	printf("%-10s", "售出数量");
	printf("%-10s", "销售单位");
	printf("%-10s", "售往地址");
	printf("%-11s|", "售货员ID");

	printf("\n");

	for (i = 0; i < P; i++)
	{
		if (strcmp(cargoSolds[i].cargoSold_name, "") != 0)
		{
			printf("\t\t\t| %-14s", cargoSolds[i].cargoSold_id);
			printf("%-10s", cargoSolds[i].cargoSold_name);
			printf("%-10d", cargoSolds[i].cargoSold_quantity);
			printf("%-10s", cargoSolds[i].cargoSold_unit);
			printf("%-10s", cargoSolds[i].cargoSold_place);
			printf("%-11s|", cargoSolds[i].user_id);
			printf("\n");
		}
		else
			break;
	}
	printf("\t\t\t|------------------------------------------------------------------|\n");

	printf("\n\n\n");

	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                接下来请继续选择您的操作:             |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 1   退货                             |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 2   退出退货功能                     |\n");
	printf("\t\t\t|------------------------------------------------------|\n");


	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 请输入您的选择【1-2】：              |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	scanf("%d", &sel);

	while (sel < 1 || sel>2)
	{
		printf("\n\n\n");
		printf("\t\t\t|------------------------------------------------------|\n");
		printf("\t\t\t|          输入错误,请重新输入您的选择【1-2】：        |\n");
		printf("\t\t\t|------------------------------------------------------|\n");
		scanf("%d", &sel);
	}

	if (sel == 1)
	{
		printf("\n\n\n");
		printf("\t\t\t|------------------------------------------------------|\n");
		printf("\t\t\t|                    输入退货销售单号:                 |\n");
		printf("\t\t\t|------------------------------------------------------|\n");
		getchar();
		gets(tem_cargoSolds.cargoSold_id);

		//验证销售单号合法性
		int flag = 0;
		for (i = 0; i < P; i++)
		{
			if (kmpSearch(cargoSolds[i].cargoSold_id, tem_cargoSolds.cargoSold_id) != -1)
			{
				result = i;
				flag = 1;
				break;
			}
		}

		if (flag == 1) 
		{//输入的销售单号存在
			printf("\n\n\n");
			printf("\t\t\t|------------------------------------------------------|\n");
			printf("\t\t\t|                    输入退货货物名称:                 |\n");
			printf("\t\t\t|------------------------------------------------------|\n");
			scanf("%s",tem_cargoSolds.cargoSold_name);
			for (i = 0; i < P; i++)
			{
				if (kmpSearch(cargos[i].cargo_name, tem_cargoSolds.cargoSold_name) != -1)
				{//验证仓库中是否有该商品
					j = i;
					break;
				}
			}
		
			if (strcmp(cargoSolds[result].cargoSold_name, tem_cargoSolds.cargoSold_name) == 0)
			{//退货单的货物名与输入货物名相等
				if (j > -1)
				{//仓库中有该商品
					printf("\n\n\n");
					printf("\t\t\t|------------------------------------------------------|\n");
					printf("\t\t\t|                    输入退货货物数量:                 |\n");
					printf("\t\t\t|------------------------------------------------------|\n");
					scanf("%d", &tem_cargoSolds.cargoSold_quantity);

					if (cargoSolds[result].cargoSold_quantity < tem_cargoSolds.cargoSold_quantity)
					{//超出销售数量
						printf("\n\n\n");
						printf("\t\t\t|------------------------------------------------------|\n");
						printf("\t\t\t|              超出销售数量,本次退货失败！             |\n");
						printf("\t\t\t|------------------------------------------------------|\n");
					}
					else
					{//不超出销售数量
						if (cargos[j].cargo_quantity < tem_cargoSolds.cargoSold_quantity)
						{//库存不足
							printf("\n\n\n");
							printf("\t\t\t|------------------------------------------------------|\n");
							printf("\t\t\t|              当前库存不足,本次退货失败 ！            |\n");
							printf("\t\t\t|------------------------------------------------------|\n");
						}
						else
						{//库存充足
							cargos[j].cargo_quantity -= tem_cargoSolds.cargoSold_quantity;
							printf("\n\n\n");
							printf("\t\t\t|------------------------------------------------------|\n");
							printf("\t\t\t|                 退货成功，已更新库存数量             |\n");
							printf("\t\t\t|------------------------------------------------------|\n");
							printf("更新后的数量：%d", cargos[j].cargo_quantity);
							filesave();
							admin_menu();
						}
					}
				}
				else
				{//j == -1,仓库中没有该商品
					printf("\n\n\n");
					printf("\t\t\t|------------------------------------------------------|\n");
					printf("\t\t\t|                   仓库中没有该货物！                 |\n");
					printf("\t\t\t|------------------------------------------------------|\n");
				}
			}
			else 
			{//退货单的货物名与输入货物名不等
				printf("\n\n\n\t\t\t您输入的文件名：%s\n\t\t\t销售记录上的货物名:%s", tem_cargoSolds.cargoSold_name, cargoSolds[result].cargoSold_name);
				printf("\t\t\t|------------------------------------------------------|\n");
				printf("\t\t\t|                   退货货物名称错误！                 |\n");
				printf("\t\t\t|------------------------------------------------------|\n");
			}
		}
		else
		{//输入的销售单号不存在
			printf("\n\n\n");
			printf("\t\t\t|------------------------------------------------------|\n");
			printf("\t\t\t|                   不存在该销售单号!                 |\n");
			printf("\t\t\t|------------------------------------------------------|\n");
		}
	}

	else if (sel == 2)
	{
		admin_menu();
	}

}
