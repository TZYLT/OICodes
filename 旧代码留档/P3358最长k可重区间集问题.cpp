#include<bits/stdc++.h>
using namespace std;
#define M 300200
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
pair<int,int> range[1000];
int len[1010];
int n,k;
vector<int> sd;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&range[i].first,&range[i].second);
        sd.push_back(range[i].first);
        sd.push_back(range[i].second);
    }
    sort(sd.begin(),sd.end());
    int x=unique(sd.begin(),sd.end())-sd.begin();
    for(int i=1;i<=n;i++){
        len[i]=range[i].second-range[i].first;
        range[i].first=2+lower_bound(sd.begin(),sd.begin()+x+1,range[i].first)-sd.begin();
        range[i].second=2+lower_bound(sd.begin(),sd.begin()+x+1,range[i].second)-sd.begin();
        //printf("[%d %d]\n",range[i].first,range[i].second);
    }
    s=1;t=2*n+3;
    for(int i=1;i<=2*n+2;i++)
        add(i,i+1,k,0);
    for(int i=1;i<=n;i++)
        add(range[i].first,range[i].second,1,len[i]);
    EK();
    printf("%d\n",ans);
}