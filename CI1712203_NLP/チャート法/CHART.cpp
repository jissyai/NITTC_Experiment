#include <stdio.h>
#define STACK_SIZE 100
#define SUCCESS 1
#define FAILURE 0
#define null -1

#define N 8	//入力文章の単語数
char *input_words[N] = { "the","man","broke","a","desk","with","a","drawer" };	//入力文章
//char *dic_rule[N] = { "det1","n1","v1","det2","n2","prep1","det3","n3" };	//入力文章の辞書規則

#define det 0	//構文規則を数字と対応付け
#define n 1
#define v 2
#define prep 3
#define NP 4
#define VP 5
#define PP 6
#define S 7
#define NP2 8
#define VP2 9

#define the 0	//辞書規則を数字と対応付け
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
	bool	dic_flag;	//辞書規則に適用される場合のフラグ
	int		parts_num;	//品詞分類の対応番号
	int		spel;
	int		ID1;	//不活性弧のID(履歴)
	int		ID2;	//不活性弧のID2(履歴)
	bool	arc_status;	//弧の分類，不活性弧:true，活性弧:false
};

int push(arc push_data);
int pop(arc *pop_data);
bool check(arc data, int count);
int SearchWant(arc retdata);
void S_expression(arc data);	//S式(S-expression)の生成

arc stack_data[STACK_SIZE];
int stack_num;

arc arc_table[STACK_SIZE];

int main(void) {
	int count, i, wantpart;
	arc send;

	//辞書規則の適用
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
	//開始記号Sの活性弧を追加
	send = { 0, 0, 0, false, S, null, null, null,  false };	//構文規則の対応番号いれる
	push(send);

	//アジェンダが空になるまで以下の操作を続ける
	for (count = 0; stack_num != 0; count++) {
		//弧の選択
		pop(&arc_table[count]);	//チャートに追加
		//弧の結合
		if (arc_table[count].arc_status == false) {	//弧が活性弧のとき右にある不活性孤を探して結合
			wantpart = SearchWant(arc_table[count]);	//弧を渡したら何を必要としてるか返す
			for (i = 0; i < count; i++) {	//チャートを見る
				if (arc_table[i].arc_status == true && arc_table[i].start == arc_table[count].end) {	//不活性弧でかつ、弧が右ならば
					if (wantpart != NP && wantpart != VP) {	//wantpartが分岐するものでないとき
						if (wantpart == arc_table[i].parts_num) {
							//結合してできた新しい弧をpush
							if (arc_table[count].period == 0) {
								send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, i, null, false };
								//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
								if (check(send, count)) { push(send); }
							}
							else if (arc_table[count].period == 1) {
								send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, arc_table[count].ID1, i, true };
								//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
								if (check(send, count)) { push(send); }
							}
						}
					}
					else {
						if (wantpart == NP) {
							if (arc_table[i].parts_num == NP || arc_table[i].parts_num == NP2) {
								//結合してできた新しい弧をpush
								if (arc_table[count].period == 0) {
									send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, i, null, false };
									//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
									if (check(send, count)) { push(send); }
								}
								else if (arc_table[count].period == 1) {
									send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, arc_table[count].ID1, i, true };
									//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
									if (check(send, count)) { push(send); }
								}
							}
						}
						if (wantpart == VP) {
							if (arc_table[i].parts_num == VP || arc_table[i].parts_num == VP2) {
								//結合してできた新しい弧をpush
								if (arc_table[count].period == 0) {
									send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, i, null, false };
									//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
									if (check(send, count)) { push(send); }
								}
								else if (arc_table[count].period == 1) {
									send = { arc_table[count].start, arc_table[i].end, (arc_table[count].period) + 1, false, arc_table[count].parts_num, null, arc_table[count].ID1, i, true };
									//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
									if (check(send, count)) { push(send); }
								}
							}
						}
					}
				}
			}
		}
		if (arc_table[count].arc_status == true) {	//弧が不活性弧のとき左にある活性孤を探して結合
			for (i = 0; i < count; i++) {	//チャートを見る
				if (arc_table[i].arc_status == false && arc_table[i].end == arc_table[count].start) {	//活性弧でかつ、弧が←ならば
					wantpart = SearchWant(arc_table[i]);
					if (wantpart != NP && wantpart != VP) {//wantpartが分岐するものでないとき
						if (wantpart == arc_table[count].parts_num) {
							//結合してできた新しい弧をpush
							if (arc_table[i].period == 0) {
								send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, count, null, false };
								//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
								if (check(send, count)) push(send);
							}
							else if (arc_table[i].period == 1) {
								send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, arc_table[i].ID1, count, true };
								//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
								if (check(send, count)) push(send);
							}
						}
					}
					else {
						if (wantpart == NP) {
							if (arc_table[count].parts_num == NP || arc_table[count].parts_num == NP2) {//
																									//結合してできた新しい弧をpush
								if (arc_table[i].period == 0) {
									send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, count, null, false };
									//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
									if (check(send, count)) push(send);
								}
								else if (arc_table[i].period == 1) {
									send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, arc_table[i].ID1, count, true };
									//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
									if (check(send, count)) push(send);
								}
							}
						}
						if (wantpart == VP) {
							if (arc_table[count].parts_num == VP || arc_table[count].parts_num == VP2) {
								//結合してできた新しい弧をpush
								if (arc_table[i].period == 0) {
									send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, count, null, false };
									//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
									if (check(send, count)) push(send);
								}
								else if (arc_table[i].period == 1) {
									send = { arc_table[i].start, arc_table[count].end, (arc_table[i].period) + 1, false, arc_table[i].parts_num, null, arc_table[i].ID1, count, true };
									//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
									if (check(send, count)) push(send);
								}
							}
						}
					}
				}
			}
		}

		//新しい弧の提案
		if (arc_table[count].arc_status == false && SearchWant(arc_table[count])>3) {	//弧が活性孤[i,j,X→a.YB]のとき、Yを左辺とする規則Y→y(辞書規則を除く)があれば[j,j,Y→.y]を作って追加
			//※同じ弧が既にチャートまたはアジェンダにあるときは追加しない
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

	//S式の構築
	for (i = 0; i < count; i++) {	//チャートを見る
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

//重複する弧がないか確認
bool check(arc data, int count) {
	int i;
	//スタックの確認
	for (i = 0; i < stack_num; i++) {
		if (stack_data[i].start == data.start &&stack_data[i].end == data.end && stack_data[i].period == data.period &&stack_data[i].dic_flag == data.dic_flag
			&&stack_data[i].parts_num == data.parts_num &&stack_data[i].spel == data.spel &&stack_data[i].ID1 == data.ID1
			&&stack_data[i].ID2 == data.ID2 &&stack_data[i].arc_status == data.arc_status)
			return false;
	}
	//チャートの確認
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

void S_expression(arc data) {	//S式の生成
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
