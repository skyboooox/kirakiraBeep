#include <stdio.h>
#include <Windows.h>
#define C 523.25
#define D 622
#define E 682
#define F 740
#define G 831
#define A 932
#define B 1046

int qu, er, si, liu, ba, sl;
float a[9][12];

int BPM(int p) {
	qu = p / 60;//全音符
	er = qu / 2;//2分音符 
	si = er / 2;//4分音符
	liu = er + si;//6分音符
	ba = si / 2;//8分音符
	sl = ba / 2;//16分音符
	return p;
}

//int yin(){
//	a[0][0]=16.352;
//	for(int i=0;i<9;i++){
//		for(int p=1;i<12;p++){
//			a[i][p]=a[i][p-1]*1.059533;
//		}
//	}
//	return 0;
//}
int main() {
	int p = 60;
	BPM(p * 1000);

	Beep(C, si);
	Beep(C, si);
	Beep(G, si);
	Beep(G, si);
	Beep(A, si);
	Beep(A, si);
	Beep(G, er);
	//Beep(D,500);
	//Beep(E,500);
	//Beep(F,500);
	//Beep(G,500);
	//Beep(A,500);
	//Beep(B,500);
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
