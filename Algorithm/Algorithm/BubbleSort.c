#include <stdio.h>

void BubbleSort(int DataSet[], int Length) {
	 
	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 0; i < Length - 1; i++) { // 데이터 집합의 크기만큼 내부에 있는 for 루프 실행
		for (j = 0; j < Length - (i + 1); j++) { //정렬이 될때마다 정렬할 갯수가 하나씩 줄어듬

			if (DataSet[j] < DataSet[j + 1]) { //만약 정렬이 되어 있다면 다음 루프 실행
				continue;
			}
			if (DataSet[j] > DataSet[j + 1]) { //정렬이 안되어 있다면 스왑
				temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
			}
		}
	}
}

int main_BubbleSort (void) {
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0]; // 배열의 길이
	int i = 0;

	BubbleSort(DataSet, Length);

	for (i = 0; i < Length; i++) {
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}