#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int condition_main() {
	/*int age = 25;

	if (age >= 20) {
		printf("일반인 입니다.\n");
	}
	else {
		printf("학생 입니다.\n");
	}*/

	/*int age = 8;
	if (age >= 8 && age <= 13) {
		printf("초등학생 입니다.\n");
	}
	else if (age >= 14 && age <= 16) {
		printf("중학생 입니다.\n");
	}
	else if (age >= 17 && age <= 19) {
		printf("고등학생 입니다.\n");
	} else {
		printf("성인입니다.\n");
	}*/

	/*for (int i = 1; i <= 30; i++) {

		if (i >= 6) {
			printf("나머지 학생은 집에 가세요.\n");
			break;
		}
		printf("%d번 학생은 조별 발표 준비를 하세요.\n", i);
	}*/

	/*for (int i = 1; i <= 30; i++) {
		if (i >= 6 && i <= 10) {
			if (i == 7) {
				printf("%d번 학생은 아파서 결석입니다.\n", i);
				continue;
			}
			printf("%d번 학생은 조별 발표 준비를 하세요.\n", i);
		}
	}*/

	//srand(time(NULL)); //난수 초기화 필수
	//int num = rand() % 3 + 1; // 0, 1, 2 => 0부터 시작
	//printf("%d", num);

	srand(time(NULL));
	int num = rand() % 100 + 1;
	int chance = 10;
	int choice = 0;
	printf("숫자 맞추기 게임 시작!! \n");
	printf("정답 기회 : %d회 \n\n\n", chance);

	while(chance > 0){
		printf("숫자를 입력 하세요.  ");
		scanf_s("%d", &choice);

		if (choice > num) {
			printf("DOWN↓.\n", choice);
		}
		else if (choice < num) {
			printf("UP↑.\n", choice);
		}
		else {
			printf("정답입니다.\n");
			break;
		}

		chance--;
	}
	return 0;
}