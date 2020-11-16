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
	
	if (Queue->Rear == Queue->Capacity) { //후단이 용량의 끝이라면(실제용량은 +1이기 때문에 전단과 후단사이가 하나 비어있음)
		Position = Queue->Rear; // Position은 후단이고
		Queue->Rear = 0; //후단을 0으로 보냄
	}
	else { //용량의 끝이 아니라면
		Position = Queue->Rear++; //Postion은 후단이고 후단은 다음 배열로 보냄
	}

	Queue->Nodes[Position].Data = Data; // Position자리에 노드 삽입

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

