void salesrecords()
{
	fileread();
	system("cls");
	int i;
	printf("\t\t\t*********************** ��ӭ�����ֿ����ϵͳ ***********************\n\n\n");
	printf("\t\t\t|-----------------------------------------------------------------|\n");
	printf("\t\t\t|                         ���ۼ�¼��ѯ����                        |\n");
	printf("\t\t\t|-----------------------------------------------------------------|\n");
	printf("\n");
	printf("\n\n\n\t\t\t|-----------------------------------------------------------------|\n");
	printf("\t\t\t|                    �òֿ⵱ǰ���ۻ����б�����:                  |\n");
	printf("\t\t\t|-----------------------------------------------------------------|\n");
	printf("\t\t\t| %-14s","���");
	printf("%-10s","��������");
	printf("%-10s","�۳�����");
	printf("%-10s","���۵�λ");
	printf("%-9s","������ַ");
	printf("%-11s|", "�ۻ�ԱID");

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
