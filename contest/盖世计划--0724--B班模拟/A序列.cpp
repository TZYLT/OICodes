#include<bits/stdc++.h>
using namespace std;
long long n,q,s;
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    while(q--){
        scanf("%lld",&s);
        long long ans=0;
        if(s%(n+1)==0&&(n/2-s/(n+1)+1)>=0)ans+=(n/2-s/(n+1)+1);
        long long r=s%(n+1),len=(s/(n+1))*2;
        if(((2*n+2-2*r)+len<=n)&&((2*n+2-2*r)<=n))ans++;
        if(((2*r-1)-len>=1)&&((2*r-1)<=n))ans++;
        if(r==len/2+n+2)ans+=((n+1)/2)-1-(len/2);
        if(len>=2){
            len-=2;
            r+=n+1;
            if(r==len/2+n+2)ans+=((n+1)/2)-1-(len/2);
        }
        printf("%lld\n",ans);
    }
}