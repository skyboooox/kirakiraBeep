#include <stdio.h>
#include <Windows.h>
#include "scale.h"

int qu, er, si, liu, ba, sl;
int BPM(int p) {
	qu = p / 60;//全音符
	er = qu / 2;//2分音符 
	si = er / 2;//4分音符
	liu = er + si;//6分音符
	ba = si / 2;//8分音符
	sl = ba / 2;//16分音符
	return p;
}

int main(){
	int p = 60;
	BPM(p * 1000);

	FILE* fp;
	char buffer[1000];
	fopen_s(&fp, "新建文本文档.txt", "r");
	if (fp == NULL)
	{
		printf("不能打开 \n");
		exit(1);
	}

	while (!feof(fp))//循环读取每一行，直到文件尾
	{
		fgets(buffer, 1000, fp);//将fp所指向的文件一行内容读到缓冲区
		printf("%s\n", buffer);//输出所读到的内容
		for (size_t j = 0; buffer[j] == '\0'; j++)
		for (size_t i = 0; i<j; i++)
		{
			if (buffer[i] == 'P') {

			}
			
			printf("%d\n", i);
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
