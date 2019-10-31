#include <stdio.h>
#include <Windows.h>
#define MAXSIZE 84998//定义最大个数(VS2019通过测试)

int p,fen,ms,fq;
char buffer[MAXSIZE];

int BPM(int i) //计算拍数，p
{
	if (buffer[i + 1] >= '0' && buffer[i + 1] <= '9') {
		p = (buffer[i + 1] - '0') * 100;
	}
	if (buffer[i + 2] >= '0' && buffer[i + 2] <= '9') {
		p = p + (buffer[i + 2] - '0') * 10;
	}
	if (buffer[i + 3] >= '0' && buffer[i + 3] <= '9') {
		p = p + (buffer[i + 3] - '0');
	}
	p = p * 1000;
	return(1);
}

int TIME(int i)//通过拍数 p ，计算实际毫秒数 ms  
{
	if (buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
	{
		fen = (buffer[i + 1] - '0') * 10;
	}
	if (buffer[i + 2] >= '0' && buffer[i + 2] <= '9')
	{
		fen = fen + (buffer[i + 2] - '0');
	}
	if (fen == 1) ms = p / 60;//全音符
	if (fen == 2) ms = p / 120;//2分音符
	if (fen == 4) ms = p / 240;//4分音符
	if (fen == 6) ms = (p / 120) + (p / 240);//6分音符
	if (fen == 8) ms = p / 480;//8分音符
	if (fen == 16) ms = p / 960;//16分音符
	return(1);

}
int FQ(int i)//频率
{
	if (buffer[i + 3] == 'C') {
		if (buffer[i + 4] == '1') fq = 130;
		if (buffer[i + 4] == '2') fq = 261;
		if (buffer[i + 4] == '3') fq = 523;
		if (buffer[i + 4] == '4') fq = 1046;
		if (buffer[i + 4] == '5') fq = 2093;
			if (buffer[i + 4] == '#') {
				if (buffer[i + 5] == '1') fq = 138;
				if (buffer[i + 5] == '2') fq = 227;
				if (buffer[i + 5] == '3') fq = 554;
				if (buffer[i + 5] == '4') fq = 1108;
				if (buffer[i + 5] == '5') fq = 2217;
			}

	}
		if (buffer[i + 3] == 'D') {
			if (buffer[i + 4] == '1') fq = 147;
			if (buffer[i + 4] == '2') fq = 294;
			if (buffer[i + 4] == '3') fq = 587;
			if (buffer[i + 4] == '4') fq = 1175;
			if (buffer[i + 4] == '5') fq = 2349;
			if (buffer[i + 4] == '#') {
				if (buffer[i + 5] == '1') fq = 155;
				if (buffer[i + 5] == '2') fq = 311;
				if (buffer[i + 5] == '3') fq = 622;
				if (buffer[i + 5] == '4') fq = 1244;
				if (buffer[i + 5] == '5') fq = 2489;
			}

	}

	if (buffer[i + 3] == 'E') {
		if (buffer[i + 4] == '1') fq = 164;
		if (buffer[i + 4] == '2') fq = 327;
		if (buffer[i + 4] == '3') fq = 659;
		if (buffer[i + 4] == '4') fq = 1318;
		if (buffer[i + 4] == '5') fq = 2637;
	}

	if (buffer[i + 3] == 'F') {
		if (buffer[i + 4] == '1') fq = 174;
		if (buffer[i + 4] == '2') fq = 349;
		if (buffer[i + 4] == '3') fq = 698;
		if (buffer[i + 4] == '4') fq = 1396;
		if (buffer[i + 4] == '5') fq = 2793;
			if (buffer[i + 4] == '#') {
				if (buffer[i + 5] == '1') fq = 185;
				if (buffer[i + 5] == '2') fq = 369;
				if (buffer[i + 5] == '3') fq = 740;
				if (buffer[i + 5] == '4') fq = 1480;
				if (buffer[i + 5] == '5') fq = 2960;
			}
			i = i + 4;
	}

	if (buffer[i + 3] == 'G') {
		if (buffer[i + 4] == '1') fq = 196;
		if (buffer[i + 4] == '2') fq = 392;
		if (buffer[i + 4] == '3') fq = 783;
		if (buffer[i + 4] == '4') fq = 1568;
		if (buffer[i + 4] == '5') fq = 3136;
			if (buffer[i + 4] == '#') {
				if (buffer[i + 5] == '1') fq = 207;
				if (buffer[i + 5] == '2') fq = 415;
				if (buffer[i + 5] == '3') fq = 830;
				if (buffer[i + 5] == '4') fq = 1661;
				if (buffer[i + 5] == '5') fq = 3322;
			}

	}
	if (buffer[i + 3] == 'A') {
		if (buffer[i + 4] == '1') fq = 220;
		if (buffer[i + 4] == '2') fq = 440;
		if (buffer[i + 4] == '3') fq = 880;
		if (buffer[i + 4] == '4') fq = 1760;
		if (buffer[i + 4] == '5') fq = 3520;
			if (buffer[i + 4] == '#') {
				if (buffer[i + 5] == '1') fq = 223;
				if (buffer[i + 5] == '2') fq = 466;
				if (buffer[i + 5] == '3') fq = 932;
				if (buffer[i + 5] == '4') fq = 1864;
				if (buffer[i + 5] == '5') fq = 3729;
			}

	}
	if (buffer[i + 3] == 'B') {
		if (buffer[i + 4] == '1') fq = 246;
		if (buffer[i + 4] == '2') fq = 493;
		if (buffer[i + 4] == '3') fq = 987;
		if (buffer[i + 4] == '4') fq = 1975;
		if (buffer[i + 4] == '5') fq = 3951;
	}
	if (buffer[i + 3] == 'S') Sleep(ms);
	i = i + 4;
	return(1);
}

int main(int argc, char const* argv[]) {
	FILE* fp;
	fopen_s(&fp, "argv[1]'", "r");
	if (fp == NULL) {
		printf("不能打开 \n");
		exit(1);
	}

	while (!feof(fp))//循环读取每一行，直到文件尾
	{
		fgets(buffer, MAXSIZE, fp);//将fp所指向的文件一行内容读到缓冲区
		size_t j=0;
		while (buffer[j] != '\0')//求数组结尾
		{
			j++;
		}
		for (size_t i = 0; i < j-2; i++) {
			if (buffer[i] == 'P') {//判断 P 的位置，向下3个元素
				BPM(i);
			}
			i = i + 4;
			if (buffer[i] == ' ') {//判断 “空格” 的位置，向下2个元素
				TIME(i);
			}
			
			FQ(i);
			Beep(fq, ms);
			Sleep(3);
			fq = 0, ms = 0;
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
