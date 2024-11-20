#include<bits/stdc++.h>
using namespace std;
long long a[100000],n,q,v;
int main(){
    cin>>n>>q;
    cin>>v;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);#include<bits/stdc++.h>
using namespace std;
long long a[100000],n,q,v;
int main(){
    cin>>n>>q;
    cin>>v;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    while (q--)
    {
        long long x,y;
        cin>>x>>y;
        a[x]=y;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=(a[i]>=v);
    cout<<ans<<endl;
}
    while (q--)
    {
        long long x,y;
        cin>>x>>y;
        a[x]=y;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=(a[i]>=v);
    cout<<ans<<endl;
}