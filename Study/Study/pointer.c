#include <stdio.h>

void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);

int main_pointer() {

	//int a = 10;
	//int b = 20;
	//printf("\n\n\n =====���� ����======\n\n\n");
	//printf("a�� �ּ� : %d\n", &a);
	//printf("b�� �ּ� : %d\n", &b);

	//printf("swap �Լ� �� -> a: %d , b: %d\n", a, b);
	//swap(a, b);
	//printf("swap �Լ� �� -> a: %d , b: %d\n", a, b);

	//printf("\n\n\n =====�ּҰ� �� ����======\n\n\n");

	//printf("swap �Լ� �� -> a: %d , b: %d\n", a, b);
	//swap_addr(&a, &b);
	//printf("swap �Լ� �� -> a: %d , b: %d\n", a, b);

	int arr[3] = { 10, 20 ,30 };
	changeArray(arr);
	for (int i = 0 ; i < 3; i++) {
		printf("arr[%d] �� �� : %d\n", i, arr[i]);
	}

	return 0;
}

void swap(int a, int b) {

	printf("swap �Լ� �� a�� �ּ� : %d\n", &a);
	printf("swap �Լ� �� b�� �ּ� : %d\n", &b);
	int temp = a;
	a = b;
	b = temp;
	printf("swap �Լ� �� -> a: %d , b: %d\n", a, b);
}

void swap_addr(int *a, int *b) {

	printf("swap �Լ� �� a�� �ּ� : %d\n", *a);
	printf("swap �Լ� �� b�� �ּ� : %d\n", *b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap �Լ� �� -> a: %d , b: %d\n", *a, *b);
}

void changeArray(int* ptr) {
	ptr[2] = 50;
}