#include<bits/stdc++.h>
using namespace std;
int n,nxt[4000010];
string s1,s2,st;
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
	cin>>s2;
	//printf("%d\n%d\n",s1.size(),s2.size());
	st='0'+s2+'#'+s1;
	kmp(st);
	for(int i=s2.size();i<=st.size();i++)
		if(nxt[i]==s2.size())
			printf("%d\n",i-2*s2.size());
	for(int i=1;i<=s2.size();i++)
		printf("%d ",nxt[i]);
}
