#include <stdio.h>
#include <stdlib.h>

typedef struct tagBSTNode {
	struct tagBSTNode* Left;
	struct tagBstNode* Right;
	int Data;
}BSTNode;

BSTNode* BST_CreateNode(int NewData);
void BST_DestroyNode(BSTNode* Node);
void BST_DestoryTree(BSTNode* Tree);

BSTNode* BST_SearchNode(BSTNode* Tree, int Target);
BSTNode* BST_SearchMinNode(BSTNode* Tree);
void BST_InsertNode(BSTNode* Tree, BSTNode* Child);
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, int Target);
void BST_InorderPrintTree(BSTNode* Tree);