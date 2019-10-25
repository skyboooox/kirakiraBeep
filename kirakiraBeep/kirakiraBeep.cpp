#include <stdio.h>
#include <Windows.h>
#include "scale.h"
#define MAXSIZE 84998//定义最大个数(VS2019通过测试)

int i,j,p,fen,ms;
char buffer[MAXSIZE];

int BPM() {//计算排数，p
	if (buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
	{
		p = (buffer[i + 1] - '0') * 100;
	}
	if (buffer[i + 2] >= '0' && buffer[i + 2] <= '9')
	{
		p = p + (buffer[i + 2] - '0') * 10;
	}
	if (buffer[i + 3] >= '0' && buffer[i + 3] <= '9')
	{
		p = p + (buffer[i + 3] - '0');
	}
	p = p * 1000;
}
int FQ() {//通过排数 p ，计算实际毫秒数 ms 
	if (buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
	{
		fen = (buffer[i + 1] - '0') * 10;
	}
	if (buffer[i + 2] >= '0' && buffer[i + 2] <= '9')
	{
		fen = p + (buffer[i + 2] - '0');
	}
	if (fen = 1) ms = p / 60;//全音符
	if (fen = 2) ms = p / 120;//2分音符
	if (fen = 4) ms = p / 240;//4分音符
	if (fen = 6) ms = (p / 120) + (p / 240);//6分音符
	if (fen = 8) ms = p / 480;//8分音符
	if (fen = 16) ms = p / 960;//16分音符

}
int main(){
	FILE* fp;
	fopen_s(&fp, "新建文本文档.txt", "r");
	if (fp == NULL)
	{
		printf("不能打开 \n");
		exit(1);
	}

	while (!feof(fp))//循环读取每一行，直到文件尾
	{
		fgets(buffer, 1000, fp);//将fp所指向的文件一行内容读到缓冲区
		while (buffer[j] != '\0')//求数组结尾
		{
			j++;
		}
		for (size_t i = 0; i<j; i++)
		{
			if (buffer[i] == 'P') {//判断 P 的位置，向下3个元素
				BPM();
			}
			if (buffer[i] == ' ') {//判断 “空格” 的位置，向下2个元素
				FQ();
		}

	}


	fclose(fp);
	

	return 0;
}


//blog.csdn.net/lynch0571/article/details/33329151
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
