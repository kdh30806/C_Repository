#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int condition_main() {
	/*int age = 25;

	if (age >= 20) {
		printf("�Ϲ��� �Դϴ�.\n");
	}
	else {
		printf("�л� �Դϴ�.\n");
	}*/

	/*int age = 8;
	if (age >= 8 && age <= 13) {
		printf("�ʵ��л� �Դϴ�.\n");
	}
	else if (age >= 14 && age <= 16) {
		printf("���л� �Դϴ�.\n");
	}
	else if (age >= 17 && age <= 19) {
		printf("����л� �Դϴ�.\n");
	} else {
		printf("�����Դϴ�.\n");
	}*/

	/*for (int i = 1; i <= 30; i++) {

		if (i >= 6) {
			printf("������ �л��� ���� ������.\n");
			break;
		}
		printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���.\n", i);
	}*/

	/*for (int i = 1; i <= 30; i++) {
		if (i >= 6 && i <= 10) {
			if (i == 7) {
				printf("%d�� �л��� ���ļ� �Ἦ�Դϴ�.\n", i);
				continue;
			}
			printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���.\n", i);
		}
	}*/

	//srand(time(NULL)); //���� �ʱ�ȭ �ʼ�
	//int num = rand() % 3 + 1; // 0, 1, 2 => 0���� ����
	//printf("%d", num);

	srand(time(NULL));
	int num = rand() % 100 + 1;
	int chance = 10;
	int choice = 0;
	printf("���� ���߱� ���� ����!! \n");
	printf("���� ��ȸ : %dȸ \n\n\n", chance);

	while(chance > 0){
		printf("���ڸ� �Է� �ϼ���.  ");
		scanf_s("%d", &choice);

		if (choice > num) {
			printf("DOWN��.\n", choice);
		}
		else if (choice < num) {
			printf("UP��.\n", choice);
		}
		else {
			printf("�����Դϴ�.\n");
			break;
		}

		chance--;
	}
	return 0;
}