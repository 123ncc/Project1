#include <stdio.h>
#include <stdlib.h>
#include<time.h>

///����ԭ��
int count;///������Ŀ����
int max;///�����������
int getChoice();
void Menu();
int test(int);

/*
�û�ѡ����
�����û��Ĺ���ѡ��
choice=1��ʾ�ӷ���2��ʾ������3��ʾ�˷���4��ʾ������0��ʾ�˳�
*/
int getChoice()
{
	int choice;
	scanf("%d", &choice);
	return choice;
}

/*
��ʾ���ܲ˵�
*/
void Menu()
{
	printf("===================================\n");
	printf("\n��ӭʹ��Сѧ������������ϰ���\n");
	printf("\t1���ӷ���ϰ\t2��������ϰ\n");
	printf("\t3���˷���ϰ\t4��������ϰ\n");
	printf("\t5���ۺ���ϰ\t0���˳�ϵͳ\n");
	printf("��������Ҫ��ӡ��Ŀ������\n");
	scanf("%d", &count);
	printf("��������Ŀ�е�������֣�\n");
	scanf("%d", &max);
	printf("���������ѡ��0--5����\n");
	printf("\n===================================\n");

}

/*
����һ����Ĳ��Թ���
*/
int test(int n)
{
	int ranswer[count];
	int t = 0;                ///��ʱ����
	char operation;            ///�������
	int num1[count];               ///������1
	int num2[count];               ///������2
	srand(time(NULL)); ///��ʼ�����������
	for (int j = 1;j <= 2 * count; j++)
	{
		num1[j] = rand() % max + 1;            ///ȡ0��max֮��������
		num2[j] = rand() % max + 1;
	}
	if (n == 5)      ///��������ܣ����ѡ��5���������1-4�������ÿһ�����㷽ʽ
	{
		n = rand() % 4 + 1;
	}

	switch (n)
	{
	case 1:
		operation = '+';
		break;

	case 2:
		operation = '-';
		break;

	case 3:
		operation = '*';
		break;

	case 4:
		operation = '/';
		break;
	}

	///�ӷ�������������ʱ�򣬽�������������
	for (int i = 1;i <= count;i++)
	{
		if ((operation == '-') && (num1<num2))
		{
			t = num1[i];
			num1[i] = num2[i];
			num2[i] = t;
		}

		///���������У���������num2Ϊ0ʱ�ͽ�num2ǿ����Ϊ1
		///��num1��ֵ��ֵ��num1*num2����ֹ��������
		if (operation == '/')
		{
			if (num2[i] == 0)
			{
				num2[i] = 1;
			}
			num1[i] = num1[i] * num2[i];        ///��ֹnum1���ܱ�num2���������
		}

		printf("%d%c%d= \n", num1[i], operation, num2[i]);
	}
	///���㲢������ȷ��
	printf("��ȷ��Ϊ�� \n");
	for (i = 1;i <= count;i++)
	{
		switch (operation)
		{
		case '+':
			ranswer[i] = num1[i] + num2[i];
			break;

		case '-':
			ranswer[i] = num1[i] - num2[i];
			break;

		case '*':
			ranswer[i] = num1[i] * num2[i];
			break;

		case '/':
			ranswer[i] = num1[i] / num2[i];
			break;
		}
		printf("%d  \n", ranswer[i]);
	}
}

///������
int main(void)
{
	int choice = 0;        ///�����û���ѡ��
	do      ///ѭ����ʼ����
	{
		Menu();                  ///��ʾ�˵�
		choice = getChoice();
		///����choice�ķ�Χ
		if (choice<0 || choice>5)
		{
			choice = 1;            ///���������Ų��ڷ�Χ�ڣ�Ĭ�����ӷ�
		}
		if (choice == 0)
		{
			break;                ///�û�ѡ��0���˳�ѭ�����˳�ϵͳ��
		}
		test(choice);
	} while (choice != 0);

	printf("��лʹ�ñ����\n");
	return 0;
}
