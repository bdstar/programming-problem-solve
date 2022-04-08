//27391916	120	Stacks of Flapjacks	Accepted	C++11	0.000	2022-04-08 06:06:24
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>

using namespace std;

typedef long long lli;
typedef unsigned long long ull;

#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int res[MAX_N];
int ori[MAX_N];
int n;
void input(char S[]){
	int tmp = 0, i = 0;
	n = 0;
	for (i = 0; S[i] != '\0'; i++)
		if (S[i] == ' ')
			ori[n++] = tmp, tmp = 0;
		else
			tmp = tmp * 10 + S[i] - '0';
	ori[n++] = tmp;
}
int main(){
	char str[10000];
	while (gets(str)){
		input(str);
		for (int i = 0; i < n; i++)
			res[i] = ori[i];
		sort(res, res + n);
		bool first = true;
		for (int i = 0; i < n; i++){
			if (i != 0)	putchar(' ');
			printf("%d", ori[i]);
		}
		putchar('\n');
		for (int i = n - 1; i >= 0; i--){
			int target = res[i], pos;
			for (pos = i; pos >= 0; pos--)
				if (ori[pos] == target)
					break;
			if (pos == i)	continue;
			if (pos != 0){
				if (!first)	putchar(' ');
				printf("%d", n - pos), first = false;
				for (int j = 0, k = pos; j < k; j++, k--)
					swap(ori[j], ori[k]);
			}
			if (!first)	putchar(' ');
			printf("%d", n - i);
			first = false;
			for (int j = 0, k = i; j < k; j++, k--)
				swap(ori[j], ori[k]);
		}
		if (!first)	putchar(' ');
		printf("%d\n", 0);
	}
	return 0;
}