#include <stdio.h>
#include <malloc.h>

typedef struct tagNode {
	int Data;
	struct  tagNode* PrevNode; 
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

	while (current != NULL && (--location) >= 0) {
		current = current->NextNode;
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

	NewNode->PrevNode = Current;
	NewNode->NextNode = Current->NextNode;

	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
	}
	Current->NextNode = NewNode;
}

void DLL_GetNodeCount(Node* Head) {

	int count = 0;
	Node* Current = Head;
	while (Current != NULL) {
		Current = Current->NextNode;
		count++;
	}

	return count;

}

int main() {
	return 0;
}