#include <stdio.h>

typedef struct tagNode {
	int data;
	struct tagNode* NextNode;
} Node;
Node MyNode;

Node* SLL_SequentailSearchNode(Node* Head, int Target) { //링크드 리스트를 위한 순차탐색
	Node* Current = Head; 
	Node* Match = NULL; // 탐색할 타겟과 일차하는 노드

	while (Current != NULL) { //노드가 널이 아닐동안 => 널이면 빠져나옴
		if (Current->data == Target) { // 노드의 데이터와 타겟이 일치하면
			Match = Current; // 매치노드에 노드대입
			break; // 반복문 빠져나옴
		}
		else {
			Current = Current->NextNode; // 아니면 다음노드 이동
		}
	}
	return Match;
}

int Arr_SequentailSearch(int DataSet[], int Target, int size) { // 배열을 위한 순차탐색

	int Target_index = 0; // 타겟 인덱스 번호

	for (int i = 0; i < size; i++){ // 배열의 크기만큼 반복
		if (DataSet[i] == Target) { // 배열의 데이터와 타겟 일치하면
			Target_index = i;
			break;
		}
	}
	return Target_index;
}

Node* SLL_MoveToFront(Node** Head, int Target) { //링크드리스트 전진 이동 순차 탐색
	Node* Current = (*Head);
	Node* Previous = NULL;
	Node* Match = NULL;

	while (Current != NULL) { // 현재 노드가 널이 아닐동안 반복
		if (Current->data == Target) { // 타겟과 데이터 일치하면
			Match == Current; // Match에 저장
			if (Previous != NULL) { // 이전노드가 널이 아니면 => 두번째 노드부터
				Previous->NextNode = Current->NextNode; // 이전노드의 다음 노드를 현재 노드의 다음 노드로 연결

				Current->NextNode = (*Head); // 현재 노드의 다음 노드는 헤드
				(*Head) = Current; // 헤드가 현재 노드가 됨
			}
			break;
		}
		else { // 타겟 노드와 일치하지 않으면
			Previous = Current; // 현재 노드는 이전 노드가 되고
			Current = Current->NextNode; // 현재 노드는 현재 노드의 다음 노드가 됨 => 한칸 이동
		}
	}
	return Match;
}

int Arr_MoveToFront(int DataSet[], int Target, int size) { // 배열 전진 이동 순차 탐색
	int Prev = 0;
	int Target_index = 0;

	for (int i = 0; i < size; i++) {
		if (DataSet[i] == Target) {
			Target_index = i;
			if (i != 0) {
				memmove(&DataSet[1], &DataSet[0], sizeof(DataSet[0]) * i); 
				// 첫 번째 매개변수는 이동할 새로운 주소
				// 두 번째 매개변수는 이동할 데이터가 어디서 부터인지를 나타내는 주소
				// 세 번째 매개변수는 얼마만큼 옮길건지를 표현하는 byte
				DataSet[0] = Target;
			}
			break;
		}
	}
	return Target_index;
}

Node* SLL_Transpose(Node** Head, int Target) {
	Node* Current = (*Head);
	Node* PPrevious = NULL; // 이전노드의 이전노드
	Node* Previous = NULL; // 이전노드
	Node* Match = NULL;

	while (Current != NULL) {
		if (Current->data == Target) { // 타겟과 데이터 일치하면
			Match = Current; // 매치노드에 현재노드 저장
			if (Previous != NULL) { // 이전노드 널이 아니면
				if (PPrevious != NULL) { // 이전노드의 이전노드가 널이 아니면
					PPrevious->NextNode = Current; // 이전이전노드의 다음노드는 현재노드
				}
				else { // 이전노드의 이전노드가 널이면
					(*Head) = Current; //헤드노드가 현재노드
				}

				Previous->NextNode = Current->NextNode; // 이전노드의 다음노드는 현재노드의 다음노드

				Current->NextNode = Previous; // 현재노드의 다음노드는 이전노드가 된다
			}
			break;
		}
		else {
			if (Previous != NULL) { // 타겟 일치하지 않으면
				PPrevious = Previous;
				Previous = Current;
				Current = Current->NextNode;
			}
		}
	}
	return Match;
}

int Arr_Transpose(int DataSet[], int Target, int size) {
	int Target_index;
	int temp; // 값 교환시 사용될 변수
	for (int i = 0; i < size; i++){
		if (DataSet[i] == Target) {
			Target_index = i;
			if (i != 0) {
				temp = DataSet[i - 1];
				DataSet[i - 1] = DataSet[i];
				DataSet[i] = temp;
			}
				break;
		}
	}
	return Target_index;
}

int main(void) {

}
