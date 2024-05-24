#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define LEN_MIN 15 //���� ����
#define LEN_MAX 50
#define STM_MIN 0 //������ ü��
#define STM_MAX 5
#define PROB_MIN 10//Ȯ��
#define PROB_MAX 90
#define AGGRO_MIN 0 //��׷� ����
#define AGGRO_MAX 5
//������ �̵� ����
#define MOVE_LEFT 1
#define MOVE_STAY 0
//������ ���� ���
#define ATK_MOVE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2
//������ �ൿ
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

int len, prob, stm;
void intro_len(void) {
	while (1) {
		printf("train length(15~50)>>");
		scanf_s("%d", &len);
		if (len <= LEN_MAX && len >= LEN_MIN) { exit(0); }
	}
}
void intro_prob(void) {
	while (1) {
		printf("percentile probability 'p'(10~90)>>");
		scanf_s("%d", &prob);
		if (prob >= PROB_MIN && prob <= PROB_MAX) { exit(0); }
	}
}
void intro_train(void) {
	if (len >= 15 && len <= 50) {
		for (int i = 0; i < len; i++) {
			printf("#");
		}
		printf("\n");//���� ���� ���
		for (int i = 1; i <= len; i++) {
			if (i == 1 || i == len) {
				printf("#");
			}
			else if (i == len - 2) {
				printf("M");//������ ���
			}
			else if (i == len - 3) {
				printf("Z");//���� ���
			}
			else if (i == len - 6) {
				printf("C");// �ù� ���
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
		for (int i = 0; i < len; i++) {
			printf("#");
		}
	}
}
int turn = 1;
int c, m, z;
int a, b;
void move(void) {
	c = len - 6;
	z = len - 3;
	a = rand() % 100;
	if (a <= 100 - prob) {
		--c;// �ù� �����̰� ��ġ ����
	}
	b = rand() % 100;
	if (turn % 2 == 1) {
		if (b <= prob) {
			--z;//���� �����̰� ��ġ ����
		}
	}
}
void train(void) {
	if (len >= 15 && len <= 50) {
		for (int i = 0; i < len; i++) {
			printf("#");
		}
		printf("\n");//���� ���� ���
		for (int i = 1; i <= len; i++) {
			if (i == 1 || i == len) {
				printf("#");
			}
			else if (i == m) {
				printf("M");//������ ���
			}
			else if (i == z) {
				printf("Z");//���� ���
			}
			else if (i == c) {
				printf("C");// �ù� ���
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
		for (int i = 0; i < len; i++) {
			printf("#");
		}
		printf("\n");
	}
	printf("\n");
}
void print_move(void) {
	if (a <= 100 - prob) {
		printf("citizen = %d -> %d\n", c + 1, c);
	}
	else {
		printf("citizen = stay  %d\n", c);
	}
	if (turn % 2 == 1) {
		if (b <= prob) {
			printf("zombie = %d -> %d\n", z + 1, z);
		}
		else {
			printf("zombie = stay %d\n", z);
		}
	}
	else {
		printf("zombie = stay %d (cannot move) \n", z);
	}
	printf("\n");
	++turn;
}
int main(void) {

	return 0;
}
int main() {
	int test;
}