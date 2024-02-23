#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n==1||n==2||n==3||n==6){
		printf("-1\n");
		return 0;
	}
	else if(n==4)printf("1 2 1 0\n");
	else if(n==5)printf("2 1 2 0 0\n");
	else {
		printf("%d 2 1 ",n-4);
		for(int i=1;i<=n-7;i++)putchar('0'),putchar(' ');//printf("0 ");
		printf("1 0 0 0\n");
	}
}
