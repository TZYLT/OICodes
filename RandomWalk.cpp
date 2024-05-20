#include<bits/stdc++.h>
using namespace std;
#define M 500500
#define p 998244353
int head[M],nextt[M],ver[M],deg[M],cnt;
void add(int x,int y){
    ++cnt;

    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}

long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int n,x,y,s,t;
int a[M],b[M],dp[M];
void dfs1(int x,int fa){
    
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
        dfs1(ver[i],x);
        a[x]=(1ll*a[ver[i]]*qpow(deg[ver[i]],p-2)+a[x])%p;
        b[x]=(1ll*b[ver[i]]*qpow(deg[ver[i]],p-2)+b[x])%p;
    }
    b[x]+=(s==x);
    a[x]=(1ll-a[x]+p)%p;
    b[x]=(1ll*b[x]*qpow(a[x],p-2)%p);
    a[x]=1ll*a[x]*deg[x]%p;
    a[x]=qpow(a[x],p-2);
}

void dfs2(int x,int fa){
    if(x==t)dp[x]=1;
    else dp[x]=(1ll*a[x]*dp[fa]%p+b[x])%p;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)dfs2(ver[i],x);
}
int main(){
    scanf("%d%d%d",&n,&s,&t);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        deg[x]++;
        deg[y]++; 
        add(x,y);
        add(y,x);
    }
    dfs1(t,0);
    dfs2(t,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",dp[i]);
    
}