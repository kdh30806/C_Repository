#include "ExpressionTree.h"

ETNode* ET_CreateNode(char NewData) {
	ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode));

	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
}

void ET_DestroyNode(ETNode* Node) {
	free(Node);
}

void ET_DestroyTree(ETNode* Root) {
	if (Root == NULL)
		return;

	ET_DestroyTree(Root->Left);
	ET_DestroyTree(Root->Right);
	ET_DestroyNode(Root);
}

void ET_PreorderPrintTree(ETNode* Root) {
	if (Root == NULL)
		return;

	printf(" %c", Root->Data);

	ET_PreorderPrintTree(Root->Left);

	ET_PreorderPrintTree(Root->Right);
}

void ET_InorderPrintTree(ETNode* Root) {
	if (Root == NULL)
		return;

	printf("(");
	ET_InorderPrintTree(Root->Left);

	printf("%c", Root->Data);

	ET_InorderPrintTree(Root->Right);
	printf(")");
}

void ET_PostorderPrintTree(ETNode* Root) {
	if (Root == NULL)
		return;

	ET_PostorderPrintTree(Root->Left);

	ET_PostorderPrintTree(Root->Right);

	printf(" %c", Root->Data);
}

void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node) {
	int len = strlen(PostfixExpression);
	char Token = PostfixExpression[len - 1];
	PostfixExpression[len - 1] = '\0';

	switch (Token)
	{
	case '+': case '-': case '*': case '/':
		(*Node) = ET_CreateNode(Token);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
		break;

	default:
		(*Node) = ET_CreateNode(Token);
		break;
	}
}

double ET_Evaluate(ETNode* Tree) {
	char Temp[2];

	double Left = 0;
	double Right = 0;
	double Result = 0;
	if (Tree == NULL)
		return 0;

	switch (Tree->Data)
	{
	case '+': case '-': case '*': case '/':
		Left = ET_Evaluate(Tree->Left);
		Right = ET_Evaluate(Tree->Right);

		if (Tree->Data == '+') Result = Left + Right;
		else if (Tree->Data == '-') Result = Left - Right;
		else if (Tree->Data == '*') Result = Left * Right;
		else if (Tree->Data == '/') Result = Left / Right;
		break;
	default:
		memset(Temp, 0, sizeof(Temp));
		Temp[0] = Tree->Data;
		Result = atof(Temp);
		break;
	}

	return Result;
}