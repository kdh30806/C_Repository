#include <stdio.h>

void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);

int main_pointer() {

	//int a = 10;
	//int b = 20;
	//printf("\n\n\n =====값의 전달======\n\n\n");
	//printf("a의 주소 : %d\n", &a);
	//printf("b의 주소 : %d\n", &b);

	//printf("swap 함수 전 -> a: %d , b: %d\n", a, b);
	//swap(a, b);
	//printf("swap 함수 후 -> a: %d , b: %d\n", a, b);

	//printf("\n\n\n =====주소값 의 전달======\n\n\n");

	//printf("swap 함수 전 -> a: %d , b: %d\n", a, b);
	//swap_addr(&a, &b);
	//printf("swap 함수 후 -> a: %d , b: %d\n", a, b);

	int arr[3] = { 10, 20 ,30 };
	changeArray(arr);
	for (int i = 0 ; i < 3; i++) {
		printf("arr[%d] 의 값 : %d\n", i, arr[i]);
	}

	return 0;
}

void swap(int a, int b) {

	printf("swap 함수 내 a의 주소 : %d\n", &a);
	printf("swap 함수 내 b의 주소 : %d\n", &b);
	int temp = a;
	a = b;
	b = temp;
	printf("swap 함수 내 -> a: %d , b: %d\n", a, b);
}

void swap_addr(int *a, int *b) {

	printf("swap 함수 내 a의 주소 : %d\n", *a);
	printf("swap 함수 내 b의 주소 : %d\n", *b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap 함수 내 -> a: %d , b: %d\n", *a, *b);
}

void changeArray(int* ptr) {
	ptr[2] = 50;
}