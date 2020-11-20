#include <stdio.h>
#include <malloc.h>

typedef struct tagSBTNode {
	struct tagSBTNode* Left;
	struct tagSBTNode* Right;
	char Data;
}SBTNode;

SBTNode* SBT_CreateNode(char NewData);
void SBT_DestroyNode(SBTNode* Node);
void SBT_PreorderPrintTree(SBTNode* Node);
void SBT_InorderPrintTree(SBTNode* Node);
void SBT_PostorderPrintTree(SBTNode* Node);