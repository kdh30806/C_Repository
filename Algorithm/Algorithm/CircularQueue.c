#include <stdint.h>
#include <malloc.h>
#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue** Queue, int Capacity) {
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));

	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
	(*Queue)->Capacity = Capacity;
}

void CQ_DestroyQueue(CircularQueue* Queue) {
	free(Queue->Nodes);
	free(Queue);
}
void CQ_Enqueue(CircularQueue* Queue, int Data) {
	int Position = 0;
	
	if (Queue->Rear == Queue->Capacity) { //�Ĵ��� �뷮�� ���̶��(�����뷮�� +1�̱� ������ ���ܰ� �Ĵܻ��̰� �ϳ� �������)
		Position = Queue->Rear; // Position�� �Ĵ��̰�
		Queue->Rear = 0; //�Ĵ��� 0���� ����
	}
	else { //�뷮�� ���� �ƴ϶��
		Position = Queue->Rear++; //Postion�� �Ĵ��̰� �Ĵ��� ���� �迭�� ����
	}

	Queue->Nodes[Position].Data = Data; // Position�ڸ��� ��� ����

}

int CQ_Dequeue(CircularQueue* Queue) {
	int Position = Queue->Front;

	if (Queue->Front == Queue->Capacity) {
		Queue->Front = 0;
	}
	else {
		Queue->Front++;
	}

	return Queue->Nodes[Position].Data;
}

int CQ_IsEmpty(CircularQueue* Queue) {
	return (Queue->Front == Queue->Rear);
}

int CQ_IsFull(CircularQueue* Queue) {
	if (Queue->Front < Queue->Rear) {
		return Queue->Capacity == (Queue->Rear - Queue->Front);
	}
	else {
		return (Queue->Rear + 1) == Queue->Front;
	}
}

int CQ_GetSize(CircularQueue* Queue) {
	if (Queue->Front < Queue->Rear) {
		return (Queue->Rear - Queue->Front);
	}
	else {
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
	}
}

