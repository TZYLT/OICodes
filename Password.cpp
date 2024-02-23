#include<bits/stdc++.h>
using namespace std;
int nxt[4000010];
string s1;
void kmp(string &s){
	nxt[1]=0;
	for(int i=2;i<=s.size();i++){
		int p=nxt[i-1];
		while(p!=0){
			if(s[p+1]==s[i])break;
			else p=nxt[p];
		}
		nxt[i]=(s[p+1]==s[i])?p+1:0;
	}
}

int main(){
	cin>>s1;
	s1=' '+s1;
	kmp(s1);
	int m=0;
	
	for(int i=1;i<=s1.size()-2;i++)
		m=max(m,nxt[i]);
	int ans=-1;
	for(int p=nxt[s1.size()-1];p;p=nxt[p])
		if(p<=m){
			ans=p;
			break;
		}
	if(ans==-1)printf("Just a legend\n");
	else for(int i=1;i<=ans;i++)
			putchar(s1[i]);
}
