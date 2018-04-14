//	正規乱数検証計算

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
	
#define N 10000	//繰り返し回数

double gauss(int);
void print(double,double,int);

int main(int argc,char **argv){
	double sa = 0.0 , sb = 0.0;
	double v;
	int i;
	
	printf(" 回数	平均値	  標準偏差\n");
	for(i=1;i<=N;i++){
		v = gauss(12);
		sa += v;
		sb += v*v;
		if((i%10) == 0){		//間隔
				printf("%lf ",v);
			print(sa,sb,i);
		}
	}
	return 0;
}

//結果打ち出し
void print(double sa, double sb, int i){
	double ave = 0.0, hh, sig;
	
	ave=sa/(double)i;
	hh=sb-2.0*ave*sa+(double)i*ave*ave;
	sig=sqrt(hh/((double)i-1.0));
	printf("%6d %8.4lf %8.4lf\n",i,ave,sig);
}

//正規乱数生成
double gauss(int num){
	double ss=0.0;
	int i;
	
	for(i=0;i<num;i++)
		ss += rand() / (double)RAND_MAX;
	return ss-6;
}
