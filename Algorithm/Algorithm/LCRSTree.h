#include <stdio.h>
#include <malloc.h>

typedef struct tagLCRSNode {
	struct tagLCRSNode* LeftChild; //���� �ڽĳ�� ������
	struct tagLCRSNode* RightSibling; //������ ������� ������
	char Data;
}LCRSNode;

LCRSNode* LCRS_CreateNode(char NewData);
void LCRS_DestroyNode(LCRSNode* Node);
void LCRS_DestroyTree(LCRSNode* Root);
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child);
void LCRS_PrintTree(LCRSNode* Node, int Depth);