//27391751	113	Power of Cryptography	Accepted	ANSI C	0.000	2022-04-08 05:18:18
#include<stdio.h>
#include<math.h>
int main(){
	double p;
	int n;
	while(scanf("%d%lf",&n,&p)==2){		
		printf("%.0lf\n",pow(p,(double)1/n));
	}
	return 0;
}