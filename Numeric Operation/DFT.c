#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define P 10

double func_y(double);

int main(int argc,char **argv){
  double f[P];
  double ar,ai,x;
  int m,n;

  clock_t start,end;
  start=clock();

  struct timeval s, e;
  gettimeofday(&s, NULL);

  for(m=0;m<P;m++)
    f[m]=func_y(2.0*M_PI/(double)P*(double)m);

  printf("次数\t実数部\t虚数部\t絶対値\n");
  for(n=0;n<P;n++){
    ar=0.0;
    ai=0.0;
    for(m=0;m<P;m++){
      x=2.0*M_PI/(double)P*(double)m*(double)n;
      ar+=f[m]*cos(-x);
      ai+=f[m]*sin(-x);
    }
    ar/=(double)P;
    ai/=(double)P;
    x=sqrt(ar*ar+ai*ai);
    printf("%4d %9.3lf %9.3lf %9.3lf\n",n,ar,ai,x);
  }

  gettimeofday(&e, NULL);
  printf("time = %lf\n", (e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec)*1.0E-6);

  end=clock();
  //printf("処理時間：%d[ms]\n",end-start);

  return 0;
}

double func_y(double x){
  return 2.0*sin(3.0*x)+3.0*cos(9.0*x);
}
