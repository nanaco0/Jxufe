void show_supplier()
{
	fileread();
	system("cls");
	int i;
	printf("\t\t\t***************** 欢迎来到仓库管理系统 *****************\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                    供应商管理功能                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\n\n\n");
	printf("\t\t\t|---------------------------------------------------------------------------------------------------------------|\n");
	printf("\t\t\t|                                             该仓库供应商名单如下:                                             |\n");
	printf("\t\t\t|---------------------------------------------------------------------------------------------------------------|\n");
	printf("\t\t\t| %-14s", "编号");
	printf("%-30s", "名称");
	printf("%-16s", "手机号");
	printf("%-50s|", "地址");

	printf("\n");

	for (i = 0; i < P; i++)
	{
		if (strcmp(suppliers[i].supplier_name, "") != 0)
		{
			printf("\t\t\t| %-14s", suppliers[i].supplier_id);
			printf("%-30s", suppliers[i].supplier_name);
			printf("%-16s", suppliers[i].supplier_phone);
			printf("%-50s|", suppliers[i].supplier_address);
			printf("\n");
		}
		else
		{
			break;
		}
	}
	printf("\t\t\t|---------------------------------------------------------------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
}