#pragma once
void defaultSort()
{
	system("cls");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|              该仓库当前货物清单列表如下:             |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|      %-16s", "编号");
	printf("%-10s", "货物名称");
	printf("%-10s", "库存数量");
	printf("%-10s  |", "默认单位");
	printf("\n");
	int i;
	int count = 0, sum = 0;
	struct cargo temp[P]; // 临时数组用于存储排序结果

	// 复制原数组到临时数组
	for (i = 0; i < P; i++)
	{
		if (strcmp(cargos[i].cargo_name, "") != 0)
		{
			temp[count] = cargos[i];
			count++;

			// 累加库存数量到总和
			sum += cargos[i].cargo_quantity;
		}
		else
			break;
	}

	// 对临时数组进行排序
	// 这里可以使用任意排序算法，例如冒泡排序、快速排序等
	// 这里假设按货物编号排序
	int j;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (strcmp(temp[j].cargo_id, temp[j + 1].cargo_id) > 0)
			{
				// 交换两个货物的位置
				struct cargo tmp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tmp;
			}
		}
	}

	// 输出排序后的结果
	for (i = 0; i < count; i++)
	{
		printf("\t\t\t|      %-16s", temp[i].cargo_id);
		printf("%-10s", temp[i].cargo_name);
		printf("%-10d", temp[i].cargo_quantity);
		printf("%-10s  |", temp[i].cargo_unit);
		printf("\n");
	}

	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|         总商品个数: %-8d", count);
	printf("总库存数量: %-8d     |", sum);
	printf("\n");
	printf("\t\t\t|------------------------------------------------------|\n");

	printf("\t\t\t");
	system("pause");
}

void quantitySort()
{
	system("cls");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|              该仓库当前货物清单列表如下:             |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|      %-16s", "编号");
	printf("%-10s", "货物名称");
	printf("%-10s", "库存数量");
	printf("%-10s  |", "默认单位");
	printf("\n");
	int i;
	int count = 0, sum = 0;
	struct cargo temp[P]; // 临时数组用于存储排序结果

	// 复制原数组到临时数组
	for (i = 0; i < P; i++)
	{
		if (strcmp(cargos[i].cargo_name, "") != 0)
		{
			temp[count] = cargos[i];
			count++;

			// 累加库存数量到总和
			sum += cargos[i].cargo_quantity;
		}
		else
			break;
	}

	// 对临时数组进行排序
	// 这里可以使用任意排序算法，例如冒泡排序、快速排序等
	// 这里假设按库存数量排序
	int j;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (temp[j].cargo_quantity > temp[j + 1].cargo_quantity)
			{
				// 交换两个货物的位置
				struct cargo tmp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tmp;
			}
		}
	}

	// 输出排序后的结果
	for (i = 0; i < count; i++)
	{
		printf("\t\t\t|      %-16s", temp[i].cargo_id);
		printf("%-10s", temp[i].cargo_name);
		printf("%-10d", temp[i].cargo_quantity);
		printf("%-10s  |", temp[i].cargo_unit);
		printf("\n");
	}

	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|         总商品个数: %-8d", count);
	printf("总库存数量: %-8d     |", sum);
	printf("\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
}

void idSort()
{
	system("cls");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|              该仓库当前货物清单列表如下:             |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|      %-16s", "编号");
	printf("%-10s", "货物名称");
	printf("%-10s", "库存数量");
	printf("%-10s  |", "默认单位");
	printf("\n");
	int i;
	int count = 0, sum = 0;
	struct cargo temp[P]; // 临时数组用于存储排序结果

	// 复制原数组到临时数组
	for (i = 0; i < P; i++)
	{
		if (strcmp(cargos[i].cargo_name, "") != 0)
		{
			temp[count] = cargos[i];
			count++;

			// 累加库存数量到总和
			sum += cargos[i].cargo_quantity;
		}
		else
			break;
	}

	// 对临时数组进行排序
	// 这里可以使用任意排序算法，例如冒泡排序、快速排序等
	// 这里假设按库存数量排序
	int j;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (temp[j].cargo_id > temp[j + 1].cargo_id)
			{
				// 交换两个货物的位置
				struct cargo tmp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tmp;
			}
		}
	}

	// 输出排序后的结果
	for (i = 0; i < count; i++)
	{
		printf("\t\t\t|      %-16s", temp[i].cargo_id);
		printf("%-10s", temp[i].cargo_name);
		printf("%-10d", temp[i].cargo_quantity);
		printf("%-10s  |", temp[i].cargo_unit);
		printf("\n");
	}

	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|         总商品个数: %-8d", count);
	printf("总库存数量: %-8d     |", sum);
	printf("\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
}

void printCargo()
{
	system("cls");
	int i, sel;
	printf("\t\t\t***************** 欢迎来到仓库管理系统 *****************\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                    请选择您的操作:                   |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                    显示库存功能                      |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  1   默认排序                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  2   按商品编号排序                  |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  3   按库存数量排序                  |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  4   返回上一级菜单                  |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 请输入您的选择【1-4】：              |\n");
	printf("\t\t\t|------------------------------------------------------|\n\t\t\t");
	scanf("%d", &sel);
	getchar();
	while (sel < 1 || sel > 4)
	{
		printf("\t\t\t|------------------------------------------------------|\n");
		printf("\t\t\t|          输入错误,请重新输入您的选择【1-2】：        |\n");
		printf("\t\t\t|------------------------------------------------------|\n\t\t\t");
		scanf("%d", &sel);
	}

	switch (sel)
	{
	case 1:
		defaultSort();
		break;
	case 2:
		idSort();
		break;
	case 3:
		quantitySort();
		break;
	case 4:
		menu();
	}
}
