#include<bits/stdc++.h>
using namespace std;
int n,nxt[1000010];
string s;
void kmp(void){
	nxt[1]=0;
	for(int i=2;i<=n;i++){
		int p=nxt[i-1];
		while(p!=0){
			if(s[p+1]==s[i])break;
			else p=nxt[p];
		}
		nxt[i]=(s[p+1]==s[i])?p+1:0;
	}
}

int main(){
	scanf("%d",&n);
	cin>>s;
	s='0'+s;
	kmp();
	printf("%d",n-nxt[n]);
}
