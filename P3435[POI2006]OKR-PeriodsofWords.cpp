#include<bits/stdc++.h>
using namespace std;
int n,nxt[4000010],P[4000010];
string s;
void kmp(string &s){
	nxt[1]=0;
	for(int i=2;i<=s.size()-1;i++){
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
	s=' '+s;
	kmp(s);
	for(int i=1;i<=n;i++){
		if(nxt[i]==0) P[i]=0; 
		else if(nxt[nxt[i]]==0) P[i]=nxt[i];
		else P[i]=P[nxt[i]];
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=P[i]?i-P[i]:0;
		printf("%lld\n",ans);
}
