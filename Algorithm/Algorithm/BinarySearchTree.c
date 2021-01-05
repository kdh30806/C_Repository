#include "BinarySearchTree.h"

BSTNode* BST_SearchNode(BSTNode* Tree, int Target) {

	if (Tree == NULL){ // ���� Ž�� Ʈ���� ���̸�
		return NULL; // �� ��ȯ
	}
	
	if (Tree->Data == Target) { // Ʈ���� ��Ʈ ����� �����Ϳ� Ÿ���� ��ġ�ϸ�
		return Tree; // ��� ��ȯ
	}
	else if (Tree->Data > Target) { // ��Ʈ ����� �����Ͱ� ��ǥ �� ���� ũ��
		return BST_SearchNode(Tree->Left, Target); // ���� �ڽ� ���� ���
	}
	else if (Tree->Data < Target) { // ��Ʈ ����� �����Ͱ� ��ǥ �� ���� ������
		return BST_SearchNode(Tree->Right, Target); // ������ �ڽ� ���� ���
	}
}

void BST_InsertNode(BSTNode** Tree, BSTNode* Child) {

	if ((*Tree)->Data < Child->Data) { // ������ �����Ͱ� ��Ʈ ��庸�� ũ�� ������ ����
		if ((*Tree)->Right == NULL) { // ������ ��尡 ���̸�
			(*Tree)->Right = Child; // ����
		}
		else { // ������ ��尡 ���� �ƴϸ� 
			BST_InsertNode((*Tree)->Right, Child); // ������ �ڽ� ���� ���
		}
	}
	else if ((*Tree)->Data > Child->Data) { // ������ �����Ͱ� ��Ʈ ��庸�� ������ ���� ����
		if ((*Tree)->Left == NULL) { // ���̸�
			(*Tree)->Left = Child; // ����
		}
		else { // ���� ��尡 ���� �ƴϸ�
			BST_InsertNode((*Tree)->Left, Child); // ���� �ڽ� ���� ���
		}
	} 
	else { // ������ �����Ϳ� ��Ʈ��尡 ������
		printf("�ߺ� ��� �Դϴ�.");
		return; // ����
	}
}

BSTNode* BST_SearchMinNode(BSTNode* Tree) {
	if (Tree == NULL) {
		return NULL;
	}

	if (Tree->Left == NULL) {
		return Tree;
	}
	else {
		return BST_SearchMinNode(Tree->Left);
	}
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, int Target) {
	BSTNode* Removed = NULL;

	if (Tree == NULL) {
		return NULL;
	}

	if (Tree->Data > Target) { // ������ �����Ͱ� ��Ʈ ��庸�� ������
		Removed = BST_RemoveNode(Tree->Left, Tree, Target); // ���� Ʈ���� �̵�
	}
	else if (Tree->Data < Target) { // ������ �����Ͱ� ��Ʈ ��庸�� ũ��
		Removed = BST_RemoveNode(Tree->Right, Tree, Target); // ������ Ʈ���� �̵�
	}
	else { // ������ �����Ͱ� ��Ʈ ���� ��ġ
		Removed = Tree; // ������ �����ʹ� Tree

		if (Tree->Left == NULL && Tree->Right == NULL) { // ������ ����� �ڽ� ��尡 ���� ���� �ʴ´ٸ�
			if (Parent->Left == Tree) { // ������ �����Ͱ� ��Ʈ ����� ���� Ʈ����
				Parent->Left = NULL; // ���� ����
			}
			else { // �������̸�
				Parent->Right = NULL; // ������ ����
			}
		}
		else { // ������ ����� �ڽ� ��尡 ���� �Ѵٸ�
			if (Tree->Left != NULL && Tree->Right != NULL) { // ���ʴ� ���� �Ѵٸ�
				BSTNode* MinNode = BST_SearchMinNode(Tree->Right); // ������ Ʈ���߿��� �ּҰ� ��带 ã�´�.
				Removed = BST_RemoveNode(Tree, NULL, MinNode->Data); // ã�� �ּҰ� ��嵵 �Ű��� ��, ��ó���� ����� �ϱ� ������ �Ȱ��� �������Լ��� ȣ�����ش�.
				Tree->Data = MinNode->Data; // ������ ��带 �ּҰ� ����� �����ͷ� ��ü
			}
			else { // �ڽ� ��尡 ���ʸ� ���� �� ���
				BSTNode* Temp = NULL;
				if (Tree->Left != NULL) {
					Temp = Tree->Left;
				}
				else {
					Temp = Tree->Right;
				}

				if (Parent->Left == Tree) {
					Parent->Left = Temp;
				}
				else {
					Parent->Right = Temp;
				}
			}
		}
	}
}