#include<bits/stdc++.h>
using namespace std;
int n,m;
long long s;
int k[1001000],b[1001000];
bool check(int t){
    vector<long long> cs;
    for(int i=1;i<=n;i++)
        cs.push_back(1ll*k[i]*t+b[i]);
    sort(cs.begin(),cs.end());
    long long ans=0;
    for(int i=1;i<=m;i++)
        if(cs[n-i]>0)ans+=cs[n-i];
        else break;
    return s<=ans;
}
int sc(int l,int r){
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(check(mid))return sc(l,mid);
    else return sc(mid+1,r);
}
int main(){
    freopen("merchant.in","r",stdin);
    freopen("merchant.out","w",stdout);
    scanf("%d%d%lld",&n,&m,&s);
    for(int i=1;i<=n;i++)
        scanf("%d%d",k+i,b+i);
    printf("%d\n",sc(0,2000000000));
}