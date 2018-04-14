#include <stdio.h>
#define STACK_SIZE 100
#define SUCCESS 1
#define FAILURE 0
#define null -1

#define N 8	//���͕��͂̒P�ꐔ
char *input_words[N] = { "the","man","broke","a","desk","with","a","drawer" };	//���͕���
//char *dic_rule[N] = { "det1","n1","v1","det2","n2","prep1","det3","n3" };	//���͕��͂̎����K��

#define det 0	//�\���K���𐔎��ƑΉ��t��
#define n 1
#define v 2
#define prep 3
#define NP 4
#define VP 5
#define PP 6
#define S 7
#define NP2 8
#define VP2 9

#define the 0	//�����K���𐔎��ƑΉ��t��
#define man 1
#define broke 2
#define a 3
#define desk 4
#define with 5
#define drawer 7

struct arc {
	int		start;
	int		end;
	int		period;
	bool	dic_flag;	//�����K���ɓK�p�����ꍇ�̃t���O
	int		parts_num;	//�i�����ނ̑Ή��ԍ�
	int		spel;
	int		ID1;	//�s�����ʂ�ID(����)
	int		ID2;	//�s�����ʂ�ID2(����)
	bool	arc_status;	//�ʂ̕��ށC�s������:true�C������:false
};

int push(arc push_data);
int pop(arc *pop_data);
bool check(arc data, int count);
int SearchWant(arc retdata);
void S_expression(arc data);	//S��(S-expression)�̐���

arc stack_data[STACK_SIZE];
int stack_num;

arc arc_table[STACK_SIZE];

