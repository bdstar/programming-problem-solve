//27382847	101	The Blocks Problem	Accepted	C++11	0.000	2022-04-05 13:36:45
#include<stdio.h>
#include<string.h>
void move_onto(int a,int b,int m[][25],int index[],int pos[]){
	int ap,bp;
	int i,k;
	for(i=pos[a],ap=0;ap<index[i]&&m[i][ap]!=a;ap++);  // find a's pos
	for(;index[pos[a]]-1>ap;index[pos[a]]--){
		k=m[pos[a]][index[pos[a]]-1];
		pos[k]=k;
		m[pos[k]][index[k]++]=k;}
	for(i=pos[b],bp=0;bp<index[i]&&m[i][bp]!=b;bp++);  // find b's pos
	for(;index[pos[b]]-1>bp;index[pos[b]]--){
		k=m[pos[b]][index[pos[b]]-1];
		pos[k]=k;
		m[pos[k]][index[k]++]=k;}
	m[pos[b]][index[pos[b]]++]=m[pos[a]][--index[pos[a]]];
	pos[a]=pos[b];
}
void move_over(int a,int b,int m[][25],int index[],int pos[]){
	int ap,bp;
	int i,k;
	for(i=pos[a],ap=0;ap<index[i]&&m[i][ap]!=a;ap++);  // find a's pos
	for(;index[pos[a]]-1>ap;index[pos[a]]--){
		k=m[pos[a]][index[pos[a]]-1];
		pos[k]=k;
		m[k][index[k]++]=k;}
	for(i=pos[b],bp=0;bp<index[i]&&m[i][bp]!=b;bp++);  // find b's pos	
	m[pos[b]][index[pos[b]]++]=m[pos[a]][--index[pos[a]]];	
	pos[a]=pos[b];
}
void pile_onto(int a,int b,int m[][25],int index[],int pos[]){
	int ap,bp;
	int i,j,k;
	int line;
	for(i=pos[a],ap=0;ap<index[i]&&m[i][ap]!=a;ap++);  // find a's pos	
	for(i=pos[b],bp=0;bp<index[i]&&m[i][bp]!=b;bp++);  // find b's pos
	for(;index[pos[b]]-1>bp;index[pos[b]]--){
		k=m[pos[b]][index[pos[b]]-1];
		pos[k]=k;
		m[pos[k]][index[k]++]=k;}
	for(i=index[pos[a]],j=ap,line=pos[a];i>j;j++){
		k=m[line][j];
		m[pos[b]][index[pos[b]]++]=k;
		pos[k]=pos[b];
		index[line]--;}
}
void pile_over(int a,int b,int m[][25],int index[],int pos[]){
	int ap;
	int i,j,k;
	int line;
	for(i=pos[a],ap=0;ap<index[i]&&m[i][ap]!=a;ap++);  // find a's pos		
	for(i=index[pos[a]],j=ap,line=pos[a];i>j;j++){
		k=m[line][j];
		m[pos[b]][index[pos[b]]++]=k;
		pos[k]=pos[b];
		index[line]--;}
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		char str1[10],str2[10];
		int pos[25];
		int m[25][25];
		int index[25];
		int a,b;
		int i,j;
		for(i=0;i<n;i++){
			index[i]=1;
			m[i][0]=i;
			pos[i]=i;}
		while(scanf("%s",str1)==1&&strcmp(str1,"quit")!=0){
			scanf("%d %s%d",&a,str2,&b);
			if(pos[a]==pos[b])
				continue;
			if(strcmp(str1,"move")==0)
				if(strcmp(str2,"onto")==0)
					move_onto(a,b,m,index,pos);
				else
					move_over(a,b,m,index,pos);
			else
				if(strcmp(str2,"onto")==0)
					pile_onto(a,b,m,index,pos);
				else
					pile_over(a,b,m,index,pos);}
		for(i=0;i<n;i++){
			printf("%d:",i);
			for(j=0;j<index[i];j++)
				printf(" %d",m[i][j]);
			putchar('\n');
		}
	}
	return 0;
}