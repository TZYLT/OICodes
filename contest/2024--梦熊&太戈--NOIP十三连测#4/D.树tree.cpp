#include<bits/stdc++.h>
using namespace std;
#define M 600600
unsigned ps,rt;
unsigned xs(unsigned x){
    x^=x<<13;
    x^=x>>17;
    x^=x<<5;
    x^=ps;
    return x;
}
#define mod 998244353
int head[M],nextt[M],ver[M],cnt;
int sum[M],fa[M],fac[M];
unsigned Hash[M];
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
void dfs(int x,int f){
    Hash[x]=rt;fa[x]=f;
    multiset<unsigned> s;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=f){
            dfs(ver[i],x);
            Hash[x]=Hash[x]+xs(Hash[ver[i]]);
            s.insert(Hash[ver[i]]);
            sum[x]=1ll*sum[x]*sum[ver[i]]%mod;
        }
    for(int i=head[x];i;i=nextt[i])
        sum[x]=1ll*sum[x]*fac[s.count(Hash[ver[i]])]%mod;
}

void change(int x,int f){
    if(x==0)return;
    Hash[x]=rt;fa[x]=f;sum[x]=1;
    multiset<unsigned> s;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=f){
            Hash[x]=Hash[x]+xs(Hash[ver[i]]);
            s.insert(Hash[ver[i]]);
            sum[x]=1ll*sum[x]*sum[ver[i]]%mod;
        }
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=f){
            sum[x]=1ll*sum[x]*fac[s.count(Hash[ver[i]])]%mod;
            s.erase(Hash[ver[i]]);
        }
    change(fa[x],fa[fa[x]]);
    //printf("[%d]:%d\n",x,sum[x]);
}
int n;
int tot=1;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    srand(time(0));
    ps=1ll*rand()*rand();
    rt=1ll*rand()*rand();
    dfs(1,0);
    fac[0]=1;
    for(int i=1;i<=300000;i++)
        fac[i]=1ll*fac[i-1]*i%mod;
    scanf("%d",&n);
    while(n--){
        int op,x;
        scanf("%d%d",&op,&x);
        if(op==0){
            tot++;
            add(tot,x);
            add(x,tot);
            change(tot,x);
        }else{
            printf("%d\n",sum[x]);
        }
    }
}