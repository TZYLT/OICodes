#include<bits/stdc++.h>
using namespace std;
#define M 200200
const int inf=1<<30;
int head[M],nextt[M],edge[M],ver[M],cost[M],cnt=1;
int s,t;
void add(int x,int y,int z,int c){
    ver[++cnt]=y;edge[cnt]=z;cost[cnt]=c;nextt[cnt]=head[x];head[x]=cnt;
    ver[++cnt]=x;edge[cnt]=0;cost[cnt]=-c;nextt[cnt]=head[y];head[y]=cnt;
}
int d[M],v[M],incf[M],pre[M];
bool spfa(){
    queue<int> q;
    memset(d,0xcf,sizeof d);
    memset(v,0,sizeof v);
    q.push(s);d[s]=0;v[s]=1;incf[s]=inf;
    while(q.size()){
        int x=q.front();v[x]=0;q.pop();
        for(int i=head[x];i;i=nextt[i]){
            if(!edge[i])continue;
            int y=ver[i];
            if(d[y]<d[x]+cost[i]){
                d[y]=d[x]+cost[i];
                incf[y]=min(incf[x],edge[i]);
                pre[y]=i;
                if(!v[y])v[y]=1,q.push(y);
            }
        }
    }
    if(d[t]==0xcfcfcfcf)return 0;
    return 1;
}
int maxflow,ans;
void updata(){
    int x=t;
    while(x!=s){
        edge[pre[x]]-=incf[t];
        edge[pre[x]^1]+=incf[t];
        x=ver[pre[x]^1];
    }
    maxflow+=incf[t];
    ans+=d[t]*incf[t];
}
void EK(){
    while(spfa())updata();
}
int n,k;
int num(int i,int j,int st){
    return i+j*n+st*n*n;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            if(j+1<=n)add(num(i,j,1),num(i,j+1,0),k,0);
            if(i+1<=n)add(num(i,j,1),num(i+1,j,0),k,0);
            add(num(i,j,0),num(i,j,1),1,x);
            add(num(i,j,0),num(i,j,1),k-1,0);
        }
    add(s=1,num(1,1,0),k,0);
    t=num(n,n,1);
    EK();
    printf("%d\n",ans);
}