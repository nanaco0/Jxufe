#pragma once
void defaultSort()
{
	system("cls");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|              �òֿ⵱ǰ�����嵥�б�����:             |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|      %-16s", "���");
	printf("%-10s", "��������");
	printf("%-10s", "�������");
	printf("%-10s  |", "Ĭ�ϵ�λ");
	printf("\n");
	int i;
	int count = 0, sum = 0;
	struct cargo temp[P]; // ��ʱ�������ڴ洢������

	// ����ԭ���鵽��ʱ����
	for (i = 0; i < P; i++)
	{
		if (strcmp(cargos[i].cargo_name, "") != 0)
		{
			temp[count] = cargos[i];
			count++;

			// �ۼӿ���������ܺ�
			sum += cargos[i].cargo_quantity;
		}
		else
			break;
	}

	// ����ʱ�����������
	// �������ʹ�����������㷨������ð�����򡢿��������
	// ������谴����������
	int j;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (strcmp(temp[j].cargo_id, temp[j + 1].cargo_id) > 0)
			{
				// �������������λ��
				struct cargo tmp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tmp;
			}
		}
	}

	// ��������Ľ��
	for (i = 0; i < count; i++)
	{
		printf("\t\t\t|      %-16s", temp[i].cargo_id);
		printf("%-10s", temp[i].cargo_name);
		printf("%-10d", temp[i].cargo_quantity);
		printf("%-10s  |", temp[i].cargo_unit);
		printf("\n");
	}

	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|         ����Ʒ����: %-8d", count);
	printf("�ܿ������: %-8d     |", sum);
	printf("\n");
	printf("\t\t\t|------------------------------------------------------|\n");

	printf("\t\t\t");
	system("pause");
}

void quantitySort()
{
	system("cls");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|              �òֿ⵱ǰ�����嵥�б�����:             |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|      %-16s", "���");
	printf("%-10s", "��������");
	printf("%-10s", "�������");
	printf("%-10s  |", "Ĭ�ϵ�λ");
	printf("\n");
	int i;
	int count = 0, sum = 0;
	struct cargo temp[P]; // ��ʱ�������ڴ洢������

	// ����ԭ���鵽��ʱ����
	for (i = 0; i < P; i++)
	{
		if (strcmp(cargos[i].cargo_name, "") != 0)
		{
			temp[count] = cargos[i];
			count++;

			// �ۼӿ���������ܺ�
			sum += cargos[i].cargo_quantity;
		}
		else
			break;
	}

	// ����ʱ�����������
	// �������ʹ�����������㷨������ð�����򡢿��������
	// ������谴�����������
	int j;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (temp[j].cargo_quantity > temp[j + 1].cargo_quantity)
			{
				// �������������λ��
				struct cargo tmp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tmp;
			}
		}
	}

	// ��������Ľ��
	for (i = 0; i < count; i++)
	{
		printf("\t\t\t|      %-16s", temp[i].cargo_id);
		printf("%-10s", temp[i].cargo_name);
		printf("%-10d", temp[i].cargo_quantity);
		printf("%-10s  |", temp[i].cargo_unit);
		printf("\n");
	}

	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|         ����Ʒ����: %-8d", count);
	printf("�ܿ������: %-8d     |", sum);
	printf("\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
}

void idSort()
{
	system("cls");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|              �òֿ⵱ǰ�����嵥�б�����:             |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|      %-16s", "���");
	printf("%-10s", "��������");
	printf("%-10s", "�������");
	printf("%-10s  |", "Ĭ�ϵ�λ");
	printf("\n");
	int i;
	int count = 0, sum = 0;
	struct cargo temp[P]; // ��ʱ�������ڴ洢������

	// ����ԭ���鵽��ʱ����
	for (i = 0; i < P; i++)
	{
		if (strcmp(cargos[i].cargo_name, "") != 0)
		{
			temp[count] = cargos[i];
			count++;

			// �ۼӿ���������ܺ�
			sum += cargos[i].cargo_quantity;
		}
		else
			break;
	}

	// ����ʱ�����������
	// �������ʹ�����������㷨������ð�����򡢿��������
	// ������谴�����������
	int j;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (temp[j].cargo_id > temp[j + 1].cargo_id)
			{
				// �������������λ��
				struct cargo tmp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = tmp;
			}
		}
	}

	// ��������Ľ��
	for (i = 0; i < count; i++)
	{
		printf("\t\t\t|      %-16s", temp[i].cargo_id);
		printf("%-10s", temp[i].cargo_name);
		printf("%-10d", temp[i].cargo_quantity);
		printf("%-10s  |", temp[i].cargo_unit);
		printf("\n");
	}

	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|         ����Ʒ����: %-8d", count);
	printf("�ܿ������: %-8d     |", sum);
	printf("\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t");
	system("pause");
}

void printCargo()
{
	system("cls");
	int i, sel;
	printf("\t\t\t***************** ��ӭ�����ֿ����ϵͳ *****************\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                    ��ѡ�����Ĳ���:                   |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                    ��ʾ��湦��                      |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  1   Ĭ������                        |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  2   ����Ʒ�������                  |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  3   �������������                  |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                  4   ������һ���˵�                  |\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	
	printf("\n\n\n");
	printf("\t\t\t|------------------------------------------------------|\n");
	printf("\t\t\t|                 ����������ѡ��1-4����              |\n");
	printf("\t\t\t|------------------------------------------------------|\n\t\t\t");
	scanf("%d", &sel);
	getchar();
	while (sel < 1 || sel > 4)
	{
		printf("\t\t\t|------------------------------------------------------|\n");
		printf("\t\t\t|          �������,��������������ѡ��1-2����        |\n");
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
