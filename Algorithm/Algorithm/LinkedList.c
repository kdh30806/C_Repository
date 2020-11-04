#include <stdio.h>
#include <malloc.h>

typedef struct tagNode {
	int data;
	struct tagNode* NextNode;
} Node;
Node MyNode;

Node* SLL_creatNode(int newData) {
	//c���� �ڵ� �޸𸮿� ���� �޸𸮰� ����
	// �ڵ� �޸� = {} ����� ������� �޸�
	// ���� �޸� = �����Ӱ� �޸� �Ҵ� ���� => �ڹٿ����� ������ �÷��Ͱ� �˾Ƽ� ���� �������� c������ ���� ���־����
	Node* newNode = (Node*)malloc(sizeof(Node)); //malloc => ���� �޸𸮿� newNode ������ ����

	newNode->data = newData;
	newNode->NextNode = NULL;

	return newNode;
}

void SLL_destroyNode(Node* Node) {
	free(Node);
}

void SLL_appendNode(Node** head, Node* newNode) {
	if ((*head) == NULL) { //��尡 ���̸�
		*head = newNode; //���� ������ ��尡 �����
	}
	else { //��尡 ���� �ƴϸ�
		Node* tail = (*head); //����� ����
		while (tail->NextNode != NULL) { //������� nextNode�� ���� �ƴ� ������
			tail = tail->NextNode; //tail�� ������带 ����Ŵ =>���� ���ö����� ã�ư���
		}
		tail->NextNode = newNode; //���� ������ �� �� �ڸ��� ���� ������ ��带 ����
	}
}

Node* SLL_getNodeAt(Node* head, int location) { //�Ķ���ͷ� ��ũ�� ����Ʈ�� �ε��� ��ȣ ����
	Node* current = head; //location�� 0�̸� head ���

	while (current != NULL && (--location) >= 0) { //���� �ƴҶ� ������ �ε��� ��ȣ�� ���̳ʽ� �̵��ϸ� ���̳ʽ��� �Ǹ� ��ž
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
		printf("����ִ� ��� �Դϴ�.");
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

	Node* linkedList = NULL; //��ũ�帮��Ʈ ����
	Node* newNode = NULL; //���� ������ ��带 ���� ����

	newNode = SLL_creatNode(177); //������ 177�� ���� ���ο� ��� ����
	SLL_appendNode(&linkedList, newNode); //��ũ�� ����Ʈ�� ���� �ϸ鼭 ����� ��

	newNode = SLL_creatNode(150); // ������ 150�� ���� ���ο� ��� ����
	SLL_appendNode(&linkedList, newNode); //��ũ�� ����Ʈ�� ����

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
		printf("List[%d] �� ������ ���� %d\n", i, cuurent->data);
	}

	return 0;
}