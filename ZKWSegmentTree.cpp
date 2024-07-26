#include<bits/stdc++.h>
using namespace std;
#define M 200005
int sum[M<<2],add[M<<2],data[M<<2];
int n,N=1;
void build(int n){
    while(N<=n+1)N<<=1;
    for(int i=N+1;i<=N+n;++i)sum[i]=data[i-N];
    for(int i=N-1;i>=1;--i)sum[i]=sum[i<<1]+sum[i<<1|1];
}
void update(int l,int r,int k){
    int lNum=0,rNum=0,nNum=1;
    for(l=N+l-1,r=N+r+1;l^r^1;l>>=1,r>>=1,nNum<<=1){
        sum[l]+=k*lNum;
        sum[r]+=k*rNum;
        if(~l&1){add[l^1]+=k;sum[l^1]+=k*nNum;lNum+=nNum;}
        if(r&1){add[r^1]+=k;sum[r^1]+=k*nNum;rNum+=nNum;}
    }
    for(;l;l>>=1,r>>=1){
        sum[l]+=k*lNum;
        sum[r]+=k*rNum;
    } 
}
int query(int l,int r){
    int lNum=0,rNum=0,nNum=1;
    int ans=0;
    for(l=N+l-1,r=N+r+1;l^r^1;l>>=1,r>>=1,nNum<<=1){
        if(add[l])ans+=add[l]*lNum;
        if(add[r])ans+=add[r]*rNum;
        if(~l&1){ans+=sum[l^1];lNum+=nNum;}
        if(r&1){ans+=sum[r^1];rNum+=nNum;}
    }
    for(;l;l>>=1,r>>=1) {
        ans+=add[l]*lNum;
        ans+=add[r]*rNum;
    }
    return ans;
}
