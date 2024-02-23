#include<bits/stdc++.h>
using namespace std;
#define M 100100
int fa[M],len[M],s[M];
void init(void){
	for(int i=0;i<=100000;i++) fa[i]=i,len[i]=0,s[i]=1;
}
int get(int x){
	if(fa[x]==x)return x;
	int k=fa[x];
	fa[x]=get(fa[x]);
	len[x]+=len[k];
	s[x]=s[fa[x]];
	return fa[x];
}
void merge(int x,int y){
	int i=get(x),j=get(y);
	if(i==j) return;
	fa[i]=j;
	len[i]=len[j]+s[j];
	s[j]+=s[i];
	s[i]=s[j];
}

int T;
int main(){
	scanf("%d",&T);
	init();
	while(T--){
		char op;int x,y;
		cin>>op>>x>>y;
		if(op=='M') merge(y,x);
		else printf("%d\n",(get(x)!=get(y))?-1:(abs(len[x]-len[y])-1));
		
	}
}
