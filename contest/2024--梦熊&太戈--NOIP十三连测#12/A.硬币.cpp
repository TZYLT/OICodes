#include<bits/stdc++.h>
using namespace std;
map<long long,int> st;
long long a[61];
int n;long long ans=0;
int main(){
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(int i=2;i<=n;i++)
        st[a[i]/a[i-1]]++;
    ans++;
    for(auto c:st){
        if(c.second==0)continue;
        long long t=1,tt=0;
        while(t<c.second)tt++,t*=c.first;
        ans=max(ans,1+tt);
    }
    printf("%lld\n",ans);
}