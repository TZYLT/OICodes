#include<bits/stdc++.h>
using namespace std;
#define M 2500000
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int dfn[M],low[M],v[M],st[M],top,T,C,s[M];
void tarjan(int x){
    dfn[x]=low[x]=++T;
    st[++top]=x;
    v[x]=1;
    for(int i=head[x];i;i=nextt[i]){
        if(!dfn[ver[i]]){
            tarjan(ver[i]);
            low[x]=min(low[x],low[ver[i]]);
        }
        else if(v[ver[i]])low[x]=min(low[x],dfn[ver[i]]);
    }
    if(dfn[x]==low[x]){
        C++;
        while(st[top]!=x){
            s[st[top]]=C;
            v[st[top]]=0;
            top--;
        }
        s[st[top]]=C;
        v[st[top]]=0;
        top--;
    }
}
int n,m;
int i,a,j,b;
int main(){
    scanf("%d%d",&n,&m);
	for(int k=1;k<=m;k++){
		scanf("%d%d%d%d",&i,&a,&j,&b);
		add(i+a*n,j+(b^1)*n);
		add(j+b*n,i+(a^1)*n);
	}
	for(int i=1;i<=2*n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		if(s[i]==s[i+n]){
			printf("IMPOSSIBLE\n");
			return 0;
		}
	printf("POSSIBLE\n");
	for(int i=1;i<=n;i++)
		if(s[i]>s[i+n])printf("1 ");
		else printf("0 ");
}