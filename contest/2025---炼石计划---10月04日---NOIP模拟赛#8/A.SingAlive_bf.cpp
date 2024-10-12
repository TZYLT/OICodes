#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int l=1;l<=n;l++){
                int t=i*i+j*j+l*l-k;
                int p=sqrt(t);
                if(p*p==t&&p>=1&&p<=n)ans++;

            }
    
    printf("%lld\n",ans);
}
