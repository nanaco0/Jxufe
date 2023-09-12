void salesrecords()
{
	fileread();
	system("cls");
	int i;
	printf("\t\t\t*********************** 欢迎来到仓库管理系统 ***********************\n\n\n");
	printf("\t\t\t|-----------------------------------------------------------------|\n");
	printf("\t\t\t|                         销售记录查询功能                        |\n");
	printf("\t\t\t|-----------------------------------------------------------------|\n");
	printf("\n");
	printf("\n\n\n\t\t\t|-----------------------------------------------------------------|\n");
	printf("\t\t\t|                    该仓库当前已售货物列表如下:                  |\n");
	printf("\t\t\t|-----------------------------------------------------------------|\n");
	printf("\t\t\t| %-14s","编号");
	printf("%-10s","货物名称");
	printf("%-10s","售出数量");
	printf("%-10s","销售单位");
	printf("%-9s","售往地址");
	printf("%-11s|", "售货员ID");

	printf("\n");

	for(i=0; i<P; i++)
	{
		if(strcmp(cargoSolds[i].cargoSold_name,"")!=0)
		{
			printf("\t\t\t| %-14s", cargoSolds[i].cargoSold_id);
			printf("%-10s",cargoSolds[i].cargoSold_name);
			printf("%-10d",cargoSolds[i].cargoSold_quantity);
			printf("%-10s",cargoSolds[i].cargoSold_unit);
			printf("%-9s", cargoSolds[i].cargoSold_place);
			printf("%-11s|", cargoSolds[i].user_id);
			printf("\n");
		}
		else
			break;
	}
	printf("\t\t\t|-----------------------------------------------------------------|\n");

	printf("\t\t\t");
	system("pause");
}
