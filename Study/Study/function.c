#include <stdio.h>

void p(int num);
int add(int num, int num2);
int sub(int num, int num2);
int mul(int num, int num2);
int div(int num, int num2);

int main_function() {

	int num = 2;
	num = add(num, 3); 
	p(num);

	num = sub(num, 1);
	p(num);

	num = mul(num, 3);
	p(num);

	num = div(num, 6);
	p(num);

}

void p(int num) {
	printf("num은 %d입니다. \n", num);
}

int add(int num, int num2) {
	return num + num2;
}

int sub(int num, int num2) {
	return num - num2;
}

int mul(int num, int num2) {
	return num * num2;
}

int div(int num, int num2) {
	return num / num2;
}


