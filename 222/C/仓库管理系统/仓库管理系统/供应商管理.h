void show_supplier()
{
	fileread();
	system("cls");
	int i;
	printf("\t\t\t***************** ��ӭ�����ֿ����ϵͳ *****************\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                    ��Ӧ�̹�����                    |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\n\n\n");
	printf("\t\t\t|---------------------------------------------------------------------------------------------------------------|\n");
	printf("\t\t\t|                                             �òֿ⹩Ӧ����������:                                             |\n");
	printf("\t\t\t|---------------------------------------------------------------------------------------------------------------|\n");
	printf("\t\t\t| %-14s", "���");
	printf("%-30s", "����");
	printf("%-16s", "�ֻ���");
	printf("%-50s|", "��ַ");

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