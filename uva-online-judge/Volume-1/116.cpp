//27391885	116	Unidirectional TSP	Accepted	C++11	0.040	2022-04-08 05:50:21
#include<stdio.h>
#define MAX 101
using namespace std;
int main()
{
    int n,m;
    while( scanf("%d%d",&n,&m)==2 )
    {
        int S[MAX+1][MAX+1];
        int DP[MAX+1][MAX+1];
        int PATH[MAX+1][MAX+1];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
               scanf("%d",&S[i][j]);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                DP[i][j]=2e9,PATH[i][j]=-1;
        for(int i=1;i<=n;i++)
            DP[i][m]=S[i][m],PATH[i][m]=m+1;

        for(int j=m-1; j>=1; j--){
            for(int i=1; i<=n; i++)
            {
                if( DP[i][j]>DP[i][j+1]+S[i][j] )
                    DP[i][j]=DP[i][j+1]+S[i][j],PATH[i][j]=i;
                else if( DP[i][j]==DP[i][j+1]+S[i][j]&&PATH[i][j]>i )
                    PATH[i][j]=i;

                if( i-1>=1 ){
					if( DP[i][j]>DP[i-1][j+1]+S[i][j] )
						DP[i][j]=DP[i-1][j+1]+S[i][j],PATH[i][j]=i-1;
					else if( DP[i][j]==DP[i-1][j+1]+S[i][j]&&PATH[i][j]>i-1 )
						PATH[i][j]=i-1;
				}
                else if( DP[i][j]>DP[n][j+1]+S[i][j] )
						DP[i][j]=DP[n][j+1]+S[i][j],PATH[i][j]=n;
				else if( DP[i][j]==DP[n][j+1]+S[i][j]&&PATH[i][j]>n )
						PATH[i][j]=n;

                if( i+1<=n ){
					if( DP[i][j]>DP[i+1][j+1]+S[i][j] )
						DP[i][j]=DP[i+1][j+1]+S[i][j],PATH[i][j]=i+1;
					else if( DP[i][j]==DP[i+1][j+1]+S[i][j]&&PATH[i][j]>i+1 )
						PATH[i][j]=i+1;
				}
                else if( DP[i][j]>DP[1][j+1]+S[i][j] )
                    DP[i][j]=DP[1][j+1]+S[i][j],PATH[i][j]=1;
				else if( DP[i][j]==DP[1][j+1]+S[i][j]&&PATH[i][j]>1 )
					PATH[i][j]=1;
            }
		}
        int min=2e9;
        for(int i=1; i<=n; i++)
            if( min>DP[i][1] )
                min=DP[i][1];
        int ans[MAX+1];
        for(int i=1;i<=n;i++)
            if( DP[i][1]==min ){
                for(int j=i,k=1;k<=m;k++)
                    ans[k]=j,j=PATH[j][k];
                break;
            }
        for(int i=1; i<=m; i++)
            if( i==1 )
                printf("%d",ans[i]);
            else
                printf(" %d",ans[i]);
        putchar('\n');
        printf("%d\n",min);
    }
    return 0;
}