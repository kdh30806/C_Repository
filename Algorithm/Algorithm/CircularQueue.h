#include <stdio.h>

typedef struct tagNode {
	int Data;
}Node;

typedef struct  tagCircularQueue
{
	int Capacity; //ť�� �뷮 �����뷮���� �ϳ� �۴�
	int Front; //������ ��ġ(���ŵǴ� ��尡 ��ġ���ִ� ��)
	int Rear; //�Ĵ��� ��ġ(������ �Ա�) ���� �Ĵܺ��� 1�� ū ��
	Node* Nodes; //����� �迭
}CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, int capacity);
void CQ_DestroyQueue(CircularQueue* Queue);
void CQ_Enqueue(CircularQueue* Queue, int Data);
int CQ_Dequeue(CircularQueue* Queue);
int CQ_IsEmpty(CircularQueue* Queue);
int CQ_IsFull(CircularQueue* Queue);
int CQ_GetSize(CircularQueue* Queue);