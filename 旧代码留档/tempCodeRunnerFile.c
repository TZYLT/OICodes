#include<bits/stdc++.h>
using namespace std;
#define M 10010
int head[M],nextt[M],ver[M],w[M],c[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int head1[M],nextt1[M],ver1[M],cnt1;
void add1(int x,int y){
    ++cnt1;
    ver1[cnt1]=y;
    nextt1[cnt1]=head1[x];
    head1[x]=cnt1;
}

bool v[5050];
void dfs_btr(int x,int fa,int top){
    if(v[x]&&top!=x)add1(top,x),add1(x,top),top=x;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            dfs_btr(ver[i],x,top);
}
int t=0;
int dp[5050][5050],ans=0;

void dfs(int x,int fa){
    if(v[x]){
        for(int i=0;i<=t;i++)
            dp[x][i]=dp[fa][i];
        for(int i=c[x];i<=t;i++)
            dp[x][i]=max(dp[fa][i-c[x]]+w[x],dp[x][i]),ans=max(ans,dp[x][i]);
    }else{
        for(int i=0;i<=t;i++)
            dp[x][i]=dp[fa][i],ans=max(ans,dp[x][i]);
    }
    for(int i=head1[x];i;i=nextt1[i])
        if(ver1[i]!=fa)dfs(ver1[i],x);
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    for(int i=1;i<=n;i++)
        scanf("%d",c+i);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    while(m--){
        int k;
        scanf("%d%d",&t,&k);
        for(int i=1;i<=k;i++){
            int x;
            scanf("%d",&x);
            v[x]=1;
        }
        dfs_btr(1,0,1);
        
        dfs(1,0);
        printf("%d\n",ans);

        v[1]=1;
        for(int i=1;i<=n;i++)
            if(v[i])
                for(int j=0;j<=t;j++)
                    dp[i][j]=0;
        for(int i=0;i<=n;i++)
            head1[i]=0;
        for(int i=0;i<=cnt1;i++)
            nextt1[i]=ver1[i]=0;
        cnt1=0;ans=0;
        memset(v,0,sizeof v);
    }
}