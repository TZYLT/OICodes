#include<bits/stdc++.h>
using namespace std;
#define M 200200
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
vector<int> ans[50];
int n,m,k;
int num(int x,int st){
    return 3+x+st*n;
}
int main(){
    scanf("%d%d",&k,&n);
    s=1;t=n+k+10;
    for(int i=1;i<=k;i++){
        int x;scanf("%d",&x);m+=x;
        add(num(i,1),t,x);
    }
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        add(s,num(i,0),1);
        for(int j=1;j<=x;j++){
            int y;scanf("%d",&y);
            add(num(i,0),num(y,1),1);
        }
    }
    int p=dinic();
    if(p!=m)printf("No Solution!\n");
    else{
        for(int i=1;i<=n;i++)
            for(int j=head[num(i,0)];j;j=nextt[j])
                if(ver[j]<=num(k,1)&&ver[j]>=num(1,1)&&edge[j]==0)
                    ans[ver[j]-num(0,1)].push_back(i);
        
        //for(int j=head[s];j;j=nextt[j])
        //    if(ver[j]<=num(n,0)&&ver[j]>=num(1,0)&&edge[j]==0)
        //        ans[0].push_back(ver[j]-num(0,0));
        //for(int c:ans[0])
        //    printf("%d ",c);printf("\n");
        for(int i=1;i<=k;i++){
            printf("%d: ",i);
            for(int c:ans[i])
                printf("%d ",c);
            printf("\n");
        }
    }
}