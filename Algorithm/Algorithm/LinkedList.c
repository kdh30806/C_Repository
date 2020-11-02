#include <stdint.h>
#include <malloc.h>

typedef struct tagNode {
	int data;
	struct tagNode* NextNode;
} Node;


Node* SLL_creatNode(int newData) {
	//c���� �ڵ� �޸𸮿� ���� �޸𸮰� ����
	// �ڵ� �޸� = {} ����� ������� �޸�
	// ���� �޸� = �����Ӱ� �޸� �Ҵ� ���� => �ڹٿ����� ������ �÷��Ͱ� �˾Ƽ� ���� �������� c������ ���� ���־����
	Node* newNode = (Node*)malloc(sizeof(Node)); //malloc => ���� �޸𸮿� newNode ������ ����

	newNode->data = newData;
	newNode->NextNode = NULL;

	return newNode;
}

void SLL_removeNode(Node* Node) {
	free(Node);
}