#include<bits/stdc++.h>
using namespace std;
#define M 300300
long long head[M],nextt[M],edge[M],ver[M],cnt=1;
bool v[M]={0};
void add(int x,int y,long long z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
long long sum[M];
long long f[70];

void merge(long long x){
    for(int i=62;i>=0;i--)
        if(x>>i&1){
            if(!f[i])return f[i]=x,void();
            else x^=f[i];
    }
}
void dfs(int fa,int x,long long w){
    sum[x]=sum[fa]^w;v[x]=1;
    
    for(int i=head[x];i;i=nextt[i])
        if(v[ver[i]]==0)
            dfs(x,ver[i],edge[i]);
        else if(ver[i]!=fa)
            merge(edge[i]^sum[x]^sum[ver[i]]);
}

int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;long long z;
        scanf("%d%d%lld",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    v[0]=0;
    dfs(0,1,0);
    long long t=sum[n];
    for(int i=62;~i;i--)
        t=max(t,t^f[i]);
    cout<<t<<endl;
}