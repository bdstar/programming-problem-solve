//27391905	118	Mutant Flatworld Explorers	Accepted	C++11	0.000	2022-04-08 06:01:25
#include<stdio.h>
#define LOST 0
#define SAFE 1
static int max_x,max_y;
static int scent[1000][2];
static int total;
char change_face(char face,char c){
	if(c=='R')
		switch(face){
			case 'E':
				return 'S';
			case 'S':
				return 'W';
			case 'W':
				return 'N';
			case 'N':
				return 'E';}
	else
		switch(face){
			case 'E':
				return 'N';
			case 'S':
				return 'E';
			case 'W':
				return 'S';
			case 'N':
				return 'W';}
}
bool forward(char face,int *x,int *y){
	int i;
	int temp_x,temp_y;
	temp_x=(*x);
	temp_y=(*y);
	switch(face){ 
		case 'N':
			temp_y++;	break;
		case 'E':
			temp_x++;	break;
		case 'W':
			temp_x--;	break;
		case 'S':
			temp_y--;   break;}
	if(temp_x>max_x||temp_x<0||temp_y<0||temp_y>max_y){
		for(i=0;i<total;i++)
			if((*x)==scent[i][0]&&(*y)==scent[i][1])
				return SAFE;
		return LOST;}
	else{
		(*x)=temp_x;
		(*y)=temp_y;
		return SAFE;
	}
}
int main(){	
	scanf("%d%d",&max_x,&max_y);
	char c=getchar();
	int x,y;
	char face;
	char str[20];	
	total=0;
	while(gets(str)){
		sscanf(str,"%d%d %c",&x,&y,&face);
		int i;
		bool lost;
		char command[200];
		gets(command);
		for(i=0,lost=false;command[i]!='\0'&&(!lost);i++){
			if(command[i]=='F'){
				if(!forward(face,&x,&y))				
					lost=true;}
			else
				face=change_face(face,command[i]);
		}
		if(lost){
			printf("%d %d %c LOST\n",x,y,face);
			scent[total][0]=x;
			scent[total++][1]=y;}
		else
			printf("%d %d %c\n",x,y,face);
	}
	return 0;
}