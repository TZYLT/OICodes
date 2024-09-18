#include<bits/stdc++.h>
using namespace std;
int f[70];
int merge(int x){
    for(int i=31;~i;i--)
        if(x>>i&1){
            if(!f[i])return f[i]=x,1;
            else x^=f[i];
        }
    return 0;
}
int n;
vector<pair<int,int> > a;
int main(){
    scanf("%d",&n);
    for(int i=1,x;i<(1<<n);i++)
        scanf("%d",&x),a.push_back(make_pair(x,i));
    sort(a.begin(),a.end());
    long long ans=0;
    for(int i=0;i<(1<<n)-1;i++)
        if(merge(a[i].second))
            ans+=a[i].first;
    printf("%lld\n",ans);
}