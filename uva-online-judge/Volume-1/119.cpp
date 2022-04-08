//27391911	119	Greedy Gift Givers	Accepted	C++11	0.000	2022-04-08 06:03:58
#include<stdio.h>
#include<string.h>
int main(){
	int n;
	bool first=true;
	while( scanf("%d",&n)==1 ){
		int ans[1000]={0};
		char name[10][100];
		for(int i=0;i<n;i++)
			scanf("%s",name[i]);
		for(int i=0;i<n;i++){
			char giver[100];
			int ptrGiver,ptrReceiver;
			int money;
			int people;
			scanf("%s%d%d",giver,&money,&people);
			for(int j=0;j<n;j++)
				if( strcmp(giver,name[j])==0 ){
					ptrGiver=j;
					break;
				}
			if( people>0 ){
				ans[ptrGiver]-=money;
				ans[ptrGiver]+=money%people;
			}
			for(int j=0;j<people;j++){
				char Receiver[100];
				scanf("%s",Receiver);
				for(int k=0;k<n;k++)
					if( strcmp(Receiver,name[k])==0 ){
						ptrReceiver=k;
						break;
					}
				ans[ptrReceiver]+=money/people;
			}
		}
		if( !first )
			putchar('\n');
		first=false;
		for(int j=0;j<n;j++)
			printf("%s %d\n",name[j],ans[j]);
	}
	return 0;
}