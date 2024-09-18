#include<bits/stdc++.h>
using namespace std;
#define M 10010
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cnt=0;C=0;T=0;top=0;
        memset(s,0,sizeof(s));
        memset(v,0,sizeof(v));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(nextt,0,sizeof(nextt));
        memset(head,0,sizeof(head));
        memset(st,0,sizeof(st));
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            string a,b;
            cin>>a>>b;
            int c=0,d=0,x=0,y=0;
            if(a[0]=='m')c=0;
            else c=1;
            if(b[0]=='m')d=0;
            else d=1;
            for(int j=1;j<a.size();j++)
                x*=10,x+=a[j]-'0';
            for(int j=1;j<b.size();j++)
                y*=10,y+=b[j]-'0';
            //printf("%d %d %d %d\n",c,x,d,y);
            add(x+(c^1)*n,y+d*n);
            add(y+(d^1)*n,x+c*n);    
        }
        for(int i=1;i<=n*2;i++)
            if(!dfn[i])
                tarjan(i);
        int f=1;
        for(int i=1;i<=n;i++)
            if(s[i]==s[i+n]){
                f=0;
                break;
            }
        if(f==1)printf("GOOD\n");
        else printf("BAD\n");
    }
}