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

int main(int argc, char const* argv[]){
	int p = 60;
	BPM(p * 1000);

	FILE* fp;

	if (argc != 2)
	{
		printf("使用: %s \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fopen_s(&fp, argv[1], "r")) == NULL)
	{
		printf("不能打开 %s\n", argv[1]);
		exit(1);
	}
	
	fclose(fp);

	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
