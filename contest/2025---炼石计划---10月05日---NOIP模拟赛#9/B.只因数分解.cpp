#include<bits/stdc++.h>
using namespace std;

long long fac,m;
int t,n;
vector<long long> path,ans;
int sol(long long x,int d){
    if(d>n)return 0;
    if(x==0){ 
        ans=path;
        return 1;
    }
    for(long long i=x;i>=1;i--)
        if(fac%i==0){
            path.push_back(i);
            int k=sol(x-i,d+1);
            path.pop_back();
            if(k)return 1;
        }
        return 0;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&m);fac=1;
        for(long long i=2;i<=n;i++)
            fac*=i;
        //ans.clear();path.clear();
        sol(m,0);
        printf("%d\n",ans.size());
        for(auto c:ans)
            printf("%lld ",c);
        printf("\n");
    }
}