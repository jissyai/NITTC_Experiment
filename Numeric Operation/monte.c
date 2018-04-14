
//	球体の体積計算

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000
#define DIM 5

int main(int argc, char const *argv[]) {
	double x[DIM], r[DIM];
	int n, j;
	double rr;
	int m[DIM];

	for(j=0; j<DIM; j++)
		m[j]=0;

	printf("　回数　　円面積　　球体積　　4次元　　5次元\n\n");
	for (n=1; n<=N; n++) {
		for(j=0; j<DIM; j++){
			x[j]=(double)rand()/(double)RAND_MAX;
			r[j]=0.0;
		}

		rr=0.0;
		for(j=0; j<DIM; j++){
			rr+=(x[j]-0.5)*(x[j]-0.5);
			r[j]=rr;
		}

		for(j=0; j<DIM; j++)
			if(r[j]<=0.25)	m[j]++;

		if((n%1000)==0){						//解答打ち出し
			printf("%6d",n);
			for(j=1; j<DIM; j++)
				printf("%9.4lf",(double)m[j]/(double)n);
			printf("\n");
		}
	}
	return 0;
}
