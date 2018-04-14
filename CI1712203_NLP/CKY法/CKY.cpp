#include <stdio.h>

#define N 8	//入力文章の単語数
char *input_words[N] = { "the","man","broke","a","desk","with","a","drawer" };	//入力文章
char *dic_rule[N] = { "det1","n1","v1","det2","n2","prep1","det3","n3" };	//入力文章の辞書規則

#define det 0	//構文規則を数字と対応付け
#define n 1
#define v 2
#define prep 3
#define NP 4
#define VP 5
#define PP 6
#define S 7

#define det1 0	//辞書規則を数字と対応付け
#define n1 1
#define v1 2
#define det2 3
#define n2 4
#define prep1 5
#define det3 6
#define n3 7

void in_data(int i1, int j1, int i2, int j2, bool checkflag, int part);
void syntax_rule(int i1, int j1, int i2, int j2);	//word1とword2に対して構文規則総あたり
void S_expression(int i, int j);	//S式(S-expression)の生成
void S_expression2(int i, int j);	//別パターンのS式の生成
bool pattern2;	//構文規則が2つあてはまる場合のフラグ

struct cky {
	int		i1;	//1単語目のi座標1つめの構文規則に対して
	int		j1;	//j座標
	int		i2;	//2単語目のi座標
	int		j2;	//j座標
	int		i1_2;	//1単語目のi座標2つめの構文規則に対して
	int		j1_2;	//j座標
	int		i2_2;	//2単語目のi座標
	int		j2_2;	//j座標
	bool	dic_flag;	//辞書規則に適用される場合のフラグ
	int		dic_num;	//辞書規則の対応番号
	int		parts_num;	//品詞分類の対応番号
	int		syn_num1;	//構文規則の対応番号
	int		syn_num2;	//構文規則の2つ目が有る場合
	bool	flag_2;	//2つの構文規則を持っている場合のフラグ
};

cky table[N][N] = {};	//CKY表用の2次元配列
int Dicrules(cky word);	//辞書規則の分類

int main(void) {
	int i, j, k, l;	//ループ用の添え字

	for (i = 0; i < N; i++) {	//CKY表の初期化
		for (j = 0; j < N; j++) {
			table[i][j] = { -1, -1, -1, -1, -1, -1, -1, -1, false, -1, -1, -1, -1, false };
		}
	}

	for (i = 0; i < N; i++) {	//辞書規則の適用
		table[i][i].dic_flag = true;
		table[i][i].dic_num = i;
		table[i][i].parts_num = Dicrules(table[i][i]);
	}

	for (l = 1; l <= N - 1; ++l) {	//CKY表を走査
		for (j = 0; j < N - l; ++j) {
			i = j + l;
			pattern2 = false;
			for (k = j; k <= i - 1; ++k) {
				//構文規則との対応付け
				syntax_rule(j, k, k + 1, i);
			}
		}
	}

	if (table[0][N - 1].syn_num1 == S) {	//Sが導出されたらS式を作成
		S_expression(0, N - 1);
	}
	printf("\n\n");
	if (table[0][N - 1].syn_num2 == S) {	//Sがもう一つあるなら2つ目のS式を作成
		S_expression2(0, N - 1);
	}
	printf("\n\n");

	getchar();

	return 0;

}

void syntax_rule(int i1, int j1, int i2, int j2) {	//構文規則総あたり
	bool checkflag = false;	//もし1つ目があった場合はtrueにして2つ目に入れる

	if (table[i1][j1].syn_num1 == NP && table[i2][j2].syn_num1 == VP) {	//S→NP VP
		in_data(i1, j1, i2, j2, checkflag, S);
		checkflag = true;
		pattern2 = true;
	}
	if (table[i1][j1].parts_num == det && table[i2][j2].parts_num == n) {	//NP→det n 
		in_data(i1, j1, i2, j2, checkflag, NP);
		checkflag = true;
		pattern2 = true;
	}
	if (table[i1][j1].syn_num1 == NP && table[i2][j2].syn_num1 == PP)		{//NP→NP PP
		in_data(i1, j1, i2, j2, checkflag, NP);
		checkflag = true;
		pattern2 = true;
	}
	if (table[i1][j1].parts_num == v && table[i2][j2].syn_num1 == NP) {	//VP→v NP
		in_data(i1, j1, i2, j2, checkflag, VP);
		checkflag = true;
		pattern2 = true;
	}
	if (table[i1][j1].syn_num1 == VP && table[i2][j2].syn_num1 == PP) {	//VP→VP PP
		in_data(i1, j1, i2, j2, checkflag, VP);
		checkflag = true;
		pattern2 = true;
	}
	if (table[i1][j1].parts_num == prep && table[i2][j2].syn_num1 == NP) {	//PP→prep NP
		in_data(i1, j1, i2, j2, checkflag, PP);
		checkflag = true;
		pattern2 = true;
	}

	//最初の単語が2つ目の構文規則を持っている場合
	if (table[i1][j1].flag_2 == true) {
		if (table[i1][j1].syn_num2 == NP && table[i2][j2].syn_num1 == PP) {	//NP PP →NP
			in_data(i1, j1, i2, j2, checkflag, NP);
			checkflag = true;
			pattern2 = true;
		}
		if (table[i1][j1].syn_num2 == NP && table[i2][j2].syn_num1 == VP) {	//NP VP →S
			in_data(i1, j1, i2, j2, checkflag, S);
			checkflag = true;
			pattern2 = true;
		}
		if (table[i1][j1].syn_num2 == VP && table[i2][j2].syn_num1 == PP) {	//VP PP →VP
			in_data(i1, j1, i2, j2, checkflag, VP);
			checkflag = true;
			pattern2 = true;
		}
	}
	//後ろの単語が2つ目の構文規則を持っている場合
	if (table[i2][j2].flag_2 == true) {
		if (table[i1][j1].syn_num1 == NP && table[i2][j2].syn_num2 == PP) {	//NP PP →NP
			in_data(i1, j1, i2, j2, checkflag, NP);
			pattern2 = true;
			checkflag = true;
		}
		if (table[i1][j1].parts_num == v && table[i2][j2].syn_num2 == NP) {	//v NP →VP
			in_data(i1, j1, i2, j2, checkflag, VP);
			checkflag = true;
			pattern2 = true;
		}
		if (table[i1][j1].parts_num == det && table[i2][j2].syn_num2 == NP) {	//prep NP →PP
			in_data(i1, j1, i2, j2, checkflag, PP);
			checkflag = true;
			pattern2 = true;
		}
		if (table[i1][j1].syn_num1 == NP && table[i2][j2].syn_num2 == VP) {	//NP VP →S
			in_data(i1, j1, i2, j2, checkflag, S);
			checkflag = true;
			pattern2 = true;
		}
		if (table[i1][j1].syn_num1 == VP && table[i2][j2].syn_num2 == PP) {	//VP PP →VP
			in_data(i1, j1, i2, j2, checkflag, VP);
			checkflag = true;
			pattern2 = true;
		}
	}
}

