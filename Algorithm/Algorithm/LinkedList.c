#include <stdio.h>
#include <malloc.h>

typedef struct tagNode {
	int data;
	struct tagNode* NextNode;
} Node;
Node MyNode;

Node* SLL_creatNode(int newData) {
	//c언어는 자동 메모리와 자유 메모리가 있음
	// 자동 메모리 = {} 벗어나면 사라지는 메모리
	// 자유 메모리 = 자유롭게 메모리 할당 가능 => 자바에서는 가비지 컬렉터가 알아서 정리 해주지만 c언어에서는 관리 해주어야함
	Node* newNode = (Node*)malloc(sizeof(Node)); //malloc => 자유 메모리에 newNode 포인터 저장

	newNode->data = newData;
	newNode->NextNode = NULL;

	return newNode;
}

void SLL_destroyNode(Node* Node) {
	free(Node);
}

void SLL_appendNode(Node** head, Node* newNode) {
	if ((*head) == NULL) { //헤드가 널이면
		*head = newNode; //새로 생성한 노드가 헤드노드
	}
	else { //헤드가 널이 아니면
		Node* tail = (*head); //헤드노드 대입
		while (tail->NextNode != NULL) { //헤드노드의 nextNode가 널이 아닐 때까지
			tail = tail->NextNode; //tail은 다음노드를 가르킴 =>널이 나올때까지 찾아간다
		}
		tail->NextNode = newNode; //널이 나왔을 때 그 자리에 새로 생성한 노드를 대입
	}
}

Node* SLL_getNodeAt(Node* head, int location) { //파라미터로 링크드 리스트와 인덱션 번호 전달
	Node* current = head; //location이 0이면 head 출력

	while (current != NULL && (--location) >= 0) { //널이 아닐때 까지와 인덱션 번호가 마이너스 이동하며 마이너스가 되면 스탑
		current = current->NextNode;
	}

	return current;
}

void removeNode(Node** head, Node* remove) {
	if (*head == remove) {
		*head = remove->NextNode;
	}
	else {
		Node* current = *head;
		while (current != NULL && current->NextNode != remove) {
			current = current->NextNode;
		}

		if (current != NULL) {
			current->NextNode = remove->NextNode;
		}
	}
}

void SLL_insertAfter(Node* current, Node* newNode) {
	newNode->NextNode = current->NextNode;
	current->NextNode = newNode;
}

void SLL_insertNewHead(Node** head, Node* newHead) {

	if (head == NULL) {
		(*head) = newHead;
	}else {
		newHead->NextNode = (*head)->NextNode;
		*head = newHead;
	}

}

int SLL_getNodeCount(Node* head) {
	int count = 0;
	Node* current = head;
	while (current != NULL) {
		current = current->NextNode;
		count++;
	}
	return count;
}

void SLL_insertBefore(Node** head, Node* current, Node* newNode) {

	if ((*head) == NULL) {
		printf("비어있는 노드 입니다.");
		return;
	}
	else if ((*head) == current) {
		newNode->NextNode = (*head);
		*head = newNode;
	}
	else {
		Node* prev = NULL;
		Node* now = *head;
		while (now->NextNode != NULL) {
			prev = now;
			now = now->NextNode;

			if (now == current) {
				break;
			}
		}
		newNode->NextNode = now;
		prev->NextNode = newNode;
	}
}

int main() {

	Node* linkedList = NULL; //링크드리스트 선언
	Node* newNode = NULL; //새로 생성한 노드를 담을 변수

	newNode = SLL_creatNode(177); //데이터 177을 담은 새로운 노드 생성
	SLL_appendNode(&linkedList, newNode); //링크드 리스트에 연결 하면서 헤더가 됨

	newNode = SLL_creatNode(150); // 데이터 150을 담은 새로운 노드 생성
	SLL_appendNode(&linkedList, newNode); //링크드 리스트에 연결

	newNode = SLL_creatNode(999);
	SLL_insertNewHead(&linkedList, newNode);

	newNode = SLL_creatNode(0);
	SLL_appendNode(&linkedList, newNode);

	newNode = SLL_creatNode(-1);
	SLL_appendNode(&linkedList, newNode);

	newNode = SLL_creatNode(-2);
	SLL_appendNode(&linkedList, newNode);

	newNode = SLL_creatNode(-15);
	SLL_insertBefore(&linkedList, SLL_getNodeAt(linkedList, 3), newNode);

	for (int i = 0; i < SLL_getNodeCount(linkedList); i++) {
		Node* cuurent = SLL_getNodeAt(linkedList, i);
		printf("List[%d] 의 데이터 값은 %d\n", i, cuurent->data);
	}

	return 0;
}