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

int len, prob, stm, c, m, z, c_aggro, m_aggro;
int turn = 1;
int c_prob,z_prob, m_prob, m_act;
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
void cz_move(void) {
	c = len - 6;
	z = len - 3;
	c_aggro = 0;
	c_prob = rand() % 100;
	if (c_prob <= 100 - prob) {
		--c;// �ù� �����̰� ��ġ ����
		++c_aggro;
	}
	else {
		--c_aggro;
	}
	z_prob = rand() % 100;
	if (turn % 2 == 1) {
		if (z_prob <= prob) {
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
void print_move_cz(void) {
	if (c_prob <= 100 - prob) {
		printf("citizen = %d -> %d(agrro: %d)\n", c + 1, c, c_aggro);
	}
	else {
		printf("citizen = stay  %d\n", c);
	}
	if (turn % 2 == 1) {
		if (z_prob <= prob) {
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
void m_move(void){
	m = len - 2;
	while(1){
		printf("madongseok move(0:stay, 1:left)>>"); 
		scanf_s("%d", &m_prob);
		if (m_prob == 0||m_prob==1) { break; }
	}
	if (m_prob == 1) {
		--m;
		++m_aggro;
	}
	else { --m_aggro; }
}
void m_action(void) {
	priintf("madongseok action(0.rest, 1.provoke)>>");
	scanf_s("%d", &m_act);
	if (m_act == 0) { 
		printf("madongseok rest...\n");
		--m_aggro;
		++stm;
		printf("madongseok %d (aggro: %d -> %d, stamina: %d ->%d", m_aggro + 1, m_aggro, stm - 1, stm);
	}
}
void print_m_move(void) {
	if (m_prob == 0) {
		printf("madongseok: stay %d(aggro: %d -> %d, stamina: %d", m, m_aggro,m_aggro + 1, stm);
	}
}
void action(void) {
	if (c < z) { printf("citizen does nothing.");	}
	if (z > c || z < m) {	printf("zombie attcked nobody.\n");	}
	else if (z == c + 1) {printf ("GAME OVER!citizen dead..."); }

}
void win(void) {
	if (c == 1) {
		printf(" YOU WIN!");
	}
}
int main(void) {
	intro_len();
	intro_prob();
	intro_stm();
	train();//�ʱ� ����
	cz_move();
	train();//������ ����1
	print_move_cz();
	m_move();
	train();
	return 0;
}