int main(void) {
	int count, i, wantpart;
	arc send;

	//�����K���̓K�p
	send = { 7, 8, 1, true, n, drawer, null, null ,true };
	push(send);	//drawer
	send = { 6, 7, 1, true, det, a, null, null, true };
	push(send);	//a
	send = { 5, 6, 1, true, prep, with, null, null,  true };
	push(send);	//with
	send = { 4, 5, 1, true, n, desk, null, null,  true };
	push(send);	//desk
	send = { 3, 4, 1, true, det, a, null, null,  true };
	push(send);	//a
	send = { 2, 3, 1, true, v, broke, null, null, true };
	push(send);	//broke
	send = { 1, 2, 1, true, n, man, null, null,  true };
	push(send);	//man
	send = { 0, 1, 1, true, det, the, null, null, true };
	push(send);	//the
	//�J�n�L��S�̊����ʂ�ǉ�
	send = { 0, 0, 0, false, S, null, null, null,  false };	//�\���K���̑Ή��ԍ������
	push(send);

	//�A�W�F���_����ɂȂ�܂ňȉ��̑���𑱂���
	for (count = 0; stack_num != 0; count++) {
		//�ʂ̑I��
		pop(&arc_table[count]);	//�`���[�g�ɒǉ�
		//�ʂ̌���
		if (arc_table[count].arc_status == false) {	//�ʂ������ʂ̂Ƃ��E�ɂ���s�����ǂ�T���Č���
			wantpart = SearchWant(arc_table[count]);	//�ʂ�n�����牽��K�v�Ƃ��Ă邩�Ԃ�
			for (i = 0; i < count; i++) {	//�`���[�g������
				if (arc_table[i].arc_status == true && arc_table[i].start == arc_table[count].end) {	//�s�����ʂł��A�ʂ��E�Ȃ��
					if (wantpart != NP && wantpart != VP) {	//wantpart�����򂷂���̂łȂ��Ƃ�
						if (wantpart == arc_table[i].parts_num) {
							//�������Ăł����V�����ʂ�push
							if (arc_table[count].period == 0) {
								send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, i, null, false };
								//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
								if (check(send, count)) { push(send); }
							}
							else if (arc_table[count].period == 1) {
								send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, arc_table[count].ID1, i, true };
								//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
								if (check(send, count)) { push(send); }
							}
						}
					}
					else {
						if (wantpart == NP) {
							if (arc_table[i].parts_num == NP || arc_table[i].parts_num == NP2) {
								//�������Ăł����V�����ʂ�push
								if (arc_table[count].period == 0) {
									send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, i, null, false };
									//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
									if (check(send, count)) { push(send); }
								}
								else if (arc_table[count].period == 1) {
									send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, arc_table[count].ID1, i, true };
									//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
									if (check(send, count)) { push(send); }
								}
							}
						}
						if (wantpart == VP) {
							if (arc_table[i].parts_num == VP || arc_table[i].parts_num == VP2) {
								//�������Ăł����V�����ʂ�push
								if (arc_table[count].period == 0) {
									send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, i, null, false };
									//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
									if (check(send, count)) { push(send); }
								}
								else if (arc_table[count].period == 1) {
									send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, arc_table[count].ID1, i, true };
									//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
									if (check(send, count)) { push(send); }
								}
							}
						}
					}
				}
			}
		}
		if (arc_table[count].arc_status == true) {	//�ʂ��s�����ʂ̂Ƃ����ɂ��銈���ǂ�T���Č���
			for (i = 0; i < count; i++) {	//�`���[�g������
				if (arc_table[i].arc_status == false && arc_table[i].end == arc_table[count].start) {	//�����ʂł��A�ʂ����Ȃ��
					wantpart = SearchWant(arc_table[i]);
					if (wantpart != NP && wantpart != VP) {//wantpart�����򂷂���̂łȂ��Ƃ�
						if (wantpart == arc_table[count].parts_num) {
							//�������Ăł����V�����ʂ�push
							if (arc_table[i].period == 0) {
								send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, count, null, false };
								//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
								if (check(send, count)) push(send);
							}
							else if (arc_table[i].period == 1) {
								send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, arc_table[i].ID1, count, true };
								//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
								if (check(send, count)) push(send);
							}
						}
					}
					else {
						if (wantpart == NP) {
							if (arc_table[count].parts_num == NP || arc_table[count].parts_num == NP2) {//
																									//�������Ăł����V�����ʂ�push
								if (arc_table[i].period == 0) {
									send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, count, null, false };
									//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
									if (check(send, count)) push(send);
								}
								else if (arc_table[i].period == 1) {
									send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, arc_table[i].ID1, count, true };
									//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
									if (check(send, count)) push(send);
								}
							}
						}
						if (wantpart == VP) {
							if (arc_table[count].parts_num == VP || arc_table[count].parts_num == VP2) {
								//�������Ăł����V�����ʂ�push
								if (arc_table[i].period == 0) {
									send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, count, null, false };
									//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
									if (check(send, count)) push(send);
								}
								else if (arc_table[i].period == 1) {
									send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, arc_table[i].ID1, count, true };
									//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
									if (check(send, count)) push(send);
								}
							}
						}
					}
				}
			}
		}

		//�V�����ʂ̒��
		if (arc_table[count].arc_status == false && SearchWant(arc_table[count])>3) {	//�ʂ�������[i,j,X��a.YB]�̂Ƃ��AY�����ӂƂ���K��Y��y(�����K��������)�������[j,j,Y��.y]������Ēǉ�
			//�������ʂ����Ƀ`���[�g�܂��̓A�W�F���_�ɂ���Ƃ��͒ǉ����Ȃ�
			wantpart = SearchWant(arc_table[count]);
			if (wantpart == NP) {
				send = { arc_table[count].end, arc_table[count].end, 0, false, NP, null, null, null, false };
				if (check(send, count)) { push(send); }
				send = { arc_table[count].end, arc_table[count].end, 0, false, NP2, null, null, null, false };
				if (check(send, count)) { push(send); }
			}
			if (wantpart == VP) {
				send = { arc_table[count].end, arc_table[count].end, 0, false, VP, null, null, null, false };
				if (check(send, count)) { push(send); }
				send = { arc_table[count].end, arc_table[count].end, 0, false, VP2, null, null, null, false };
				if (check(send, count)) { push(send); }
			}
			if (wantpart == PP) {
				send = { arc_table[count].end, arc_table[count].end, 0, false, PP, null, null, null, false };
				if (check(send, count)) { push(send); }
			}
		}
	}

	//S���̍\�z
	for (i = 0; i < count; i++) {	//�`���[�g������
		if (arc_table[i].start == 0 && arc_table[i].end == 8 && arc_table[i].arc_status == true && arc_table[i].parts_num == S) {
			S_expression(arc_table[i]);
			printf("\n\n");
		}
	}

	getchar();


	return 0;
}

