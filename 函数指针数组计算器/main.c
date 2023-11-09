#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void menu() {
	printf("1.加法\n2.减法\n3.乘法\n4.除法\n0.退出\n");
}

int my_add(int* a, int* b) {

	return *a + *b;
}
int my_sub(int* a, int* b) {

	return *a - *b;
}
int my_mul(int* a, int* b) {

	return *a * *b;
}
int my_div(int* a, int* b) {

	return *a / *b;
}


int main(void) {
	typedef int(*calc)(int*, int*);
	calc dotable[4] = { my_add,my_sub,my_mul,my_div };

	int x = 0, y = 0, input = 5,result=0;
	do {
		menu();
		
		printf("请选择:>");
		scanf("%d", &input);
		fflush(stdin);//不规范
		if (input < 0 || input>4) {
			printf("请重新选择\n");
			continue;
		}
		else if (0 == input) {
			printf("再见\n");
			break;
		}
		printf("请输入两个数字,(num1,num2)>");
		scanf("%d,%d", &x, &y);
		fflush(stdin);//不规范
		result=dotable[input-1](&x, &y);
		printf("结果是%d\n", result);
	} while (1);
}