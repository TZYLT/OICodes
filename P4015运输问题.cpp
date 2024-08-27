#include<bits/stdc++.h>
using namespace std;
#define M 200200
const int inf=1<<30;
#define ms(x) memset(x,0,sizeof x);
int head[M],nextt[M],edge[M],ver[M],cost[M],cnt=1;
int s,t;
void add(int x,int y,int z,int c){
    ver[++cnt]=y;edge[cnt]=z;cost[cnt]=c;nextt[cnt]=head[x];head[x]=cnt;
    ver[++cnt]=x;edge[cnt]=0;cost[cnt]=-c;nextt[cnt]=head[y];head[y]=cnt;
}
int d[M],v[M],incf[M],pre[M];
int tag=0;
bool spfa(){
    queue<int> q;
    if(tag==0)memset(d,0x7f,sizeof d);
    else memset(d,0xcf,sizeof d);
    memset(v,0,sizeof v);
    q.push(s);d[s]=0;v[s]=1;incf[s]=inf;
    while(q.size()){
        int x=q.front();v[x]=0;q.pop();
        for(int i=head[x];i;i=nextt[i]){
            if(!edge[i])continue;
            int y=ver[i];
            if(d[y]>d[x]+cost[i]&&tag==0){
                d[y]=d[x]+cost[i];
                incf[y]=min(incf[x],edge[i]);
                pre[y]=i;
                if(!v[y])v[y]=1,q.push(y);
            }
            if(d[y]<d[x]+cost[i]&&tag==1){
                d[y]=d[x]+cost[i];
                incf[y]=min(incf[x],edge[i]);
                pre[y]=i;
                if(!v[y])v[y]=1,q.push(y);
            }
        }
    }
    if(d[t]==0x7f7f7f7f&&tag==0)return 0;
    if(d[t]==0xcfcfcfcf&&tag==1)return 0;
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
int n,m;
int id(int x,int st){
    return 3+x+st*n;
};
int a[M],b[M],c[120][120];
int main(){
    scanf("%d%d",&n,&m);
    s=1;t=n+m+10;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        a[i]=x;
        add(s,id(i,0),x,0);
    }
    for(int i=1;i<=m;i++){
        int x;scanf("%d",&x);
        b[i]=x;
        add(id(i,1),t,x,0);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int x;scanf("%d",&x);
            c[i][j]=x;
            add(id(i,0),id(j,1),inf,x);
        }
    EK();
    printf("%d\n",ans);
    ms(head);ms(nextt);ms(edge);ms(ver);ms(d);ms(v);ms(incf);ms(pre);
    cnt=1;ans=0;maxflow=0;tag=1;
    for(int i=1;i<=n;i++)
        add(s,id(i,0),a[i],0);
    
    for(int i=1;i<=m;i++)
        add(id(i,1),t,b[i],0);
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            add(id(i,0),id(j,1),inf,c[i][j]);
        
    EK();
    printf("%d\n",ans);
}