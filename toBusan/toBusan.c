#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define LEN_MIN 15 //기차 길이
#define LEN_MAX 50
#define STM_MIN 0 //마동석 체력
#define STM_MAX 5
#define PROB_MIN 10//확률
#define PROB_MAX 90
#define AGGRO_MIN 0 //어그로 범위
#define AGGRO_MAX 5
//마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0
//좀비의 공격 대상
#define ATK_MOVE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2
//마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

int len, prob, stm, c, m, z;
int turn = 1;
int a, b;
void intro_len(void) {
	while (1) {
		printf("train length(15~50)>>");
		scanf_s("%d", &len);
		if (len <= LEN_MAX && len >= LEN_MIN) { break; }
	}
	c = len - 6;
}
void intro_prob(void) {
	while (1) {
		printf("percentile probability 'p'(10~90)>>");
		scanf_s("%d", &prob);
		if (prob >= PROB_MIN && prob <= PROB_MAX) { break; }
	}
	z = len - 3;
}
void intro_stm(void) {
	while (1) {
		printf("madongseok stamina(0~5)>>");
		scanf_s("%d", &stm);
		if (stm >= STM_MIN && stm <= STM_MAX) { break; }
	}
	m = len - 2;
}
void intro_train(void) {
	if (len >= 15 && len <= 50) {
		for (int i = 0; i < len; i++) {
			printf("#");
		}
		printf("\n");//기차 길이 출력
		for (int i = 1; i <= len; i++) {
			if (i == 1 || i == len) {
				printf("#");
			}
			else if (i == len - 2) {
				printf("M");//마동석 출력
			}
			else if (i == len - 3) {
				printf("Z");//좀비 출력
			}
			else if (i == len - 6) {
				printf("C");// 시민 출력
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
void move(void) {
	c = len - 6;
	z = len - 3;
	a = rand() % 100;
	if (a <= 100 - prob) {
		--c;// 시민 움직이고 위치 저장
	}
	b = rand() % 100;
	if (turn % 2 == 1) {
		if (b <= prob) {
			--z;//좀비 움직이고 위치 저장
		}
	}
}
void train(void) {
	if (len >= 15 && len <= 50) {
		for (int i = 0; i < len; i++) {
			printf("#");
		}
		printf("\n");//기차 길이 출력
		for (int i = 1; i <= len; i++) {
			if (i == 1 || i == len) {
				printf("#");
			}
			else if (i == m) {
				printf("M");//마동석 출력
			}
			else if (i == z) {
				printf("Z");//좀비 출력
			}
			else if (i == c) {
				printf("C");// 시민 출력
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
	intro_len();
	intro_prob();
	intro_stm();
	train();
	move();
	train();
	print_move();
	return 0;
}