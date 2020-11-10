#include <stdio.h>
#include <malloc.h>

typedef struct tagNode
{
	int Data;
} Node;

typedef struct tagArrayStack
{
	int Capacity;
	int Top;
	Node* Nodes;
} ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int capacity) {
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * capacity);

	(*Stack)->Capacity = capacity;
	(*Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack* Stack) {
	free(Stack->Nodes);
	free(Stack);
}

void AS_Push(ArrayStack* Stack, int Data) {
	int position = Stack->Top;

	Stack->Nodes[position].Data = Data;
	Stack->Top++;
}

int AS_Pop(ArrayStack* Stack) {
	int position = --Stack->Top;
	return Stack->Nodes[position].Data;
}