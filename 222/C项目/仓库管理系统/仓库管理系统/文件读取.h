#include <stdio.h>
#include <stdlib.h>

void fileread(){
	FILE *fp;
	fp=fopen("ϵͳ����Ա.txt","r+");
	if(fp==NULL){
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fread(admins,sizeof(struct admin),M,fp);
	fclose(fp);

	FILE *fq;
	fq=fopen("��ͨ����Ա.txt","r+");
	if(fq==NULL){
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fread(users,sizeof(struct user),N,fq);
	fclose(fq);

	FILE* fsu;
	fsu = fopen("��Ӧ��.txt", "r+");
	if (fsu == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fread(suppliers, sizeof(struct supplier), N, fsu);
	fclose(fsu);

	FILE *fz;
	fz=fopen("����.txt","r+");
	if(fz==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fread(cargos,sizeof(struct cargo),P,fz);
	fclose(fz);

	FILE *fs;
	fs=fopen("���ۼ�¼.txt","r+");
	if(fs==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fread(cargoSolds,sizeof(struct cargoSold),P,fs);
	fclose(fs);

	printf("\t\t\t��ȡ�ļ��ɹ���\n");
}
