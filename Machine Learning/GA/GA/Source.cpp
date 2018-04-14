//ga 塾講師割り当て
#define T 40//講師人数
#define S 40//生徒人数
#define X 40//1世代あたりの個体数
#define GENERATION 100//世代回数
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	srand(0);
	int Student[S], Teacher[T], i, j, g, x, N_top, m;
	int top1 = 0, top1S = 0, top1T = 0, N_top1;//上位1組と個体番号

	for (i = 0; i<S; i++) {
		Student[i] = rand() % 11;	//生徒能力0~10
	}
	for (i = 0; i<T; i++) {
		Teacher[i] = rand() % 11;	//講師能力0~10
	}

	printf("生徒能力");
	for (i = 0; i<S; i++) {
		printf(",%d", Student[i]);
	}
	printf("\n講師能力");
	for (i = 0; i<T; i++) {
		printf(",%d", Teacher[i]);
	}
	printf("\n");

	//母集団の初期化
	int ES[X][S];//E[i][j] i番目の個体のj番目の染色体(0,1で品物を選ぶか)
	for (i = 0; i<X; i++) {
		for (j = 0; j<S; j++) {
			ES[i][j] = rand() % 2;
		}
	}
	int ET[X][T];//E[i][j] i番目の個体のj番目の染色体(0,1で品物を選ぶか)
	for (i = 0; i<X; i++) {
		for (j = 0; j<T; j++) {
			ET[i][j] = rand() % 2;
		}
	}

	for (g = 0; g<GENERATION; g++) {
		int S_sum[X], T_sum[X], evaluation[X];
		double n=0.0;
		printf("\n組み合わせ");
		for (i = 0; i<X; i++) {
			S_sum[i] = 0;
			T_sum[i] = 0;
			for (j = 0; j<20; j++) {
				//染色体が1同士を比較
				if (ES[i][j]==1&&ET[i][j]==1 ) {
					S_sum[i] = Student[j];
					T_sum[i] = Teacher[j];
				}
				n = ((double)S_sum[i] + (double)T_sum[i]) / 2.0;
				evaluation[i] = 100.0-(fabs(5.0-n)*20.0);
				if (S_sum[i] == 0 && T_sum[i] == 0) {
					evaluation[i] = 0;
				}
			}
			
				printf(",(S:%d, T:%d)", S_sum[i], T_sum[i]);
			
		}

		int eva_sum=0,adaptation=0;
		for (i = 0; i < X; i++) {
			eva_sum += evaluation[i];
		}
		adaptation = eva_sum / X;
		printf("\n評価値平均:%d", adaptation);

		char buf[256];
		FILE *fp;
		sprintf_s(buf, "C:/Users/student/Documents/Visual Studio 2015/Projects/GA/GA.csv");
		fopen_s(&fp, buf, "a");
		if (fp != NULL) {
			fprintf(fp, "%d\n", adaptation);
			fclose(fp);
		}

		//エリート選択
		for (i = 1; i<X; i++) {
			//上位1個体を探す
			if (evaluation[i]>top1) {
				top1 = evaluation[i];
				top1S = S_sum[i];
				top1T = T_sum[i];
				N_top = i;
			}
		}
		printf("\nエリート選択,(S:%d, T:%d)", top1S,top1T);
		//エリート配列を確保
		int eliteS[S],eliteT[T];
		for (i = 0; i<S; i++) {
			eliteS[i] = ES[N_top][i];
		}
		for (i = 0; i<T; i++) {
			eliteT[i] = ET[N_top][i];
		}

		if (g == GENERATION - 1) {
			break;
		}

		//ルーレット選択
		//次の世代の入れ物を作る
		int nextES[X][S],nextET[X][T];
		//的
		int total = 0;
		for (i = 0; i<X; i++) {
			total += evaluation[i];
		}
		for (x = 0; x<X; x++) {
			int arrow = rand() % total;
			int sum = 0;
			for (i = 0; i<X; i++) {
				sum += evaluation[i];
				if (sum>arrow) {
					for (j = 0; j<S; j++) {
						nextES[x][j] = ES[i][j];
						nextET[x][j] = ET[i][j];
					}
					break;
				}
			}
		}
		//交叉(前から2組ずつ交叉する。交叉しなければそのままコピーされる
		for (x = 0; (X % 2 == 1 && x<X - 1) || (X % 2 == 0 && x<X); x = x + 2) {
			//crossrate%で交叉
			int crossrate = rand() % 100;
			if (crossrate<95) {
				//2点交叉でcopyEからchildを作る
				//r1~r2までの染色体を入れ替える
				int r1 = rand() % S;
				int r2 = r1 + rand() % (S - r1);//0<=r1<r2<15
				int childS[2][S];
				for (i = 0; i<S; i++) {
					if (r1 <= i && i <= r2) {
						childS[0][i] = nextES[x + 1][i];
						childS[1][i] = nextES[x][i];
					}
					else {
						childS[0][i] = nextES[x][i];
						childS[1][i] = nextES[x + 1][i];
					}
				}
				for (i = 0; i<S; i++) {
					//childを世代に入れる
					nextES[x][i] = childS[0][i];
					nextES[x + 1][i] = childS[1][i];
				}
				
				int r3 = rand() % T;
				int r4 = r1 + rand() % (T - r1);//0<=r1<r2<15
				int childT[2][T];
				for (i = 0; i<T; i++) {
					if (r1 <= i && i <= r2) {
						childT[0][i] = nextET[x + 1][i];
						childT[1][i] = nextET[x][i];
					}
					else {
						childT[0][i] = nextET[x][i];
						childT[1][i] = nextET[x + 1][i];
					}
				}
				for (i = 0; i<T; i++) {
					//childを世代に入れる
					nextET[x][i] = childT[0][i];
					nextET[x + 1][i] = childT[1][i];
				}
			}
			else {
				//printf("\n入れ替え無し\n");
			}

			//突然変異
			//各個体r%の確率で染色体のどこかを反転させる
			for (i = 0; i<X; i++) {
				int mutantrate = rand() % 100;
				if (mutantrate<1) {
					m = rand() % S;
					nextES[i][m] = (nextES[i][m] + 1) % 2;
					m = rand() % T;
					nextET[i][m] = (nextET[i][m] + 1) % 2;
				}
			}
		}
		//仮個体を次の世代個体に代入
		for (i = 0; i<X; i++) {
			for (j = 0; j<S; j++) {
				if (i == 0 || i == 1) {
					ES[i][j] = eliteS[j];
				}
				else {
					ES[i][j] = nextES[i][j];
				}
			}
			for (j = 0; j<T; j++) {
				if (i == 0 || i == 1) {
					ET[i][j] = eliteT[j];
				}
				else {
					ET[i][j] = nextET[i][j];
				}
			}
		}
		//getchar();
	}

	return 0;
}
