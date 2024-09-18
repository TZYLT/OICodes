#include<bits/stdc++.h>
using namespace std;
int n,m,t;long long tp;
long long k;
int mp[1001000];
long long ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    scanf("%d %d %lld %d",&n,&m,&k,&t);
    for(int i=1;i<=n*m;i++)
        cin>>mp[i];
    sort(mp+1,mp+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
        if(t>0){
            t--;ans+=mp[i];
            tp+=mp[i];
            t+=tp/k;
            tp%=k;

        }
    printf("%lld\n",ans);
}