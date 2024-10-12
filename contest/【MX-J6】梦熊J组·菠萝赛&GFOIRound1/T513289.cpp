#include<bits/stdc++.h>
using namespace std;
int t,n,d,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&d);
        if(!(d&1))printf("%lld\n",1ll*n*(n+1)/2);
        else{
            int x=n>>1,y=(n+1)>>1;
            printf("%lld\n",1ll*x*(x+1)/2+1ll*y*(y+1)/2);
        }
    }
}