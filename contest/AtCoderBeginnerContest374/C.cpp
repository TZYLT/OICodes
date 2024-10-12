#include<bits/stdc++.h>
using namespace std;
int n,k[22];
long long sum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>k[i];
    for(int i=1;i<=n;i++)
        sum+=k[i];
    long long ans=0x7f7f7f7f7f7f7f7f;
    for(int i=0;i<(1<<n);i++){
        long long t=0;
        for(int j=1;j<=n;j++)
            if((i>>(j-1))&1)
                t+=k[j];
        ans=min(ans,max(t,sum-t));
    }
    cout<<ans<<endl;
}