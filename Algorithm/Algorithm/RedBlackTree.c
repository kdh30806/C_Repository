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
	Parent->Left = LeftChild->Right; // ���� �ڽ� ����� ������ �ڽ� ��带 �θ� ����� ���� �ڽĿ� ���

	if (LeftChild->Right != Nil) {
		LeftChild->Right->Parent = Parent; // ����� ���� �ڽ��� �θ� ��带 �ٲ۴�.
	}

	LeftChild->Parent = Parent->Parent; // �θ��� ��ü

	if (Parent->Parent == NULL) { // �θ� NULL �̶�� ��Ʈ ����̴�. �׷��Ƿ� ���� ��带 ��Ʈ ���� �Ѵ�.
		(*Root) = LeftChild;
	}
	else {
		if (Parent == Parent->Parent->Left) { // �θ��尡 �Ҿƹ��� ����� ���� �ڽ��̿��ٸ�
			Parent->Parent->Left = LeftChild; // ���� �ڽ�����
		} 
		else { // ������ �ڽ��̿��ٸ�
			Parent->Parent->Right = LeftChild; // ������ �ڽ�����
		}

		// ������
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
	if ((*Tree) == NULL) { // ��Ʈ ��尡 ���̸� ���ο� ��尡 ��Ʈ ���
		(*Tree) = NewNode;
	}

	if ((*Tree)->Data < NewNode->Data) { //���ο� ����� �����Ͱ� �� ũ��
		if ((*Tree)->Right == Nil) { // ������ ��� ������
			(*Tree)->Right = NewNode; // ����
			NewNode->Parent = (*Tree); // �θ� ��尡 ��Ʈ ���
		}
		else {
			RBT_InsertNodeHelper(&(*Tree)->Right, NewNode); // ���������� ����Ͽ� �� ��带 ã�� ����. 
		}
	}

	if ((*Tree)->Data > NewNode->Data) { //���ο� ����� �����Ͱ� �� ������
		if ((*Tree)->Left == Nil) { // ���� ��� ������
			(*Tree)->Left = NewNode; // ����
			NewNode->Parent = (*Tree); // �θ� ��尡 ��Ʈ ���
		}
		else {
			RBT_InsertNodeHelper(&(*Tree)->Left, NewNode); // ���������� ����Ͽ� �� ��带 ã�� ����. 
		}
	}
}

void InsertNode(RBTNode** Tree, RBTNode* NewNode) {
	RBT_InsertNodeHelper(Tree, NewNode);

	NewNode->Color = RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;

	RBT_RebuildAfterInsert(Tree, NewNode); // �μ�Ʈ �Ŀ� �������� ���Ͽ� �����Ʈ���� ��Ģ�� �����Ѵ�.
}

void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X) {
	while (X != (*Root) && X->Parent->Color == RED) { // ��Ģ�� �����ϰ� �ִ� ���� ��� �ݺ��Ѵ�.
		if (X->Parent == X->Parent->Parent->Left) { // �θ��尡 �Ҿƹ��� ����� ���� �ڽ��� ���
			RBTNode* Uncle = X->Parent->Parent->Right;
			if (Uncle->Color == RED) { // 1.���� ��尡 �������� ���
				X->Parent->Color = BLACK; 
				Uncle->Color = BLACK;
				X->Parent->Parent->Color = RED;
				X = X->Parent->Parent;
			}
			else { // ���� ��尡 �������� ���
				if (X == X->Parent->Right) { // ������ �ڽ��� ���
					X = X->Parent;
					RBT_RotateLeft(Root, X); // �������� ȸ�� ��Ų��.
				}
				X->Parent->Color = BLACK;
				X->Parent->Parent->Color = RED;
				RBT_RotateRight(Root, X->Parent->Parent);
			}
		}
		else { // �θ��尡 �Ҿƹ��� ����� ������ �ڽ��� ���� ���� ���� �ڽ��� ��쿡�� ��/�츸 �ٲ��ش�.
			RBTNode* Uncle = X->Parent->Parent->Left;
			if (Uncle->Color == RED) { // 1.���� ��尡 �������� ���
				X->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				X->Parent->Parent->Color = RED;
				X = X->Parent->Parent;
			}
			else { // ���� ��尡 �������� ���
				if (X == X->Parent->Left) { // ���� �ڽ��� ���
					X = X->Parent;
					RBT_RotateRight(Root, X); // ���������� ȸ�� ��Ų��.
				}
				X->Parent->Color = BLACK;
				X->Parent->Parent->Color = RED;
				RBT_RotateLeft(Root, X->Parent->Parent);
			}
		}
	}

	(*Root)->Color = BLACK;
}