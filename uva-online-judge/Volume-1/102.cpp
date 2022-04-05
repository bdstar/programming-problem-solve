//27382876	102	Ecological Bin Packing	Accepted	C++11	0.010	2022-04-05 13:47:11
#include<stdio.h>
#define INT_MAX 2147483647
int main(){
	int B[3],G[3],C[3];
	while(scanf("%d%d%d%d%d%d%d%d%d",&B[0],&G[0],&C[0],&B[1],&G[1],&C[1],&B[2],&G[2],&C[2])==9){
		char str[4];		
		str[3]='\0';
		int k;
		int min=INT_MAX,type=0;
		if((k=B[1]+B[2]+C[0]+C[2]+G[0]+G[1])<min) // BCG type 1
			min=k,type=1;
		if((k=B[1]+B[2]+C[0]+C[1]+G[0]+G[2])<min) // BGC type 2
			min=k,type=2;
		if((k=B[0]+B[2]+C[1]+C[2]+G[0]+G[1])<min) // CBG type 3
			min=k,type=3;
		if((k=B[0]+B[1]+C[1]+C[2]+G[0]+G[2])<min) // CGB type 4
			min=k,type=4;
		if((k=B[0]+B[2]+C[0]+C[1]+G[1]+G[2])<min) // GBC type 5
			min=k,type=5;
		if((k=B[0]+B[1]+C[0]+C[2]+G[1]+G[2])<min) // GCB type 6
			min=k,type=6;
		switch(type){
			case 1:
				printf("BCG %d\n",min); break;
			case 2:
				printf("BGC %d\n",min); break;
			case 3:
				printf("CBG %d\n",min); break;
			case 4:
				printf("CGB %d\n",min); break;
			case 5:
				printf("GBC %d\n",min); break;
			case 6:
				printf("GCB %d\n",min); break;}
	}
	return 0;
}