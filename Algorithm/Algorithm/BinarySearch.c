#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int DataSet[], int Size, int Target) {
    int Left; // ���� �ε���
    int Right; // ������ �ε���
    int Mid; // �߰� �ε���

    Left = 0; // ó�� �ε���
    Right = Size - 1; // �� �ε���

    while (Left <= Right) { // Ž�� �ε����� ������ 0�� �ɶ����� ������ �ݺ��Ѵ�.
        Mid = (Left + Right) / 2; // �߰� �ε��� ��ȣ ã��

        if (Target == DataSet[Mid]) { // Ÿ�� ��ġ�ϸ�
            return Mid; // ����
        }
        else if (Target > DataSet[Mid]) { // Ÿ���� �� ũ�ٸ�
            Left = Mid + 1; // ���� �ε����� �ű��
        }
        else { // Ÿ���� �����ʿ� �ִٸ�
            Right = Mid - 1; // ������ �ε����� �ű��
        }
    }
    return 0;
}

int CompareInt(const void* elem1, const void* elem2) {

    if (*(int*)elem1 > * (int*)elem2) {
        return 1;
    }
    else if (*(int*)elem1 < *(int*)elem2) {
        return -1;
    }
    else {
        return 0;
    }
}

int main(void) {
    int Dataset[] = { 1, 9 ,4 ,6, 40, 35, 90, 30, 60, 20 };
    int i = 0;
    int Found = 0;
    int Length = sizeof Dataset / sizeof Dataset[0];

    qsort((void*)Dataset, Length, sizeof Dataset[0], CompareInt);
    Found = BinarySearch(Dataset, Length, 6);

    printf("ã�Ƴ� ��ǥ ���� �ε��� ��ȣ : %d ", Found);

    return 0;
}
