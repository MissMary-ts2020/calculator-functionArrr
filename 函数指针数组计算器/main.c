#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void menu() {
	printf("1.加法\n2.减法\n3.乘法\n4.除法\n0.退出\n");
}

int my_add(const int* a, const int* b) {

	return *a + *b;
}
int my_sub(const int* a, const int* b) {

	return *a - *b;
}
int my_mul(const int* a, const int* b) {

	return *a * *b;
}
int my_div(const int* a, const int* b) {

	return *a / *b;
}
typedef int(*calc)(const int* a, const int* b);//尽量这两行放一起，并做好注释，避免歧义
calc dotable[] = { my_add,my_sub,my_mul,my_div };//函数指针数组，又叫转移表
calc* p_dotable = &dotable;//函数指针数组指针 - 指针，这个指针指向一个数组，这个数组里面的元素都是指针，这些指针指向的对象是函数

void docalc(calc func) {
	int x = 0, y = 0, result = 0;
	printf("请输入两个数字,(num1,num2)>");
	scanf("%d,%d", &x, &y);
	fflush(stdin);//不规范
	result = func(&x, &y);
	printf("结果是%d\n", result);
	return;
}




int main(void) {
	

	int input = 5,flag=1;

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
		}//输入安全检查
		
		docalc(dotable[input-1]);

	} while (flag);
}