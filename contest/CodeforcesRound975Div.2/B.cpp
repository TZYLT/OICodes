#include<bits/stdc++.h>
using namespace std;
int t,n,q;
long long x[200200];
map<long long,long long> ans;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(long long i=1;i<=n;i++)
            scanf("%lld",x+i);

        for(long long i=1;i<n;i++)
            ans[i*(n-i)]+=(x[i+1]-x[i]-1);
        for(long long i=1;i<=n;i++)
            ans[(i-1)*(n-i)+i-1+n-i]+=1;
        while(q--){
            long long k;
            scanf("%lld",&k);
            if(ans.count(k))printf("%lld ",ans[k]);
            else printf("0 ");
        }
        printf("\n");
        for(long long i=1;i<=n;i++)
            x[i]=0;
        ans.clear();
    }
}