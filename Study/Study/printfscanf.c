#include <stdio.h>

int main(){

	char name[256];
	printf("�̸��� ������?");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("���̴� ����̿���?");
	scanf_s("%d", &age);

	float weight;
	printf("������ ��ų�ο���?");
	scanf_s("%f", &weight);

	double height;
	printf("Ű�� ��cm�ΰ���?");
	scanf_s("%lf", &height);

	char content[256];
	printf("���˸��� �����ΰ���?");
	scanf_s("%s", content, sizeof(content));

	printf("========������ ������========\n");
	printf("�̸� : %s\n", name);
	printf("���� : %d��\n", age);
	printf("������ : %.2fkg\n", weight);
	printf("Ű : %.2lfcm\n", height);
	printf("���˸� : %s", content);

return 0;
}
