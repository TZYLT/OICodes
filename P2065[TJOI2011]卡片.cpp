#include<bits/stdc++.h>
using namespace std;
#define M 1400100
#define ms(x) memset((x),0,sizeof(x))
int head[M],nextt[M],edge[M],ver[M],d[M],now[M],cnt=1;
void add(int x,int y,int z){
    ++cnt;ver[cnt]=y;edge[cnt]=z;nextt[cnt]=head[x];head[x]=cnt;
    ++cnt;ver[cnt]=x;edge[cnt]=0;nextt[cnt]=head[y];head[y]=cnt;
}
int s,t;
bool bfs(){
    memset(d,0,sizeof d);
    queue<int> q;
    q.push(s);d[s]=1;now[s]=head[s];
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=head[x];i;i=nextt[i])
            if(edge[i]&&!d[ver[i]]){
                q.push(ver[i]);
                now[ver[i]]=head[ver[i]];
                d[ver[i]]=d[x]+1;
                if(ver[i]==t)return 1;
            }
    }
    return 0;
}
int getflow(int x,int flow){
    if(x==t)return flow;
    int rest=flow;
    for(int i=now[x];i&&rest;i=nextt[i]){
        now[x]=i;
        if(edge[i]&&d[ver[i]]==d[x]+1){
            int k=getflow(ver[i],min(rest,edge[i]));
            if(!k)d[ver[i]]=0;
            edge[i]-=k;edge[i^1]+=k;
            rest-=k;
        }
    }
    return flow-rest;
}
int dinic(){
    int flow,maxflow=0;
    while(bfs())
        while(flow=getflow(s,(1<<29)))
            maxflow+=flow;
    return maxflow;        
}
int p[10000100],v[10000100],k,mn[10000100];
void linearSieve(int n){
    v[1]=1;mn[1]=0;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i,mn[i]=k;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            mn[i*p[j]]=j;
            if(i%p[j]==0)break;
        }
    }
}
int n,m;
int a[M],b[M];
int num(int x,int st){
    if(st==0)return 3+x;
    else if(st==1)return 3+x+n;
    else if(st==2)return 3+x+n+m;
}
int T;const int inf=1<<28;
int main(){
    linearSieve(10000000);
    scanf("%d",&T);
    while(T--){
        ms(head);ms(nextt);ms(edge);ms(ver);ms(d);ms(now);
        cnt=1;
        ms(a);ms(b);

        scanf("%d%d",&n,&m);
        s=1;t=n+m+k+10;
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            add(s,num(i,0),1);
            while(a[i]!=1){
                int c=p[mn[a[i]]];
                add(num(i,0),num(mn[a[i]],2),inf);
                while(a[i]!=1&&a[i]%c==0)a[i]/=c;
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%d",b+i);
            add(num(i,1),t,1);
            while(b[i]!=1){
                int c=p[mn[b[i]]];
                add(num(mn[b[i]],2),num(i,1),inf);
                while(b[i]!=1&&b[i]%c==0)b[i]/=c;
            }
        }  
        printf("%d\n",dinic());
    }
}