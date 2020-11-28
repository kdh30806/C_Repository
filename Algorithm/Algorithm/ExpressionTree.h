#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct tagETNode {
	struct tagETNode* Left;
	struct tagETNode* Right;

	char Data;
}ETNode;

ETNode* ET_CreateNode(char NewData);
void ET_DestroyNode(ETNode* Node);
void ET_DestroyTree(ETNode* Root);
void ET_PreorderPrintTree(ETNode* Root);
void ET_InorderPrintTree(ETNode* Root);
void ET_PostorderPrintTree(ETNode* Root);
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node);
double ET_Evaluate(ETNode* Tree);