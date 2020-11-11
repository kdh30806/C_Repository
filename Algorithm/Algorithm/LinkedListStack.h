#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
	char* Data;
	struct Node* NextNode;
} Node;

typedef struct tagLinkedListStack
{
	Node* Top;
	Node* List; //Head 
} LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);
Node* LLS_CreateNode(char* NewData);
void LLS_DestroyNode(Node* _Node);
void LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);
Node* LLS_Top(LinkedListStack* Stack);