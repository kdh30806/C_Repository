#include <stdio.h>
#include <string.h>

void InsertationSort(int DataSet[], int Length) {
	int i = 0;
	int j = 0;
	int value = 0;

	for (i = 1; i < Length; i++) { //������ ũ�� ������ ũ�⸸ŭ �ݺ� (i=1���� ������ ���� => ������ ������ 1�� �ε����� ���ڸ� ������ ����)
		if (DataSet[i - 1] <= DataSet[i]) //�������� ������ �Ǿ��ִ� �����ʹ� ���� �ݺ� ����
			continue;

		value = DataSet[i]; //value�� ���� ���� ����

		for (j = 0; j < i; j++) {
			if (DataSet[j] > value) { //���� �ε����� ���ڰ� �� Ŭ���
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j)); // memmove(���ο� �޸� �ּ�, ���� ������, �̵���ų �������� ��)
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