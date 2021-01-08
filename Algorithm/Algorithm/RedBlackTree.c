#include "RedBlackTree.h"

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

void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode) {
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

void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor) {

	RBTNode* Sibling = NULL;

	while (Successor->Parent != NULL && Successor->Color == BLACK) { // ��������� ��Ʈ ���� ���ų� ������ ��忡�� �Ѿ�� �ݺ� ����
		
		if (Successor == Successor->Parent->Left) { // ������� ��尡 ������ ���
			Sibling = Successor->Parent->Right;
			// 1. ������ �������� ���
			if (Sibling->Color == RED) {
				Sibling->Color = BLACK;
				Successor->Parent->Color = RED;
				RBT_RotateLeft(Root, Successor->Parent);
			}
			//2. ������ �������� ���
			else {
				// 2-1. ������ ���� �ڽ��� ��� �������� ���
				if (Sibling->Left->Color == BLACK && Sibling->Right->Color == BLACK) {
					Sibling->Color = RED;
					Successor = Successor->Parent;
				}
				// 2-2. ���� �ڽ��� �������� ���
				else {
					if (Sibling->Left->Color == RED) {
						Sibling->Left->Color = BLACK;
						Sibling->Color = RED;

						RBT_RotateRight(Root, Sibling);
						Sibling = Successor->Parent->Right;
					}
					// 2-3. ������ �ڽ��� �������� ���
					Sibling->Color = Successor->Parent->Color;
					Successor->Parent->Color = BLACK;
					Sibling->Right->Color = BLACK;
					RBT_RotateLeft(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
		else {
			Sibling = Successor->Parent->Left;
			// 1. ������ �������� ���
			if (Sibling->Color == RED) {
				Sibling->Color = BLACK;
				Successor->Parent->Color = RED;
				RBT_RotateRight(Root, Successor->Parent);
			}
			//2. ������ �������� ���
			else {
				// 2-1. ������ ���� �ڽ��� ��� �������� ���
				if (Sibling->Right->Color == BLACK && Sibling->Left->Color == BLACK) {
					Sibling->Color = RED;
					Successor = Successor->Parent;
				}
				// 2-2. ������ �ڽ��� �������� ���
				else {
					if (Sibling->Right->Color == RED) {
						Sibling->Right->Color = BLACK;
						Sibling->Color = RED;

						RBT_RotateLeft(Root, Sibling);
						Sibling = Successor->Parent->Left;
					}
					// 2-3. ������ �ڽ��� �������� ���
					Sibling->Color = Successor->Parent->Color;
					Successor->Parent->Color = BLACK;
					Sibling->Right->Color = BLACK;
					RBT_RotateRight(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
	}
}

RBTNode* RBT_RemoveNode(RBTNode** Root, int Data) {
	RBTNode* Removed = NULL;
	RBTNode* Successor = NULL;
	RBTNode* Target = RBT_SearchNode((*Root), Data);

	if (Target == NULL) {
		return NULL;
	}

	if (Target->Left == Nil || Target->Right == Nil) {
		Removed = Target;
	}
	else {
		Removed = BST_SearchMinNode(Target->Right);
		Target->Data = Removed->Data;
	}

	if (Removed->Left != Nil) {
		Successor = Removed->Left;
	}
	else {
		Successor = Removed->Right;
	}

	Successor->Parent = Removed->Parent;

	if (Removed->Parent == NULL) {
		(*Root) = Successor;
	}
	else {
		if (Removed == Removed->Parent->Left) {
			Removed->Parent->Left = Successor;
		}
		else {
			Removed->Parent->Right = Successor;
		}
	}

	if (Removed->Color == BLACK) // ������ ��尡 �������� ��� ��������̱� ������ ó���� ���� ������ �Լ� ȣ��
		RBT_RebuildAfterRemove(Root, Successor);

	return Removed;
}

RBTNode* RBT_SearchNode(RBTNode* Tree, int Target) {
	if (Tree == Nil)
		return NULL;

	if (Tree->Data > Target) {
		return RBT_SearchNode(Tree->Left, Target);
	}
	else if(Tree->Data < Target){
		return RBT_SearchNode(Tree->Right, Target);
	}
	else {
		return Tree;
	}
}

RBTNode* BST_SearchMinNode(RBTNode* Tree) {
	if (Tree == Nil) {
		return Nil;
	}

	if (Tree->Left == Nil) {
		return Tree;
	}
	else {
		return BST_SearchMinNode(Tree->Left);
	}
		
}

void RBT_DestroyNode(RBTNode* Node) {
	free(Node);
}

void RBT_DestroyTree(RBTNode* Tree) {
	if (Tree->Right != Nil) {
		RBT_DestroyTree(Tree->Right);
	}

	if (Tree->Left != Nil) {
		RBT_DestroyTree(Tree->Left);
	}

	Tree->Left = Nil;
	Tree->Right = Nil;

	RBT_DestroyNode(Tree);
}

RBTNode* RBT_CreateNode(int NewData) {
	RBTNode* NewNode = (RBTNode*)malloc(sizeof(RBTNode));
	NewNode->Parent = NULL;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	NewNode->Color = BLACK;

	return NewNode;
}

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount) {
	int i = 0;
	char c = 'X';
	int v = -1;
	char cnt[100];

	if (Node == NULL || Node == Nil)
		return;

	if (Node->Color == BLACK)
		BlackCount++;

	if (Node->Parent != NULL) {
		v = Node->Parent->Data;

		if (Node->Parent->Left == Node) {
			c = 'L';
		}
		else {
			c = 'R';
		}
	}

	if (Node->Left == Nil && Node->Right == Nil) {
		sprintf(cnt, "------------ %d", BlackCount);
	}
	else {
		sprintf(cnt, "");
	}

	for (i = 0; i < Depth; i++) {
		printf("  ");
	}
	printf("%d  %s [%c,%d] %s\n", Node->Data, (Node->Color == RED) ? "RED" : "BLACK", c, v, cnt);

	RBT_PrintTree(Node->Left, Depth + 1, BlackCount);
	RBT_PrintTree(Node->Right, Depth + 1, BlackCount);
}