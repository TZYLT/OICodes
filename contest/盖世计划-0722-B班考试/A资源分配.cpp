#include<bits/stdc++.h>
using namespace std;
#define M 500050
int a[M],w[M],bt[M],n,m;
long long ans;
set<int> s;
pair<int,int> dt[M];
int main(){
    freopen("resource.in","r",stdin);
    freopen("resource.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i),dt[i].first=w[i],dt[i].second=a[i];
    sort(a+1,a+1+n);
    sort(dt+1,dt+1+n);
    int cnt=a[1];
    for(int i=1;i<=n;i++){
        cnt=max(cnt,a[i]);
        while(s.count(cnt)>0)cnt++;
        s.insert(cnt);
    }
    for(int i=n;i>=1;i--){
        int minn=*s.lower_bound(dt[i].second);
        ans+=1ll*dt[i].first*(minn-dt[i].second);
        s.erase(minn);
    }
    printf("%lld\n",ans);
}