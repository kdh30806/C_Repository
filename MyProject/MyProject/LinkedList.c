#include <stdint.h>
#include <malloc.h>

typedef struct tagNode {
	int data;
	struct tagNode* NextNode;
} Node;


Node* SLL_creatNode(int newData) {
	//c언어는 자동 메모리와 자유 메모리가 있음
	// 자동 메모리 = {} 벗어나면 사라지는 메모리
	// 자유 메모리 = 자유롭게 메모리 할당 가능 => 자바에서는 가비지 컬렉터가 알아서 정리 해주지만 c언어에서는 관리 해주어야함
	Node* newNode = (Node*)malloc(sizeof(Node)); //malloc => 자유 메모리에 newNode 포인터 저장

	newNode->data = newData;
	newNode->NextNode = NULL;

	return newNode;
}

void SLL_removeNode(Node* Node) {
	free(Node);
}