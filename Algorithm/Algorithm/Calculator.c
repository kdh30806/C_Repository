#include "Calculator.h"
#pragma warning(disable : 4996)

char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };

int IsNumber(char Cipher) { //char가 숫자인지 아닌지 구별하는 함수
	int i = 0;
	int ArrayLength = sizeof(NUMBER);

	for (i = 0; i < ArrayLength; i++) { //NUMBER에 들어있는 숫자들을 다 비교
		if (Cipher == NUMBER[i]) // 일치하면 리턴 1
			return 1;
	}
	//숫자가 아닐지 리턴 0
	return 0;
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE) {
	unsigned int i = 0;

	for (i = 0; 0 != Expression[i]; i++) { //Expression 이 0 => 빈 문자열이면 반복문 종료
		Token[i] = Expression[i]; //Token 초기화
		    
		if (IsNumber(Expression[i]) == 1) { //Expression 이 피연산자면 Type => OPERAND;
			*TYPE = OPERAND;

				if (IsNumber(Expression[i+1]) != 1) { //다음 문자가 피연산자(숫자)가 아니면 빠져나감
					break;
				}
		}
		else { //Expression이 연산자면 Type 에 연산자 대입
			*TYPE = Expression[i];
			break;
		}
	}
	Token[++i] = '\0'; //토큰은 문자열이기 때문에 끝에 빈문자열 넣어줘야함
	return i; //i = 1 리턴
}

int GetPriority(char Operator, int InStack) {
	int Priority = -1;

	switch (Operator)
	{
	case LEFT_PARENTHESIS:
		if (InStack) { //왼쪽 괄호 스택에 있으면
			Priority = 3; //제일 낮음
		}
		else { //없으면
			Priority = 0; //제일 높음
		}
		break;
	case MULTIPLY:
	case DIVIDE:
		Priority = 1;
		break;
	case PLUS:
	case MINUS:
		Priority = 2;
		break;
	}
	return Priority;
}

int IsPrior(char OperatorInStack, char OperatorInToken) {
	return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

void GetPostfix(char* InfixExpression, char* PostfixExpreesion) {
	LinkedListStack* Stack;

	char Token[32];
	int Type = -1;
	unsigned int Position = 0;
	unsigned int Length = strlen(InfixExpression);

	LLS_CreateStack(&Stack);

	while (Position < Length) //중위표현식 길이 까지 반복
	{
		Position += GetNextToken(&InfixExpression[Position], Token, &Type); //다음 토큰이 연산자인지 피연산자인지 구분후 1리턴

		if (Type == OPERAND) { //다음 토큰이 피연산자이면
			strcat(PostfixExpreesion, Token); //후위연산자 에 출력
			strcat(PostfixExpreesion, " "); //빈문자열 넣어줌
		}
		else if (Type == RIGHT_PARENTHESIS) { //다음 토큰 오른쪽 괄호이면(스택에는 이미 왼쪽 괄호가 들어가있는 상태)
			while (!LLS_IsEmpty(Stack)) //스택이 비어질때 까지 반복
			{
				Node* Popped = LLS_Pop(Stack); //스택에 최상단 노드 제거후 출력 => Popped

				if (Popped->Data[0] == LEFT_PARENTHESIS) { //최상단 노드의 데이터의 연산자가 왼쪽괄호면
					LLS_DestroyNode(Popped); //노드를 없애고
					break; //반복문 빠져나감
				}
				else { //최상단 노드의 데이터가 왼쪽 괄호가 아니면
					strcat(PostfixExpreesion, Popped->Data); //후위표기식에 데이터 추가
					LLS_DestroyNode(Popped); //추가후 해당 노드 파괴
				}//노드 파괴 후 노드가 남아 있으면 다시 반복
			}
		}
		else { //다음 토큰이 숫자도 오른쪽 괄호도 아니면 => 왼쪽 괄호 이거나 연산자이면
			while (!LLS_IsEmpty(Stack) && !IsPrior(LLS_Top(Stack)->Data[0], Token[0])) { //스택안의 연산자의 우선순위가 더 높으면 반복
				Node* Popped = LLS_Pop(Stack); //스택 최상단 노드 제거 후 출력

				if (Popped->Data[0] != LEFT_PARENTHESIS) { //최상단 노드의 데이터가 왼쪽괄호가 아니라면
					strcat(PostfixExpreesion, Popped->Data); //후기표현식에 출력
				}
				LLS_DestroyNode(Popped); //노드 파괴
			}
			LLS_Push(Stack, LLS_CreateNode(Token)); // 왼쪽괄호라면 노드에 담아서 스택에 푸쉬
		}

	} //중위표현식 다 읽었으면
		while (!LLS_IsEmpty(Stack)) //스택이 비어질때 까지 반복
		{
			Node* Popped = LLS_Pop(Stack); //최상단 노드 제거 후 출력

			if (Popped->Data[0] != LEFT_PARENTHESIS) { //최상단 노드의 데이터가 왼쪽괄호가 아니라면
				strcat(PostfixExpreesion, Popped->Data); //후위표현식에 출력
			}

			LLS_DestroyNode(Popped); //노드 파괴

		}
		LLS_DestroyStack(Stack); // 스택 파괴
}

double Calculate(char* PostfixExpression) { //후위표현식 계산기
	LinkedListStack* Stack;
	Node* ResultNode; //결과 값을 담을 노드

	double Result;
	char Token[32];
	int Type = -1;
	unsigned int Read = 0;
	unsigned int Length = strlen(PostfixExpression);

	LLS_CreateStack(&Stack);

	while (Read < Length) { //후위표현식 길이만큼 반복
		Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

		if (Type == SPACE) { //빈 공간 스페이스 일 경우 그냥 진행
			continue;
		}

		if (Type == OPERAND) { //다음 토큰 숫자이면
			Node* NewNode = LLS_CreateNode(Token);
			LLS_Push(Stack, NewNode); //스택에 저장
		}
		else { //다음 토큰 연산자이면
			char ResultString[32];
			double Operator1, Operator2, TempResult = 0.0;
			Node* OperatorNode;

			OperatorNode = LLS_Pop(Stack); //스택에서 숫자하나 꺼냄
			Operator2 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);

			OperatorNode = LLS_Pop(Stack); //스택에서 숫자하나 꺼냄
			Operator1 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);

			switch (Type)
			{
			case PLUS: TempResult = Operator1 + Operator2; break;
			case MINUS: TempResult = Operator1 - Operator2; break;
			case MULTIPLY: TempResult = Operator1 * Operator2; break;
			case DIVIDE: TempResult = Operator1 / Operator2; break;
			}

			gcvt(TempResult, 10, ResultString); //문자열로 변환
			LLS_Push(Stack, LLS_CreateNode(ResultString)); //스택에 결과값 푸쉬
		}
	}
	// 연산 끝나면
	ResultNode = LLS_Pop(Stack); //스택에 저장되어 있는 최종 결과 값 꺼냄
	Result = atof(ResultNode->Data); //스택에 저장되어있는 문자열을 실수로 변환
	LLS_DestroyNode(ResultNode); // 노드 파괴

	LLS_DestroyStack(Stack); // 스택 파괴

	return Result;
}