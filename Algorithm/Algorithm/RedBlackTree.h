#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct tagRBTNode {
	struct tagRBTNode* Parent;
	struct tagRBTNode* Left;
	struct tagRBTNode* Right;

	enum { RED, BLACK } Color;
	int Data;
}RBTNode;

void RBT_DestroyTree(RBTNode* Tree);

RBTNode* RBT_CreateNode(int NewData);
void RBT_DestroyNode(RBTNode* Node);

RBTNode* BST_SearchMinNode(RBTNode* Tree);

RBTNode* RBT_SearchNode(RBTNode* Tree, int Target);
void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode);
void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode);
RBTNode* RBT_RemoveNode(RBTNode** Root, int Target);
void RBT_RebuildAfterInsert(RBTNode** Tree, RBTNode* NewNode);
void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* X);

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount);
void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent); 
void RBT_RotateRight(RBTNode** Root, RBTNode* Parent);

#endif // !REDBLACKTREE_H