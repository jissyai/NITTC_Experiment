#include <stdio.h>

int main(void)
{
	int a,c,b,M,i,x[100];
	FILE *fp;
	fp=fopen("kongou.csv","w");

	a=1;
	b=0;
	c=7;
	M=10;
	for(i=1;i<=100;i++)
	{
		x[1]=b;
		x[i+1]=(a*x[i]+c)%M;

		if(i%3!=0)
		{
			printf("x%3d=%3d, ",i,x[i]);
		}
		else
		{
			printf("x%3d=%3d\n",i,x[i]);
		}

		if(fp!=NULL){
			fprintf(fp,"x%3d,%3d\n",i,x[i]);
		}
	}

	fclose(fp);
	return 0;
}
