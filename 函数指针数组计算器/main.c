#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void menu() {
	printf("1.�ӷ�\n2.����\n3.�˷�\n4.����\n0.�˳�\n");
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
		
		printf("��ѡ��:>");
		scanf("%d", &input);
		fflush(stdin);//���淶
		if (input < 0 || input>4) {
			printf("������ѡ��\n");
			continue;
		}
		else if (0 == input) {
			printf("�ټ�\n");
			break;
		}
		printf("��������������,(num1,num2)>");
		scanf("%d,%d", &x, &y);
		fflush(stdin);//���淶
		result=dotable[input-1](&x, &y);
		printf("�����%d\n", result);
	} while (1);
}