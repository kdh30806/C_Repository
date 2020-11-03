#include <stdio.h>

int main(){

	char name[256];
	printf("이름이 뭐에요?");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("나이는 몇살이에요?");
	scanf_s("%d", &age);

	float weight;
	printf("몸무게 몇킬로에요?");
	scanf_s("%f", &weight);

	double height;
	printf("키는 몇cm인가요?");
	scanf_s("%lf", &height);

	char content[256];
	printf("범죄명은 무엇인가요?");
	scanf_s("%s", content, sizeof(content));

	printf("========용의자 프로필========\n");
	printf("이름 : %s\n", name);
	printf("나이 : %d살\n", age);
	printf("몸무게 : %.2fkg\n", weight);
	printf("키 : %.2lfcm\n", height);
	printf("범죄명 : %s", content);

return 0;
}
