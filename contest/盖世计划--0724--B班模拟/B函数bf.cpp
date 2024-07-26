#include<bits/stdc++.h>
using namespace std;
inline bool check(long long x){
    int c=__builtin_popcountll(x);
    if((x&(1<<(c+1)))==0||(x&(1<<(c-1))))
        return 1;
    else return 0;
}
int sum[(1<<20)+100];
long long t,l,r,ans;
int main(){
    freopen("function.in","r",stdin);
    freopen("function.out","w",stdout);
    sum[0]=1;
    for(int i=1;i<=(1<<20);i++)
        sum[i]=sum[i-1]+check(i);
    scanf("%lld",&t);
    while(t--){
        ans=0;
        scanf("%lld%lld",&l,&r);
        if((r+1)==(1ll<<__lg(r+1))&&(l==0||l==1)){
            printf("%lld",r+1-(1ll<<(__lg(r+1)-2))+(l==0));
            continue;
        }
        if(r<=(1<<20)){
            if(l==0)printf("%lld\n",sum[r]);
            else printf("%lld\n",sum[r]-sum[l-1]);
            continue;
        }
        for(int i=l;i<=r;i++)
            ans+=check(i);
        printf("%lld\n",ans);
    }
}