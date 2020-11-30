#include <stdio.h>

void Swap(int* A, int* B) {
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

int Partition(int DataSet[], int Left, int Right) {
	int First = Left;
	int Pivot = DataSet[First]; // 기준 숫자

	++Left; // 기준 숫자 다음 인덱스 부터 시작

	while (Left <= Right) { // 왼쪽 비교숫자가  오른쪽 보다 작거나 같을 동안 실행
		while (DataSet[Left] <= Pivot && Left < Right) // Left인덱스의 숫자가 기준숫자 보다 작으면
			++Left;

		while (DataSet[Right] > Pivot && Left <= Right) // Right인덱스의 숫자가 기준숫자보다 크면 
			--Right;

		if (Left < Right)
			Swap(&DataSet[Left], &DataSet[Right]); // 스왑
		else
			break;
	}

	Swap(&DataSet[First], &DataSet[Right]); // 마지막으로 기준 숫자와 오른쪽 기준숫자 스왑

	return Right;
}

void QuickSort(int DataSet[], int Left, int Right) {
	if (Left < Right) {
		int Index = Partition(DataSet, Left, Right);

		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}

int main_QuickSort(void) {

	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	QuickSort(DataSet, 0, Length - 1);

	for (i = 0; i < Length; i++) {
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}