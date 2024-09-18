#include<bits/stdc++.h>
using namespace std;

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
int id(int x,int i,int st,int l){
    return (x-1)*(m*6)+i+m*((st==1)*3+l);
}
int n,m,q;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        for(int j=0)
    }
}