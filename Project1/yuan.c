#include <stdio.h>
#include <stdlib.h>
#include<time.h>

///函数原型
int count;///定义题目数量
int max;///定义最大数字
int getChoice();
void Menu();
int test(int);

/*
用户选择功能
返回用户的功能选择
choice=1表示加法，2表示减法，3表示乘法，4表示除法，0表示退出
*/
int getChoice()
{
	int choice;
	scanf("%d", &choice);
	return choice;
}

/*
显示功能菜单
*/
void Menu()
{
	printf("===================================\n");
	printf("\n欢迎使用小学生四则运算练习软件\n");
	printf("\t1、加法练习\t2、减法练习\n");
	printf("\t3、乘法练习\t4、除法练习\n");
	printf("\t5、综合练习\t0、退出系统\n");
	printf("请输入需要打印题目数量：\n");
	scanf("%d", &count);
	printf("请输入题目中的最大数字：\n");
	scanf("%d", &max);
	printf("请输入你的选择（0--5）：\n");
	printf("\n===================================\n");

}

/*
进行一道题的测试过程
*/
int test(int n)
{
	int ranswer[count];
	int t = 0;                ///临时变量
	char operation;            ///运算符号
	int num1[count];               ///操作数1
	int num2[count];               ///操作数2
	srand(time(NULL)); ///初始化随机数种子
	for (int j = 1;j <= 2 * count; j++)
	{
		num1[j] = rand() % max + 1;            ///取0—max之间的随机数
		num2[j] = rand() % max + 1;
	}
	if (n == 5)      ///进入程序功能，如果选择5就随机产生1-4所代表的每一种运算方式
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

	///加法操作不够减的时候，交换两个操作数
	for (int i = 1;i <= count;i++)
	{
		if ((operation == '-') && (num1<num2))
		{
			t = num1[i];
			num1[i] = num2[i];
			num2[i] = t;
		}

		///出发操作中，除数，即num2为0时就将num2强制置为1
		///将num1的值赋值给num1*num2，防止不能整除
		if (operation == '/')
		{
			if (num2[i] == 0)
			{
				num2[i] = 1;
			}
			num1[i] = num1[i] * num2[i];        ///防止num1不能被num2整除的语句
		}

		printf("%d%c%d= \n", num1[i], operation, num2[i]);
	}
	///计算并给出正确答案
	printf("正确答案为： \n");
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

///主函数
int main(void)
{
	int choice = 0;        ///接收用户的选择
	do      ///循环开始功能
	{
		Menu();                  ///显示菜单
		choice = getChoice();
		///控制choice的范围
		if (choice<0 || choice>5)
		{
			choice = 1;            ///如果运算符号不在范围内，默认做加法
		}
		if (choice == 0)
		{
			break;                ///用户选择0，退出循环（退出系统）
		}
		test(choice);
	} while (choice != 0);

	printf("感谢使用本软件\n");
	return 0;
}
