void filesave()
{
	FILE *fp;
	fp=fopen("ϵͳ����Ա.txt","w");
	if(fp==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fwrite(admins,sizeof(struct admin),M,fp);
	fclose(fp);

	FILE *fq;
	fq=fopen("��ͨ����Ա.txt","w+");
	if(fq==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fwrite(users,sizeof(struct user),N,fq);
	fclose(fq);

	FILE* fsu;
	fsu = fopen("��Ӧ��.txt", "w+");
	if (fsu == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fwrite(suppliers, sizeof(struct supplier), N, fsu);
	fclose(fsu);

	FILE *fz;
	fz=fopen("����.txt","w+");
	if(fz==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fwrite(cargos,sizeof(struct cargo),P,fz);
	fclose(fz);

	FILE *fs;
	fs=fopen("���ۼ�¼.txt","w+");
	if(fs==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fwrite(cargoSolds,sizeof(struct cargoSold),P,fs);
	fclose(fs);

	printf("\n\n\n\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                     ��Ϣ����ɹ���                   |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
}
