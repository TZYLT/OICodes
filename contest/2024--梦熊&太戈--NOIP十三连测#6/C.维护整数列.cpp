#include<bits/stdc++.h>
using namespace std;
#define M 500400
#define mod 1000000007
int sum[M],ssq[M],no[M];
int a[M];
void build(int p,int l,int r){
    if(l==r){
        sum[p]=a[l]%mod;
        ssq[p]=1ll*a[l]*a[l]%mod;
        no[p]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build((p<<1)|1,mid+1,r);
    sum[p]=(sum[p<<1]+sum[(p<<1)|1])%mod;
    ssq[p]=(ssq[p<<1]+ssq[(p<<1)|1])%mod;
    no[p]=no[p<<1]+no[(p<<1)|1];
}
void change(int p,int L,int R,int l,int r,int d){
    if(l<=L&&R<=r&&no[p]==0)return;
    if(L==R){
        a[L]=floor((float)a[L]/d);
        if(a[L]==-1||a[L]==1)no[p]=0;
        sum[p]=a[L]%mod;
        ssq[p]=1ll*a[L]*a[L]%mod;
        return;
    }
    int mid=(L+R)>>1;
    if(l<=mid)change(p<<1,L,mid,l,r,d);
	if(r>mid)change((p<<1)|1,mid+1,R,l,r,d);
    sum[p]=(sum[p<<1]+sum[(p<<1)|1])%mod;
    ssq[p]=(ssq[p<<1]+ssq[(p<<1)|1])%mod;
    no[p]=no[p<<1]+no[(p<<1)|1];
}
void add(int p,int L,int R,int x,int d){
    if(L==R&&L==x){
        a[L]=d;
        if(a[L]==-1||a[L]==1)no[p]=0;
        else no[p]=1;
        sum[p]=a[L]%mod;
        ssq[p]=1ll*a[L]*a[L]%mod;
        return;
    }
    int mid=(L+R)>>1;
    if(x<=mid)add(p<<1,L,mid,x,d);
	if(x>mid)add((p<<1)|1,mid+1,R,x,d);
    sum[p]=(sum[p<<1]+sum[(p<<1)|1])%mod;
    ssq[p]=(ssq[p<<1]+ssq[(p<<1)|1])%mod;
    no[p]=no[p<<1]+no[(p<<1)|1];
}
int asksum(int p,int L,int R,int l,int r){
    if(l<=L&&R<=r)return sum[p];
    int ans=0;
    int mid=(L+R)>>1;
    if(l<=mid)ans=(ans+asksum(p<<1,L,mid,l,r))%mod;
	if(r>mid)ans=(ans+asksum((p<<1)|1,mid+1,R,l,r))%mod;
    return ans;
}
int asksq(int p,int L,int R,int l,int r){
    if(l<=L&&R<=r)return ssq[p];
    int ans=0;
    int mid=(L+R)>>1;
    if(l<=mid)ans=(ans+asksq(p<<1,L,mid,l,r))%mod;
	if(r>mid)ans=(ans+asksq((p<<1)|1,mid+1,R,l,r))%mod;
    return ans;
}
int n,m;
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    build(1,1,n);
    while(m--){
        int op,l,r,x;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1)printf("%d\n",asksum(1,1,n,l,r));
        else if(op==2)printf("%d\n",asksq(1,1,n,l,r));
        else if(op==3){
            scanf("%d",&x);
            change(1,1,n,l,r,x);
        }else{
            add(1,1,n,l,r);
        }
    }
}