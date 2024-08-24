#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
vector<pair<int,int> > ed;
int n,m,k,ans;
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int main(){
    freopen("head.in","r",stdin);
    freopen("head.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,x,y;i<=m;i++)
        scanf("%d%d",&x,&y),ed.push_back(make_pair(x,y));
    for(int i=1;i<(1<<n);i++){
        int s=0;
        for(auto c:ed)
            if((i>>(c.first-1)&1)&&(i>>(c.second-1)&1))
                s++;
        ans=(ans+qpow(s,k))%p;
    }
    printf("%d\n",ans);
}