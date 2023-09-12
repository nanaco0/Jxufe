void filesave()
{
	FILE *fp;
	fp=fopen("系统管理员.txt","w");
	if(fp==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fwrite(admins,sizeof(struct admin),M,fp);
	fclose(fp);

	FILE *fq;
	fq=fopen("普通操作员.txt","w+");
	if(fq==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fwrite(users,sizeof(struct user),N,fq);
	fclose(fq);

	FILE* fsu;
	fsu = fopen("供应商.txt", "w+");
	if (fsu == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fwrite(suppliers, sizeof(struct supplier), N, fsu);
	fclose(fsu);

	FILE *fz;
	fz=fopen("货物.txt","w+");
	if(fz==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fwrite(cargos,sizeof(struct cargo),P,fz);
	fclose(fz);

	FILE *fs;
	fs=fopen("销售记录.txt","w+");
	if(fs==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fwrite(cargoSolds,sizeof(struct cargoSold),P,fs);
	fclose(fs);

	printf("\n\n\n\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                     信息保存成功！                   |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
}
