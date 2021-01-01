#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int DataSet[], int Size, int Target) {
    int Left; // 왼쪽 인덱스
    int Right; // 오른쪽 인덱스
    int Mid; // 중간 인덱스

    Left = 0; // 처음 인덱스
    Right = Size - 1; // 끝 인덱스

    while (Left <= Right) { // 탐색 인덱스의 범위가 0이 될때까지 루프를 반복한다.
        Mid = (Left + Right) / 2; // 중간 인덱스 번호 찾기

        if (Target == DataSet[Mid]) { // 타겟 일치하면
            return Mid; // 리턴
        }
        else if (Target > DataSet[Mid]) { // 타겟이 저 크다면
            Left = Mid + 1; // 왼쪽 인덱스를 옮긴다
        }
        else { // 타겟이 작은쪽에 있다면
            Right = Mid - 1; // 오른쪽 인덱스를 옮긴다
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

    printf("찾아낸 목표 값의 인덱스 번호 : %d ", Found);

    return 0;
}
