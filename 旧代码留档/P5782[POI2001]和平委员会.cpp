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
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x=2*i-1,y=2*i;
        add(x,y+2*n);
        add(y+2*n,x);
        add(x+2*n,y);
        add(y,x+2*n);
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x+2*n,y);
        add(y+2*n,x);
    }
    for(int i=1;i<=n*4;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=n*2;i++)
        if(s[i]==s[i+n*2]){
            printf("NIE\n");
            return 0;
        }
    for(int i=1;i<=n*2;i++)
		if(s[i]>s[i+n*2])printf("%d\n",i);
}