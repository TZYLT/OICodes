#include<bits/stdc++.h>
using namespace std;
int dp[1<<16];
long long a[100100];
int n,k;long long c[20];
int getid(int l,int r,long long x){
    if(l==r)return l;
    if(l+1==r){
        if(a[r]<=x)return r;
        else return l;
    }
    int mid=(l+r)>>1;
    if(a[mid]<=x)return getid(mid,r,x);
    else return getid(l,mid,x);
}
int main(){
    scanf("%d%d",&k,&n);
    for(int i=1;i<=k;i++)
        scanf("%lld",c+i);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    for(int i=0;i<(1<<k);i++)
        for(int j=1;j<=k;j++)
            if(!((i>>(j-1))&1)){
                long long tmp=a[dp[i]]+c[j];
                dp[i|(1<<(j-1))]=max(dp[i|(1<<(j-1))],getid(1,n,tmp));
            }
    long long ans=-1;
    for(int i=0;i<(1<<k);i++)
        if(dp[i]==n){
            long long tmp=0;
            for(int j=1;j<=k;j++)
                if(!((i>>(j-1))&1))tmp+=c[j];
            ans=max(tmp,ans);
        }
    printf("%lld\n",ans);
        

}