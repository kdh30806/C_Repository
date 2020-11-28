#include <stdio.h>
#include <string.h>

void InsertationSort(int DataSet[], int Length) {
	int i = 0;
	int j = 0;
	int value = 0;

	for (i = 1; i < Length; i++) { //데이터 크기 집합의 크기만큼 반복 (i=1부터 시작인 이유 => 두장의 숫자중 1번 인덱스의 숫자를 꺼내기 위함)
		if (DataSet[i - 1] <= DataSet[i]) //오름차순 정렬이 되어있는 데이터는 다음 반복 실행
			continue;

		value = DataSet[i]; //value에 뽑은 숫자 삽입

		for (j = 0; j < i; j++) {
			if (DataSet[j] > value) { //앞의 인덱스의 숫자가 더 클경우
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j)); // memmove(새로운 메모리 주소, 원본 데이터, 이동시킬 데이터의 양)
				DataSet[j] = value;
				break;
			}
		}
	}
}

int main(void) {

	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	InsertationSort(DataSet, Length);

	for (i = 0; i < Length; i++) {
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}