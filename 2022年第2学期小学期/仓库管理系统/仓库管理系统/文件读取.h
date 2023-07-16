#include <stdio.h>
#include <stdlib.h>

void fileread(){
	FILE *fp;
	fp=fopen("系统管理员.txt","r+");
	if(fp==NULL){
		printf("文件打开失败\n");
		exit(0);
	}
	fread(admins,sizeof(struct admin),M,fp);
	fclose(fp);

	FILE *fq;
	fq=fopen("普通操作员.txt","r+");
	if(fq==NULL){
		printf("文件打开失败\n");
		exit(0);
	}
	fread(users,sizeof(struct user),N,fq);
	fclose(fq);

	FILE* fsu;
	fsu = fopen("供应商.txt", "r+");
	if (fsu == NULL) {
		printf("文件打开失败\n");
		exit(0);
	}
	fread(suppliers, sizeof(struct supplier), N, fsu);
	fclose(fsu);

	FILE *fz;
	fz=fopen("货物.txt","r+");
	if(fz==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fread(cargos,sizeof(struct cargo),P,fz);
	fclose(fz);

	FILE *fs;
	fs=fopen("销售记录.txt","r+");
	if(fs==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fread(cargoSolds,sizeof(struct cargoSold),P,fs);
	fclose(fs);

	printf("\t\t\t读取文件成功！\n");
}
