#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void menu() {
	printf("1.�ӷ�\n2.����\n3.�˷�\n4.����\n0.�˳�\n");
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
typedef int(*calc)(const int* a, const int* b);//���������з�һ�𣬲�����ע�ͣ���������
calc dotable[] = { my_add,my_sub,my_mul,my_div };//����ָ�����飬�ֽ�ת�Ʊ�
calc* p_dotable = &dotable;//����ָ������ָ�� - ָ�룬���ָ��ָ��һ�����飬������������Ԫ�ض���ָ�룬��Щָ��ָ��Ķ����Ǻ���

void docalc(calc func) {
	int x = 0, y = 0, result = 0;
	printf("��������������,(num1,num2)>");
	scanf("%d,%d", &x, &y);
	fflush(stdin);//���淶
	result = func(&x, &y);
	printf("�����%d\n", result);
	return;
}




int main(void) {
	

	int input = 5,flag=1;

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
		}//���밲ȫ���
		
		docalc(dotable[input-1]);

	} while (flag);
}