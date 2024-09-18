#include<bits/stdc++.h>
using namespace std;
#define M 100050
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
int T,n;
int num(int x,int st){
    return 1+x+st*n;
}

int main(){
    scanf("%d",&T);
    while(T--){
        ms(head);ms(nextt);ms(edge);ms(ver);ms(d);ms(now);
        cnt=1;

        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                int x;
                scanf("%d",&x);
                if(x==1)add(num(i,0),num(j,1),1);
            }
        s=1;t=n*2+10;
        for(int i=1;i<=n;i++)
            add(s,num(i,0),1);
        for(int i=1;i<=n;i++)
            add(num(i,1),t,1);
        printf(dinic()==n?"Yes\n":"No\n");
    }
    

}