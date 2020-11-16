#include <stdio.h>

typedef struct tagNode {
	int Data;
}Node;

typedef struct  tagCircularQueue
{
	int Capacity; //큐의 용량 실제용량보다 하나 작다
	int Front; //전단의 위치(제거되는 노드가 위치해있는 곳)
	int Rear; //후단의 위치(들어오는 입구) 실제 후단보다 1더 큰 값
	Node* Nodes; //노드의 배열
}CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, int capacity);
void CQ_DestroyQueue(CircularQueue* Queue);
void CQ_Enqueue(CircularQueue* Queue, int Data);
int CQ_Dequeue(CircularQueue* Queue);
int CQ_IsEmpty(CircularQueue* Queue);
int CQ_IsFull(CircularQueue* Queue);
int CQ_GetSize(CircularQueue* Queue);