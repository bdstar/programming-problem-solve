//27382989	108	Maximum Sum	Accepted	C++11	0.020	2022-04-05 14:27:48
#include<stdio.h>
int main(){
	int N;
	while( scanf("%d",&N)==1 ){
		int S[101][101];
		int DP[101][101]={0};
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				scanf("%d",&S[i][j]);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				DP[i][j]=DP[i][j-1]+S[i][j];

		int max=-2e9;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				for(int k=1;k<=j;k++){
					int sum=0;
					for(int p=0;p+i<=N;p++){
						sum+=DP[i+p][j]-DP[i+p][k-1];
						if( sum>max )
							max=sum;
					}
				}
		printf("%d\n",max);
	}
	return 0;
}