#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack) {
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack) {
	while (!LLS_IsEmpty(Stack)) {
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}

	free(Stack);
}

Node* LLS_CreateNode(char* NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(sizeof(strlen(NewData) + 1));

	strcpy_s(NewNode->Data, NewData, NewNode);

	NewNode->NextNode = NULL;

	return NewNode;
}

void LLS_DestroyNode(Node* _Node) {
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode) {
	if (Stack->List == NULL) {
		Stack->List = NewNode;
	}
	else {
		Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL)
		{
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;
	}

	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack) {
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top) {
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else {
		Node* NewTopNode = Stack->List;

		while (NewTopNode != NULL && NewTopNode->NextNode != Stack->Top) {
			NewTopNode = NewTopNode->NextNode;
		}

		Stack->Top = NewTopNode;
		NewTopNode->NextNode = NULL;
	}
	return TopNode;
}

int LLS_GetSize(LinkedListStack* Stack) {
	Node* CurrentNode = Stack->List;
	int count = 0;

	while (CurrentNode != NULL) {
		CurrentNode = CurrentNode->NextNode;
		count++;
	}
	return count;
}

int LLS_IsEmpty(LinkedListStack* Stack) {
	return (Stack->List == NULL);
}

Node* LLS_Top(LinkedListStack* Stack) {
	return Stack->Top;
}