#include "SBTTree.h"

int main_TestBCTTree(void) {
SBTNode* A = SBT_CreateNode('A');
SBTNode* B = SBT_CreateNode('B');
SBTNode* C = SBT_CreateNode('C');
SBTNode* D = SBT_CreateNode('D');
SBTNode* E = SBT_CreateNode('E');
SBTNode* F = SBT_CreateNode('F');
SBTNode* G = SBT_CreateNode('G');

A->Left = B;
B->Left = C;
B->Right = D;

A->Right = E;
E->Left = F;
E->Right = G;

printf("Preoder ...\n");
SBT_PreorderPrintTree(A);
printf("\n\n");

printf("Inorder ...\n");
SBT_InorderPrintTree(A);
printf("\n\n");

printf("Postorder ...\n");
SBT_PostorderPrintTree(A);
printf("\n\n");

return 0;
}


