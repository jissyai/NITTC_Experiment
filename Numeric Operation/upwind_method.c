#include<stdio.h>

#define N 150 //格子数

int main(void) {
	/* code */
	FILE *fp;
	fp=fopen("upwind_1.csv","w");

	double U=0.2,f[N],F;
	int i,t,dt=1,dx=1;

	for(i=0;i<=N;i++){
		if(20<i&&i<30)	f[i]=1.0;
		else	f[i]=0.0;
	}

	for(t=1;t<=dt;t++){
		for(i=1;i<N;i++){
			F=f[i]-U*(f[i]-f[i-1]);
			f[i]=F;
		}

		for(i=0;i<=N;i++){
			fprintf(fp,"%f\n",f[i]);
		}
	}

	fclose(fp);

	return 0;
}
