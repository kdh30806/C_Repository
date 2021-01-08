#include <stdio.h>
#include <stdlib.h>

int CompareInt(const void* elem1, const void* elem2){

	if (*(int*)elem1 > * (int*)elem2) {
		return 1;
	}
	else if ( *(int*)elem1 < *(int*)elem2) {
		return -1;
	}
	else {
		return 0;
	}
}

int main_BinarySearch2(void) {
	int Dataset[] = { 1, 9 ,4 ,6, 40, 35, 90, 30, 60, 20 };
	int Length = sizeof Dataset / sizeof Dataset[0];
	int Target = 4;
	int* Found = 0;

	qsort((void*)Dataset, Length, sizeof Dataset[0], CompareInt);

	Found = bsearch((void*)&Target,(void*)Dataset, Length, sizeof Dataset[0], CompareInt);

	printf("찾아낸 목표 값의 인덱스 번호 : %d " ,Found-Dataset); // Found-DataSet => Found 의 인덱스 번호

	return 0;
}