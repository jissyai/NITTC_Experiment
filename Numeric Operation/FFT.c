//時間分割法による高速DFT
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define L 10 //最大サンプル数(2^L)

double r[1024],i[1024],wr[512],wi[512];

void bit(int);
void dft(int);
void bat(int,double,int,int);
double func_y(double);

int main(int argc,char **argv)
{
	clock_t start,end;
	start=clock();

  struct timeval s, e;
  gettimeofday(&s, NULL);

	int j,p;
	p = (int)pow(2.0,(double)L);
	for(j=0;j<1024;j++)
	{
		r[j] = 0.0;
		i[j] = 0.0;
	}
	//データを1/p倍してサンプリング
	for(j=0;j<p;j++)
	{
		i[j] = func_y((2.0 * M_PI / (double)p) * (double)j) / (double)p;
	}
	//データ表示
	printf("No.\tデータ\n");
	for(j=0;j<p;j++)
	{
		printf("i[%d] = %9.3lf\n",j,i[j]*(double)p);
	}
	bit(p);
	dft(p);

	printf("\n次数\t実数部\t虚数部\n");
	for(j=0;j<p;j++)
	{
		printf("%4d%9.3lf%9.3lf\n",j,r[j],i[j]);
	}

  gettimeofday(&e, NULL);
  printf("time = %lf\n", (e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec)*1.0E-6);

	end=clock();
	//printf("処理時間：%d[ms]\n",end-start);

	return 0;
}

void bit(int p)
{
	int j,d,c,k;

	for(j=0;j<p;j++)
	{
		d = j;
		c = p/2;
		for(k=0;k<L;k++)
		{
			r[j] += (d%2)*c;
			d /= 2;
			c /= 2;
		}
	}

	for(j=0;j<p;j++)
	{
		r[j] = i[(int)r[j]];
	}

	for(k=0;k<1024;k++)
	{
		i[k] = 0.0;
	}
}

void dft(int p)
{
	int a,b,j,k,h;
	double w,q,t;

	for(j=0;j<=p/2;j++)
	{
		w = -2.0*M_PI / (double)p * (double)j;
		wr[j] = cos(w);
		wi[j] = sin(w);
	}
	for(j=0;j<L;j++)
	{
		t = pow(2.0,(double)j);
		q = pow(2.0,(double)L - 1.0 - (double)j);
		for(k=0;k<q;k++)
		{
			for(h=0;h<t;h++)
			{
				a = (int)((double)k * 2.0 * t + (double)h);
				b = (int)((double)a + t);
				bat(h,q,a,b);
			}
		}
	}
}


void bat(int h,double q,int a,int b)
{
	int w;
	double ra,rb,ia,ib;

	w = (int)((double)h*q);
	ra = r[a] + r[b] * wr[w] - i[b] * wi[w];
	ia = i[a] + r[b] * wi[w] + i[b] * wr[w];
	rb = r[a] - r[b] * wr[w] + i[b] * wi[w];
	ib = i[a] - r[b] * wi[w] - i[b] * wr[w];
	r[a] = ra;
	i[a] = ia;
	r[b] = rb;
	i[b] = ib;
}

double func_y(double x)
{
	return sin(2.0*x)+3.0*cos(100.0*x)+2*sin(300*x);
}
