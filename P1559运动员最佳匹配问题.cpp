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
int n;
int num(int x,int st){
    return 2+x+st*n;
}
int a[30][30],b[30][30];
int main(){
    scanf("%d",&n);
    s=1;t=2*n+10;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&b[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            add(num(i,0),num(j,1),1,a[i][j]*b[j][i]);
    for(int i=1;i<=n;i++)
        add(s,num(i,0),1,0),
        add(num(i,1),t,1,0);
    EK();
    printf("%d\n",ans);
}