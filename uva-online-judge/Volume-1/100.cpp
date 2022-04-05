//27382794	100	The 3n + 1 problem	Accepted	C++	0.310	2022-04-05 13:22:42
#include<stdio.h>
int n(int o){
	int length=1;
	while(o!=1){		
		if((o&1)==1)
			o=3*o+1;
		else
			o/=2;			
		length++;		
	}
	return length;
}
int main(){
	int i,j;
	while(scanf("%d%d",&i,&j)==2){
		printf("%d %d ",i,j);
		int max=1;
		if(i>j){
			int temp=i;
			i=j;
			j=temp;
		}
		for(int k=i;k<=j;k++){
			int length=n(k);			
			if(max<length)
				max=length;
		}
		printf("%d\n",max);

	}
	return 0;
}