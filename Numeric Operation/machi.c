#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N	30000		//試行回数
#define M	5		//窓口数
#define ALF	1		//流れ密度
#define DEL	4		//平均処理時間
#define SIG	.5		//処理時間のばらつき
#define EPS	.000001		//log計算時のバイアス

int k = 0;		//待ち人数

double	gauss(void);
void	cll(double,double *);
int minimum(double *);
double	tim(double,double,double *,double *);
void	sentaku(double,double *,double *);
double	poison(double);

int main(int argc,char **argv){
	double	ans=0.0,time=0.0;
	double	a[20],b[200];

	int	i;

	printf("試行回数 平均待ち時間\n");
	for(i=0;i<20;i++)
		a[i]=0.0;
	for(i=0;i<200;i++)
		b[i]=0.0;

	for(i=1;i<=N;i++){
		time+=poison(time);
		ans=tim(ans,time,a,b);
		cll(time,a);
		sentaku(time,a,b);

		if(i%2000==0)
			printf("%6d\t%11.6lf\n",i,ans/(double)i);
	}
	return 0;
}

double gauss(void){
	double	del = 0.0;
	int	p;

	for(p=0;p<12;p++)
		del+=((double)rand()/(double)RAND_MAX);
	return((double)DEL+SIG*(del-6.0));
}

//空き窓口ルーチン
void cll(double time,double a[]){
	int j;

	for(j=0;j<M;j++){
		if(a[j]<time){
			a[j]=0.0;
			return;
		}
	}
}

//最短空き窓口
int minimum(double a[]){
	int	min=M,p;

	a[min]=100000.;
	for(p=0;p<M;p++)
		if(a[min]>a[p])
		min=p;
	return min;
}

//待ち解除ルーチン
double tim(double ans,double time,double a[],double b[]){
	int	j,l;
	int	min;

	for(j=0;j<k;j++){
		min=minimum(a);

		if(a[min]<time){
			ans+=a[min]-b[0];
			a[min]+=gauss();
			k--;
			for(l=0;l<k;l++)
				b[l]=b[l+1];
			b[l+1]=0.0;
		}
	}
		return ans;
}

//窓口選択ルーチン
void sentaku(double t,double a[],double b[]){
	int j;

	for(j=0;j<M;j++){
		if(a[j]==0.0){
			a[j]=t+gauss();
			return;
		}
	}
	b[k]=t;
	k++;
	return;
}

double poison(double t){
	double	taw;

	taw = -log((double)rand()/(double)RAND_MAX+EPS)/(double)ALF;
	return taw;
}
