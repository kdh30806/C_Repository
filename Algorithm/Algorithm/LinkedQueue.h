#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct tagNode {
	char* Data;
	struct tagNode* NextNode;
}Node;

typedef struct tagLinkedQueue {
	Node* Front;
	Node* Rear;
	int Count;
}LinkedQueue;

void LQ_CreateQueue(LinkedQueue** Queue);
Node* LQ_CreateNode(char* NewData);
void LQ_DestroyQueue(LinkedQueue* Queue);
void LQ_DestroyNode(Node* _Node);
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* LQ_Dequeue(LinkedQueue* Queue);
int LQ_IsEmpty(LinkedQueue* Queue);

