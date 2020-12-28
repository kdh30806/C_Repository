#include <stdio.h>
#include <malloc.h>

typedef struct tagNode {
	int Data;
	struct tagNode* PrevNode; 
	struct tagNode* NextNode;
} Node;

Node* DLL_CreatNode(int NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DLL_DestroyNode(Node* Node) {
	free(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode) {
	if (*Head == NULL) {
		*Head = NewNode;
	}
	else {
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

Node* DLL_GetNodeAt(Node* Head, int location) {

	Node* current = Head;

	while (current != NULL && location > 1) {
		current = current->NextNode;
		location--;
	}

	return current;
}

void DLL_RemoveNode(Node** Head, Node* Remove) {
	if ((*Head) == Remove) {
		(*Head) = Remove->NextNode;
		if ((*Head) != NULL) {
			(*Head)->PrevNode = NULL;
		}
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else {
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Remove->NextNode;
		if (Remove->NextNode != NULL) {
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}

		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;

	}
}

void DLL_InsertAfter(Node* Current, Node* NewNode) {
	// Current 뒤에 NewNode 추가

	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
	}
	Current->NextNode = NewNode;
}

int DLL_GetNodeCount(Node* Head) {

	int count = 0;
	Node* Current = Head;
	while (Current != NULL) {
		Current = Current->NextNode;
		count++;
	}

	return count;
}

void DLL_OutData(Node* Head) {

	Node* Current = Head;

	for (int i = 1; i <= DLL_GetNodeCount(Current); i++) {

		Node* node = DLL_GetNodeAt(Current, i);

		printf("%d번째 데이터는 %d입니다.\n", i+1, node->Data);
	}
}

int main_DoubleLinkedList() {

	Node* DLL_List = NULL;
	Node* NewNode = NULL;

	NewNode = DLL_CreatNode(10);
	DLL_AppendNode(&DLL_List, NewNode);

	NewNode= DLL_CreatNode(9);
	DLL_AppendNode(&DLL_List, NewNode);

	NewNode = DLL_CreatNode(13);
	DLL_AppendNode(&DLL_List, NewNode);

	NewNode = DLL_CreatNode(14);
	DLL_AppendNode(&DLL_List, NewNode);

	NewNode = DLL_CreatNode(15);
	DLL_AppendNode(&DLL_List, NewNode);

	NewNode = DLL_CreatNode(100);
	DLL_InsertAfter(DLL_GetNodeAt(DLL_List,1), NewNode);

	DLL_OutData(DLL_List);

	return 0;
}