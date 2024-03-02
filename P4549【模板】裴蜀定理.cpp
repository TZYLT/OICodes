#include<bits/stdc++.h>
using namespace std;
int n,ans,tmp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        if(tmp<0)tmp=-tmp;
        ans=__gcd(ans,tmp);
    }
    printf("%d",ans);
}