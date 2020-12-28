#include <stdio.h>

typedef struct tagNode {
	int data;
	struct tagNode* NextNode;
} Node;
Node MyNode;

Node* SLL_SequentailSearchNode(Node* Head, int Target) { //��ũ�� ����Ʈ�� ���� ����Ž��
	Node* Current = Head; 
	Node* Match = NULL; // Ž���� Ÿ�ٰ� �����ϴ� ���

	while (Current != NULL) { //��尡 ���� �ƴҵ��� => ���̸� ��������
		if (Current->data == Target) { // ����� �����Ϳ� Ÿ���� ��ġ�ϸ�
			Match = Current; // ��ġ��忡 ������
			break; // �ݺ��� ��������
		}
		else {
			Current = Current->NextNode; // �ƴϸ� ������� �̵�
		}
	}
	return Match;
}

int Arr_SequentailSearch(int DataSet[], int Target, int size) { // �迭�� ���� ����Ž��

	int Target_index = 0; // Ÿ�� �ε��� ��ȣ

	for (int i = 0; i < size; i++){ // �迭�� ũ�⸸ŭ �ݺ�
		if (DataSet[i] == Target) { // �迭�� �����Ϳ� Ÿ�� ��ġ�ϸ�
			Target_index = i;
			break;
		}
	}
	return Target_index;
}

Node* SLL_MoveToFront(Node** Head, int Target) { //��ũ�帮��Ʈ ���� �̵� ���� Ž��
	Node* Current = (*Head);
	Node* Previous = NULL;
	Node* Match = NULL;

	while (Current != NULL) { // ���� ��尡 ���� �ƴҵ��� �ݺ�
		if (Current->data == Target) { // Ÿ�ٰ� ������ ��ġ�ϸ�
			Match == Current; // Match�� ����
			if (Previous != NULL) { // ������尡 ���� �ƴϸ� => �ι�° ������
				Previous->NextNode = Current->NextNode; // ��������� ���� ��带 ���� ����� ���� ���� ����

				Current->NextNode = (*Head); // ���� ����� ���� ���� ���
				(*Head) = Current; // ��尡 ���� ��尡 ��
			}
			break;
		}
		else { // Ÿ�� ���� ��ġ���� ������
			Previous = Current; // ���� ���� ���� ��尡 �ǰ�
			Current = Current->NextNode; // ���� ���� ���� ����� ���� ��尡 �� => ��ĭ �̵�
		}
	}
	return Match;
}

int Arr_MoveToFront(int DataSet[], int Target, int size) { // �迭 ���� �̵� ���� Ž��
	int Prev = 0;
	int Target_index = 0;

	for (int i = 0; i < size; i++) {
		if (DataSet[i] == Target) {
			Target_index = i;
			if (i != 0) {
				memmove(&DataSet[1], &DataSet[0], sizeof(DataSet[0]) * i); 
				// ù ��° �Ű������� �̵��� ���ο� �ּ�
				// �� ��° �Ű������� �̵��� �����Ͱ� ��� ���������� ��Ÿ���� �ּ�
				// �� ��° �Ű������� �󸶸�ŭ �ű������ ǥ���ϴ� byte
				DataSet[0] = Target;
			}
			break;
		}
	}
	return Target_index;
}

Node* SLL_Transpose(Node** Head, int Target) {
	Node* Current = (*Head);
	Node* PPrevious = NULL; // ��������� �������
	Node* Previous = NULL; // �������
	Node* Match = NULL;

	while (Current != NULL) {
		if (Current->data == Target) { // Ÿ�ٰ� ������ ��ġ�ϸ�
			Match = Current; // ��ġ��忡 ������ ����
			if (Previous != NULL) { // ������� ���� �ƴϸ�
				if (PPrevious != NULL) { // ��������� ������尡 ���� �ƴϸ�
					PPrevious->NextNode = Current; // ������������� �������� ������
				}
				else { // ��������� ������尡 ���̸�
					(*Head) = Current; //����尡 ������
				}

				Previous->NextNode = Current->NextNode; // ��������� �������� �������� �������

				Current->NextNode = Previous; // �������� �������� ������尡 �ȴ�
			}
			break;
		}
		else {
			if (Previous != NULL) { // Ÿ�� ��ġ���� ������
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
	int temp; // �� ��ȯ�� ���� ����
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