int push(arc push_data)
{
	if (stack_num < STACK_SIZE) {
		stack_data[stack_num] = push_data;
		stack_num++;
		return SUCCESS;
	}
	else {
		return FAILURE;
	}
}
int pop(arc *pop_data)
{
	if (stack_num > 0) {
		stack_num--;
		*pop_data = stack_data[stack_num];
		return SUCCESS;
	}
	else {
		return FAILURE;
	}
}

//�d������ʂ��Ȃ����m�F
bool check(arc data, int count) {
	int i;
	//�X�^�b�N�̊m�F
	for (i = 0; i < stack_num; i++) {
		if (stack_data[i].start == data.start &&stack_data[i].end == data.end && stack_data[i].period == data.period &&stack_data[i].dic_flag == data.dic_flag
			&&stack_data[i].parts_num == data.parts_num &&stack_data[i].spel == data.spel &&stack_data[i].ID1 == data.ID1
			&&stack_data[i].ID2 == data.ID2 &&stack_data[i].arc_status == data.arc_status)
			return false;
	}
	//�`���[�g�̊m�F
	for (i = 0; i <= count; i++) {
		if (arc_table[i].start == data.start &&arc_table[i].end == data.end && arc_table[i].period == data.period &&arc_table[i].dic_flag == data.dic_flag
			&&arc_table[i].parts_num == data.parts_num &&arc_table[i].spel == data.spel &&arc_table[i].ID1 == data.ID1
			&&arc_table[i].ID2 == data.ID2 &&arc_table[i].arc_status == data.arc_status)
			return false;
	}
	return true;
}

int SearchWant(arc retdata)
{
	if (retdata.parts_num == S) {
		if (retdata.period == 0) {
			return NP;
		}
		if (retdata.period == 1) {
			return VP;
		}
	}
	if (retdata.parts_num == NP) {
		if (retdata.period == 0) {
			return det;
		}
		if (retdata.period == 1) {
			return n;
		}
	}
	if (retdata.parts_num == NP2) {
		if (retdata.period == 0) {
			return NP;
		}
		if (retdata.period == 1) {
			return PP;
		}
	}
	if (retdata.parts_num == VP) {
		if (retdata.period == 0) {
			return v;
		}
		if (retdata.period == 1) {
			return NP;
		}
	}
	if (retdata.parts_num == VP2) {
		if (retdata.period == 0) {
			return VP;
		}
		if (retdata.period == 1) {
			return PP;
		}
	}
	if (retdata.parts_num == PP) {
		if (retdata.period == 0) {
			return prep;
		}
		if (retdata.period == 1) {
			return NP;
		}
	}

	return -100;	//error
}

void S_expression(arc data) {	//S���̐���
	if (data.parts_num == S) {
		printf("S(");
		S_expression(arc_table[data.ID1]);
		printf(",");
		S_expression(arc_table[data.ID2]);
		printf(")");
	}
	if (data.parts_num == VP || data.parts_num == VP2) {
		printf("VP(");
		S_expression(arc_table[data.ID1]);
		printf(",");
		S_expression(arc_table[data.ID2]);
		printf(")");
	}
	if (data.parts_num == PP) {
		printf("PP(");
		S_expression(arc_table[data.ID1]);
		printf(",");
		S_expression(arc_table[data.ID2]);
		printf(")");
	}
	if (data.parts_num == NP || data.parts_num == NP2) {
		printf("NP(");
		S_expression(arc_table[data.ID1]);
		printf(",");
		S_expression(arc_table[data.ID2]);
		printf(")");
	}
	if (data.parts_num == det) {
		printf("det(%s)", input_words[data.spel]);
	}
	if (data.parts_num == n) {
		printf("n(%s)", input_words[data.spel]);
	}
	if (data.parts_num == v) {
		printf("v(%s)", input_words[data.spel]);
	}
	if (data.parts_num == prep) {
		printf("prep(%s)", input_words[data.spel]);
	}
}
