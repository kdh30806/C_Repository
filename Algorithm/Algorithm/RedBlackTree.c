#include <stdio.h>
#include <stdlib.h>

typedef struct tagRBTNode {
	struct tagRBTNode* Parent;
	struct tagRBTNode* Left;
	struct tagRBTNode* Right;

	enum {RED, BLACK} Color;
	int Data
}RBTNode;

extern RBTNode* Nil;

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent) {

	RBTNode* LeftChild = Parent->Left;
	Parent->Left = LeftChild->Right; // 왼쪽 자식 노드의 오른쪽 자식 노드를 부모 노드의 왼쪽 자식에 등록

	if (LeftChild->Right != Nil) {
		LeftChild->Right->Parent = Parent; // 등록한 왼쪽 자식의 부모 노드를 바꾼다.
	}

	LeftChild->Parent = Parent->Parent; // 부모노드 교체

	if (Parent->Parent == NULL) { // 부모가 NULL 이라면 루트 노드이다. 그러므로 왼쪽 노드를 루트 노드로 한다.
		(*Root) = LeftChild;
	}
	else {
		if (Parent == Parent->Parent->Left) { // 부모노드가 할아버지 노드의 왼쪽 자식이였다면
			Parent->Parent->Left = LeftChild; // 왼쪽 자식으로
		} 
		else { // 오른쪽 자식이였다면
			Parent->Parent->Right = LeftChild; // 오른쪽 자식으로
		}

		// 마무리
		LeftChild->Right = Parent; 
		Parent->Parent = LeftChild;
	}
}

void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent) {

	RBTNode* RightChild = Parent->Right;
	Parent->Right = RightChild->Left; 

	if (RightChild->Left != Nil) {
		RightChild->Left->Parent = Parent; 
	}

	RightChild->Parent = Parent->Parent; 

	if (Parent->Parent == NULL) { 
		(*Root) = RightChild;
	}
	else {
		if (Parent == Parent->Parent->Right) { 
			Parent->Parent->Right = RightChild;
		}
		else {
			Parent->Parent->Left = RightChild;
		}

		RightChild->Left = Parent;
		Parent->Parent = RightChild;
	}
}

void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode) {
	if ((*Tree) == NULL) { // 루트 노드가 널이면 새로운 노드가 루트 노드
		(*Tree) = NewNode;
	}

	if ((*Tree)->Data < NewNode->Data) { //새로운 노드의 데이터가 더 크면
		if ((*Tree)->Right == Nil) { // 오른쪽 비어 있으면
			(*Tree)->Right = NewNode; // 삽입
			NewNode->Parent = (*Tree); // 부모 노드가 루트 노드
		}
		else {
			RBT_InsertNodeHelper(&(*Tree)->Right, NewNode); // 오른쪽으로 재귀하여 빈 노드를 찾아 간다. 
		}
	}

	if ((*Tree)->Data > NewNode->Data) { //새로운 노드의 데이터가 더 작으면
		if ((*Tree)->Left == Nil) { // 왼쪽 비어 있으면
			(*Tree)->Left = NewNode; // 삽입
			NewNode->Parent = (*Tree); // 부모 노드가 루트 노드
		}
		else {
			RBT_InsertNodeHelper(&(*Tree)->Left, NewNode); // 오른쪽으로 재귀하여 빈 노드를 찾아 간다. 
		}
	}
}

void InsertNode(RBTNode** Tree, RBTNode* NewNode) {
	RBT_InsertNodeHelper(Tree, NewNode);

	NewNode->Color = RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;

	RBT_REbuildAfterInsert(Tree, NewNode); // 인서트 후에 리빌딩을 통하여 레드블랙트리의 규칙을 유지한다.
}