void in_data(int i1, int j1, int i2, int j2, bool checkflag, int part) {	//データ入力
	if (checkflag == false && pattern2 == false) {
		table[i1][j2].i1 = i1;
		table[i1][j2].j1 = j1;
		table[i1][j2].i2 = i2;
		table[i1][j2].j2 = j2;
		table[i1][j2].syn_num1 = part;
	}
	else {
		table[i1][j2].i1_2 = i1;
		table[i1][j2].j1_2 = j1;
		table[i1][j2].i2_2 = i2;
		table[i1][j2].j2_2 = j2;
		table[i1][j2].syn_num2 = part;
		table[i1][j2].flag_2 = true;
	}
}

int Dicrules(cky word)	{	//辞書規則の分類	0:det 1:n 2:r 3:prep
	if (word.dic_num == det1 || word.dic_num == det2 || word.dic_num == det3)	//detならば
		return det;
	if (word.dic_num == n1 || word.dic_num == n2 || word.dic_num == n3)	//nならば
		return n;
	if (word.dic_num == v1)	//vならば
		return v;
	if (word.dic_num == prep1)	//prepならば
		return prep;

	return -100;	//エラー
}

void S_expression(int i, int j)	{	//S式の生成
	cky word = table[i][j];
	if (word.syn_num1 == S) {
		printf("S(");
		S_expression(word.i1, word.j1);
		printf(",");
		S_expression(word.i2, word.j2);
		printf(")");
	}
	if (word.syn_num1 == VP) {
		printf("VP(");
		S_expression(word.i1, word.j1);
		printf(",");
		S_expression(word.i2, word.j2);
		printf(")");
	}
	if (word.syn_num1 == PP) {
		printf("PP(");
		S_expression(word.i1, word.j1);
		printf(",");
		S_expression(word.i2, word.j2);
		printf(")");
	}
	if (word.syn_num1 == NP) {
		printf("NP(");
		S_expression(word.i1, word.j1);
		printf(",");
		S_expression(word.i2, word.j2);
		printf(")");
	}
	if (word.parts_num == det) {
		printf("det(%s)", input_words[word.dic_num]);
	}
	if (word.parts_num == n) {
		printf("n(%s)", input_words[word.dic_num]);
	}
	if (word.parts_num == v) {
		printf("v(%s)", input_words[word.dic_num]);
	}
	if (word.parts_num == prep) {
		printf("prep(%s)", input_words[word.dic_num]);
	}
}

void S_expression2(int i, int j)	//別パターンのS式の生成
{
	cky word = table[i][j];
	if (word.flag_2 == true) {
		word.syn_num1 = word.syn_num2;
		word.i1 = word.i1_2;
		word.j1 = word.j1_2;
		word.i2 = word.i2_2;
		word.j2 = word.j2_2;
	}
	if (word.syn_num1 == S) {
		printf("S(");
		S_expression2(word.i1, word.j1);
		printf(",");
		S_expression2(word.i2, word.j2);
		printf(")");
	}
	if (word.syn_num1 == VP) {
		printf("VP(");
		S_expression2(word.i1, word.j1);
		printf(",");
		S_expression2(word.i2, word.j2);
		printf(")");
	}
	if (word.syn_num1 == PP) {
		printf("PP(");
		S_expression2(word.i1, word.j1);
		printf(",");
		S_expression2(word.i2, word.j2);
		printf(")");
	}
	if (word.syn_num1 == NP) {
		printf("NP(");
		S_expression2(word.i1, word.j1);
		printf(",");
		S_expression2(word.i2, word.j2);
		printf(")");
	}
	if (word.parts_num == det) {
		printf("det(%s)", input_words[word.dic_num]);
	}
	if (word.parts_num == n) {
		printf("n(%s)", input_words[word.dic_num]);
	}
	if (word.parts_num == v) {
		printf("v(%s)", input_words[word.dic_num]);
	}
	if (word.parts_num == prep) {
		printf("prep(%s)", input_words[word.dic_num]);
	}
}
