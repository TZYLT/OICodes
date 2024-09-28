#include<bits/stdc++.h>
using namespace std;
int w[200200],v[200200],n,m;
pair<int,int> rg[200200];
long long cg[200200],sum[200200];
long long s;
long long check(int x){
    memset(sum,0,sizeof sum);
    memset(cg,0,sizeof cg);

    for(int i=1;i<=n;i++)
        cg[i]=(w[i]>=x),sum[i]=(w[i]>=x)?v[i]:0;
    for(int i=1;i<=n;i++)
        cg[i]+=cg[i-1],sum[i]+=sum[i-1];
    long long ans=0;
    for(int i=1;i<=m;i++)
        ans+=(cg[rg[i].second]-cg[rg[i].first-1])*(sum[rg[i].second]-sum[rg[i].first-1]);
    return ans;
}
long long t=0x7f7f7f7f7f7f7f7f;
int search(int l,int r){
    if(l==r)return l;
    int mid=(l+r)>>1;
    long long ans=check(mid);
    t=min(t,abs(ans-s));
    if(ans<s)return search(l,mid);
    else if(ans==s)return mid;
    else return search(mid+1,r);
}
int main(){
    scanf("%d%d%lld",&n,&m,&s);
    for(int i=1;i<=n;i++)
        scanf("%d%d",w+i,v+i);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&rg[i].first,&rg[i].second);
    search(0,1000100);
    printf("%lld\n",t);
}