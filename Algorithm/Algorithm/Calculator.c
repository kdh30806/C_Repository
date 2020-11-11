#include "Calculator.h"
#pragma warning(disable : 4996)

char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };

int IsNumber(char Cipher) { //char�� �������� �ƴ��� �����ϴ� �Լ�
	int i = 0;
	int ArrayLength = sizeof(NUMBER);

	for (i = 0; i < ArrayLength; i++) { //NUMBER�� ����ִ� ���ڵ��� �� ��
		if (Cipher == NUMBER[i]) // ��ġ�ϸ� ���� 1
			return 1;
	}
	//���ڰ� �ƴ��� ���� 0
	return 0;
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE) {
	unsigned int i = 0;

	for (i = 0; 0 != Expression[i]; i++) { //Expression �� 0 => �� ���ڿ��̸� �ݺ��� ����
		Token[i] = Expression[i]; //Token �ʱ�ȭ
		    
		if (IsNumber(Expression[i]) == 1) { //Expression �� �ǿ����ڸ� Type => OPERAND;
			*TYPE = OPERAND;

				if (IsNumber(Expression[i+1]) != 1) { //���� ���ڰ� �ǿ�����(����)�� �ƴϸ� ��������
					break;
				}
		}
		else { //Expression�� �����ڸ� Type �� ������ ����
			*TYPE = Expression[i];
			break;
		}
	}
	Token[++i] = '\0'; //��ū�� ���ڿ��̱� ������ ���� ���ڿ� �־������
	return i; //i = 1 ����
}

int GetPriority(char Operator, int InStack) {
	int Priority = -1;

	switch (Operator)
	{
	case LEFT_PARENTHESIS:
		if (InStack) { //���� ��ȣ ���ÿ� ������
			Priority = 3; //���� ����
		}
		else { //������
			Priority = 0; //���� ����
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

	while (Position < Length) //����ǥ���� ���� ���� �ݺ�
	{
		Position += GetNextToken(&InfixExpression[Position], Token, &Type); //���� ��ū�� ���������� �ǿ��������� ������ 1����

		if (Type == OPERAND) { //���� ��ū�� �ǿ������̸�
			strcat(PostfixExpreesion, Token); //���������� �� ���
			strcat(PostfixExpreesion, " "); //���ڿ� �־���
		}
		else if (Type == RIGHT_PARENTHESIS) { //���� ��ū ������ ��ȣ�̸�(���ÿ��� �̹� ���� ��ȣ�� ���ִ� ����)
			while (!LLS_IsEmpty(Stack)) //������ ������� ���� �ݺ�
			{
				Node* Popped = LLS_Pop(Stack); //���ÿ� �ֻ�� ��� ������ ��� => Popped

				if (Popped->Data[0] == LEFT_PARENTHESIS) { //�ֻ�� ����� �������� �����ڰ� ���ʰ�ȣ��
					LLS_DestroyNode(Popped); //��带 ���ְ�
					break; //�ݺ��� ��������
				}
				else { //�ֻ�� ����� �����Ͱ� ���� ��ȣ�� �ƴϸ�
					strcat(PostfixExpreesion, Popped->Data); //����ǥ��Ŀ� ������ �߰�
					LLS_DestroyNode(Popped); //�߰��� �ش� ��� �ı�
				}//��� �ı� �� ��尡 ���� ������ �ٽ� �ݺ�
			}
		}
		else { //���� ��ū�� ���ڵ� ������ ��ȣ�� �ƴϸ� => ���� ��ȣ �̰ų� �������̸�
			while (!LLS_IsEmpty(Stack) && !IsPrior(LLS_Top(Stack)->Data[0], Token[0])) { //���þ��� �������� �켱������ �� ������ �ݺ�
				Node* Popped = LLS_Pop(Stack); //���� �ֻ�� ��� ���� �� ���

				if (Popped->Data[0] != LEFT_PARENTHESIS) { //�ֻ�� ����� �����Ͱ� ���ʰ�ȣ�� �ƴ϶��
					strcat(PostfixExpreesion, Popped->Data); //�ı�ǥ���Ŀ� ���
				}
				LLS_DestroyNode(Popped); //��� �ı�
			}
			LLS_Push(Stack, LLS_CreateNode(Token)); // ���ʰ�ȣ��� ��忡 ��Ƽ� ���ÿ� Ǫ��
		}

	} //����ǥ���� �� �о�����
		while (!LLS_IsEmpty(Stack)) //������ ������� ���� �ݺ�
		{
			Node* Popped = LLS_Pop(Stack); //�ֻ�� ��� ���� �� ���

			if (Popped->Data[0] != LEFT_PARENTHESIS) { //�ֻ�� ����� �����Ͱ� ���ʰ�ȣ�� �ƴ϶��
				strcat(PostfixExpreesion, Popped->Data); //����ǥ���Ŀ� ���
			}

			LLS_DestroyNode(Popped); //��� �ı�

		}
		LLS_DestroyStack(Stack); // ���� �ı�
}

double Calculate(char* PostfixExpression) { //����ǥ���� ����
	LinkedListStack* Stack;
	Node* ResultNode; //��� ���� ���� ���

	double Result;
	char Token[32];
	int Type = -1;
	unsigned int Read = 0;
	unsigned int Length = strlen(PostfixExpression);

	LLS_CreateStack(&Stack);

	while (Read < Length) { //����ǥ���� ���̸�ŭ �ݺ�
		Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

		if (Type == SPACE) { //�� ���� �����̽� �� ��� �׳� ����
			continue;
		}

		if (Type == OPERAND) { //���� ��ū �����̸�
			Node* NewNode = LLS_CreateNode(Token);
			LLS_Push(Stack, NewNode); //���ÿ� ����
		}
		else { //���� ��ū �������̸�
			char ResultString[32];
			double Operator1, Operator2, TempResult = 0.0;
			Node* OperatorNode;

			OperatorNode = LLS_Pop(Stack); //���ÿ��� �����ϳ� ����
			Operator2 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);

			OperatorNode = LLS_Pop(Stack); //���ÿ��� �����ϳ� ����
			Operator1 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);

			switch (Type)
			{
			case PLUS: TempResult = Operator1 + Operator2; break;
			case MINUS: TempResult = Operator1 - Operator2; break;
			case MULTIPLY: TempResult = Operator1 * Operator2; break;
			case DIVIDE: TempResult = Operator1 / Operator2; break;
			}

			gcvt(TempResult, 10, ResultString); //���ڿ��� ��ȯ
			LLS_Push(Stack, LLS_CreateNode(ResultString)); //���ÿ� ����� Ǫ��
		}
	}
	// ���� ������
	ResultNode = LLS_Pop(Stack); //���ÿ� ����Ǿ� �ִ� ���� ��� �� ����
	Result = atof(ResultNode->Data); //���ÿ� ����Ǿ��ִ� ���ڿ��� �Ǽ��� ��ȯ
	LLS_DestroyNode(ResultNode); // ��� �ı�

	LLS_DestroyStack(Stack); // ���� �ı�

	return Result;
}