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

int len, prob, stm, c, m, z;
int c_aggro, m_aggro = 1;
int turn = 1;
int c_prob,z_prob, m_prob,m_m, m_act;
//1-1 �λ���1 �ڵ�� �Լ��� ���� ��ȿ�� ���� �Էµ� ������ �Է¹޴°ɷ� ����
void intro_len(void) {
	while (1) {
		printf("train length(15~50)>>");
		scanf_s("%d", &len);
		if (len <= LEN_MAX && len >= LEN_MIN) { break; }
	}
}

void intro_prob(void) {
	while (1) {
		printf("percentile probability 'p'(10~90)>>");
		scanf_s("%d", &prob);
		if (prob >= PROB_MIN && prob <= PROB_MAX) { break; }
	}
}
void train(void) {
	c = len - 6;
	z = len - 3;
	m = len - 2;
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
//1-2 �ù�, ���� ������
void c_move(void) {
	c_prob = rand() % 100;
	if (c_prob <= 100 - prob) {
		--c;
		++c_aggro;
		if (c_aggro > AGGRO_MAX) { c_aggro = AGGRO_MAX; }
		printf("citizen = %d -> %d(agrro: %d -> %d)\n", c + 1, c, c_aggro - 1, c_aggro);
	}
	else {
		--c_aggro;
		if (c_aggro < AGGRO_MIN) { c_aggro = AGGRO_MIN; }
		printf("citizen = stay %d(aggro: %d -> %d)\n", c, c_aggro + 1, c_aggro);
	}
}
void z_move(void){
	z_prob + rand() % 100;
	if (turn % 2 == 1) {
		if (z_prob <= prob) {
			--z;
			printf("zombie = %d -> %d\n", z + 1, z);
		}
		else if (m_act == 2) {
			printf("zombie = stay %d (can't move)\n", z);
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
//1-3 ������ ü�� �߰�, ������ �̵� �ڵ�
void intro_stm(void) {
	while (1) {
		printf("madongseok stamina(0~5)>>");
		scanf_s("%d", &stm);
		if (stm >= STM_MIN && stm <= STM_MAX) { break; }
	}
}
void m_move(void) {
	while (1) {
		printf("madongseok move(0:stay, 1:left)>>");
		scanf_s("%d", &m_m);
		if (m_m == 0 || m_m == 1) { break; }
	}
	printf("\n");
	if (m_m == 1) {
		++m_aggro;
		if (m_aggro > AGGRO_MAX) { m_aggro = AGGRO_MAX; }
	}
	else {
		--m_aggro;
		if (m_aggro < AGGRO_MIN)  { m_aggro = AGGRO_MIN; }
	}
}
void print_m_move(void) {
	if (m_aggro == 0) {
		printf("madongseok: stay %d(aggro: %d -> %d, stamina: %d)\n", m, m_aggro + 1, m_aggro, stm);
	}
	else { printf("madongseok: stay %d(aggro: %d -> %d, stamina: %d)\n", m, m_aggro - 1, m_aggro, stm); }
}
//1-4 ������ �ൿ
void m_action(void) {
	if (m == z + 1) {
		while (1) {
			printf("madongseok action(0.rest, 1.provoke, 2. pull)>>");
			scanf_s("%d", &m_act);
			if (m_act == 0 || m_act == 1 || m_act == 2) { break; }
		}
		printf("\n");
		if (m_act == 0) {
			printf("madongseok rest...\n");
			--m_aggro;
			++stm;
			if (stm > STM_MAX) { stm = STM_MAX; }
			if (m_aggro < AGGRO_MIN) { m_aggro = AGGRO_MIN; }
			printf("madongseok %d (aggro: %d -> %d, stamina: %d ->%d)\n", m, m_aggro + 1, m_aggro, stm - 1, stm);
		}
		else if (m_act == 1) {
			printf("madongseok provoked zombie...\n");
			printf("magongseok: %d (aggro: %d -> %d, stamina: %d\n", m, m_aggro, AGGRO_MAX, stm);
			m_aggro = AGGRO_MAX;
		}
		else {
			m_prob = rand() % 100;
			m_aggro += 2;
			--stm;
			if (stm < STM_MIN) {

			}
			if (m_aggro > AGGRO_MAX) { m_aggro = AGGRO_MAX; }
			if (m_prob <= 100 - prob) {
				printf("madongseok pulled zombie... Next turn, it can't move\n");
				printf("madongseok: %d(aggro: %d -> %d, stamina: %d -> %d)\n", m, m_aggro - 2, m_aggro, stm + 1, stm);
			}
			else {
				printf("madongseok failed to pull zombie\n");
				printf("madongseok: %d(aggro: %d -> %d, stamina: %d -> %d)\n", m, m_aggro - 2, m_aggro, stm + 1, stm);
			}
		}
	}
	else {
		if (m_act == 0) {
			printf("madongseok rest...\n");
			--m_aggro;
			if (m_aggro < AGGRO_MIN) { m_aggro = AGGRO_MIN; }
			++stm;
			if (stm > STM_MAX) { stm = STM_MAX; }
			printf("madongseok %d (aggro: %d -> %d, stamina: %d ->%d)\n", m, m_aggro + 1, m_aggro, stm - 1, stm);
		}
		else  {
			printf("madongseok provoked zombie...\n");
			printf("magongseok: %d (aggro: %d -> %d, stamina: %d\n", m, m_aggro, AGGRO_MAX, stm);
			m_aggro = AGGRO_MAX;
		}
	}
}
//1-5 ���� �ൿ
void z_action(void) {
	if (c < z) { printf("citizen does nothing.\n"); }
	if (z == c + 1) { 
		printf("GAME OVER! citizen dead...\n"); 
		exit(0);
	}
	else if (z == c + 1 && z == m - 1) {
		if (c_aggro < m_aggro) {
			--stm;
			if (stm = STM_MIN) {
				printf("GMME OVER! madongseok dead...\n");
				exit(0);
			}
			printf("Zombie attaked madongseok. (magongseok stamina: %d -> %d)\n", stm + 1, stm);
		}
		else if (c_aggro == m_aggro) {
			--stm;
			if (stm = STM_MIN) {
				printf("GMME OVER! madongseok dead...\n");
				exit(0);
			}
			printf("Zombie attaked madongseok. (aggro: %d vs %d, magongseok stamina: %d -> %d)\n", c_aggro, m_aggro,  stm + 1, stm);
		}
		else {
			printf("GAME OVER! citizen dead...\n");
			exit(0);
		}
	}
	else if (z == m - 1) {
		--stm;
		if (stm = STM_MIN) {
			printf("GMME OVER! madongseok dead...\n");
			exit(0);
		}
		printf("Zombie attaked madongseok. (magongseok stamina: %d -> %d)\n", stm + 1, stm);
	}
	else { printf("zombie attacked nobody\n"); }
}