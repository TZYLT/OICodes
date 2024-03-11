#include<bits/stdc++.h>
using namespace std;
long long k,a,q;
int main(){
    cin>>k>>a>>q;
    long long ans=a,t=1;
    for(int i=1;i<=k;i++)
        t=(t*ans)%722733748,ans=(ans*q)%722733748;
    
    printf("%d\n",t);
}