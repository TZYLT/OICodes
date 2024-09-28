#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ms(x) memset(x,0,sizeof x)
int l[1600400],r[1600400];
long long sum[1600400],add[1600400];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        add[p]=sum[p]=0;
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    //sum[p]=sum[p*2]+sum[p*2+1];
}
void spread(int p){
    if(add[p]){
        sum[p*2]+=add[p];
        sum[p*2+1]+=add[p];
        add[p*2]+=add[p];
        add[p*2+1]+=add[p];
        add[p]=0;
    }
}
void change(int p,int li,int ri,long long d){
    if(li>ri)return;
    if(li<=l[p]&&ri>=r[p]){
        sum[p]+=d;
        add[p]+=d;
        return; 
    }
    spread(p);
    int mid=(l[p]+r[p])/2;
    if(li<=mid)change(p*2,li,ri,d);
    if(ri>mid)change(p*2+1,li,ri,d);
    sum[p]=max(sum[p*2],sum[p*2+1]);
}
long long ask(int p,int li,int ri){
    if(li>ri)return 0;
    if(li<=l[p]&&ri>=r[p]) return sum[p];
    spread(p);
    int mid=(l[p]+r[p])/2;
    long long v=0;
    if(li<=mid)v=max(v,ask(p*2,li,ri));
    if(ri>mid)v=max(v,ask(p*2+1,li,ri));
    return v;
} 
long long dp[400100],a[400100];
int t,n;
signed main(){
    scanf("%lld",&t);
    while(t--){
        ms(l);ms(r);ms(sum);ms(add);ms(dp);ms(a);
        scanf("%lld",&n);
        build(1,1,n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=n;i>=1;i--){
            dp[i]=a[i];
            int l=i+1,r=min<long long>(a[i]+i,n);
            dp[i]=max(dp[i],ask(1,l,r));
            change(1,l,n,a[i]);
            change(1,i,i,dp[i]);
        }
        printf("%lld\n",dp[1]);
    }
}