#include "BinarySearchTree.h"

BSTNode* BST_SearchNode(BSTNode* Tree, int Target) {

	if (Tree == NULL){ // 이진 탐색 트리가 널이면
		return NULL; // 널 반환
	}
	
	if (Tree->Data == Target) { // 트리의 루트 노드의 데이터와 타겟이 일치하면
		return Tree; // 노드 반환
	}
	else if (Tree->Data > Target) { // 루트 노드의 데이터가 목표 값 보다 크면
		return BST_SearchNode(Tree->Left, Target); // 왼쪽 자식 노드로 재귀
	}
	else if (Tree->Data < Target) { // 루트 노드의 데이터가 목표 값 보다 작으면
		return BST_SearchNode(Tree->Right, Target); // 오른쪽 자식 노드로 재귀
	}
}

void BST_InsertNode(BSTNode** Tree, BSTNode* Child) {

	if ((*Tree)->Data < Child->Data) { // 삽입할 데이터가 루트 노드보다 크면 오른쪽 노드로
		if ((*Tree)->Right == NULL) { // 오른쪽 노드가 널이면
			(*Tree)->Right = Child; // 삽입
		}
		else { // 오른쪽 노드가 널이 아니면 
			BST_InsertNode((*Tree)->Right, Child); // 오른쪽 자식 노드로 재귀
		}
	}
	else if ((*Tree)->Data > Child->Data) { // 삽입할 데이터가 루트 노드보다 작으면 왼쪽 노드로
		if ((*Tree)->Left == NULL) { // 널이면
			(*Tree)->Left = Child; // 삽입
		}
		else { // 왼쪽 노드가 널이 아니면
			BST_InsertNode((*Tree)->Left, Child); // 왼쪽 자식 노드로 재귀
		}
	} 
	else { // 삽입할 데이터와 루트노드가 같으면
		printf("중복 노드 입니다.");
		return; // 리턴
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

	if (Tree->Data > Target) { // 삭제할 데이터가 루트 노드보다 작으면
		Removed = BST_RemoveNode(Tree->Left, Tree, Target); // 왼쪽 트리로 이동
	}
	else if (Tree->Data < Target) { // 삭제할 데이터가 루트 노드보다 크면
		Removed = BST_RemoveNode(Tree->Right, Tree, Target); // 오른쪽 트리로 이동
	}
	else { // 삭제할 데이터가 루트 노드와 일치
		Removed = Tree; // 삭제할 데이터는 Tree

		if (Tree->Left == NULL && Tree->Right == NULL) { // 삭제할 노드의 자식 노드가 존재 하지 않는다면
			if (Parent->Left == Tree) { // 삭제할 데이터가 루트 노드의 왼쪽 트리면
				Parent->Left = NULL; // 왼쪽 삭제
			}
			else { // 오른쪽이면
				Parent->Right = NULL; // 오른쪽 삭제
			}
		}
		else { // 삭제할 노드의 자식 노드가 존재 한다면
			if (Tree->Left != NULL && Tree->Right != NULL) { // 양쪽다 존재 한다면
				BSTNode* MinNode = BST_SearchMinNode(Tree->Right); // 오른쪽 트리중에서 최소값 노드를 찾는다.
				Removed = BST_RemoveNode(Tree, NULL, MinNode->Data); // 찾은 최소값 노드도 옮겨질 때, 후처리를 해줘야 하기 때문에 똑같이 리무브함수를 호출해준다.
				Tree->Data = MinNode->Data; // 삭제할 노드를 최소값 노드의 데이터로 교체
			}
			else { // 자식 노드가 한쪽만 존재 할 경우
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