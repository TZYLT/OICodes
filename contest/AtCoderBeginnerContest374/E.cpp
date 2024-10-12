#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[101],p[101],b[101],q[101];

int check(int maxx){
    int cost=0;
    for(int i=1;i<=n;i++){
        cost+=min((int)ceil((double)maxx/a[i])*p[i],(int)ceil((double)maxx/b[i])*q[i]);
    }
    return cost<=m;
}
int sc(int l,int r){
    if(l==r)return l;
    if(l+1==r){
        if(check(r))return r;
        else return l;
    }
    int mid=(l+r)>>1;
    if(check(mid))return sc(mid,r);
    else return sc(l,mid);
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld%lld%lld",a+i,p+i,b+i,q+i);
    printf("%lld\n",sc(0,20000000000ll));
}