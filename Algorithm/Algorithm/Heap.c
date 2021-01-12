#include "Heap.h"

Heap* HEAP_Create(int IntitialSize)
{
	Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
	NewHeap->Capacity = IntitialSize;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * NewHeap->Capacity);

	printf("size : %d\n", sizeof(HeapNode));

	return NewHeap;
}

void  HEAP_Destroy(Heap* H)
{
	free(H->Nodes);
	free(H);
}


void HEAP_SwapNodes(Heap* H, int Index1, int Index2) {
	int CopySize = sizeof(HeapNode);
	HeapNode* Temp = (HeapNode*)malloc(CopySize);

	memcpy(Temp, &H->Nodes[Index1], CopySize);
	memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
	memcpy(&H->Nodes[Index2], Temp, CopySize);

	free(Temp);
}

int HEAP_GetParent(int Index) {
	return (int)((Index - 1) / 2);
}

void HEAP_Insert(Heap* H, int NewData) {
	int CurrentPosition = H->UsedSize; //마지막 인덱스 위치(최고 깊이, 최우측 노드)
	int ParentPosition = HEAP_GetParent(CurrentPosition); //부모 노드 구하기 

	if (H->UsedSize == H->Capacity) {
		H->Capacity *= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity); // 메모리 크기 변경
	}

	H->Nodes[CurrentPosition].Data = NewData; // 데이터 넣기

	while (CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data) { // 부모노드가 더 클때
		HEAP_SwapNodes(H, CurrentPosition, ParentPosition); // 스왑

		CurrentPosition = ParentPosition; // 인덱스도 스왑
		ParentPosition = HEAP_GetParent(CurrentPosition); // 인덱스도 스왑
	}

	H->UsedSize++;
}

int HEAP_GetLeftChild(int Index) {
	return (2 * Index) + 1;
}

void HEAP_DeleteMin(Heap* H, HeapNode* Root) {
	int ParentPosition = 0;
	int LeftPosition = 0;
	int RightPosition = 0;

	memcpy(Root, &H->Nodes[0], sizeof(HeapNode)); // Root 에 최소값 저장
	memset(&H->Nodes[0], 0, sizeof(HeapNode));

	H->UsedSize--;
	HEAP_SwapNodes(H, 0, H->UsedSize); // 루트 노드와 마지막 노드 스왑

	LeftPosition = HEAP_GetLeftChild(0);
	RightPosition = LeftPosition + 1;

	while (1) {
		int SelectedChild = 0; // 셀렉트된 노드는 자식 노드중 작은 노드

		if (LeftPosition >= H->UsedSize) {
			break;
		}

		if (RightPosition >= H->UsedSize) {
			SelectedChild = LeftPosition;
		}

		else {
			if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data) {
				SelectedChild = RightPosition;
			}
			else {
				SelectedChild = LeftPosition;
			}
		}

		if (H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data) { // 부모 노드와 선택된 노드 비교
			HEAP_SwapNodes(H, ParentPosition, SelectedChild); // 부모 노드가 더 크면 스왑
			ParentPosition = SelectedChild; // 스왑 후 다음 노드 이동을 위해 셀렉트된 노드를 부모노드로 지정
		}
		else { // 아니면 빠져나감
			break;
		}

		LeftPosition = HEAP_GetLeftChild(ParentPosition); // 다음 노드로 이동하여
		RightPosition = LeftPosition + 1;
	}

	if (H->UsedSize < (H->Capacity / 2)) {
		H->Capacity /= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}
}

void      HEAP_PrintNodes(Heap* H)
{
	int i = 0;
	for (i = 0; i < H->UsedSize; i++)
	{
		printf("%d ", H->Nodes[i].Data);
	}
	printf("\n");
}