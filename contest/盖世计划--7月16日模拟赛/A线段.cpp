#include<bits/stdc++.h>
using namespace std;
#define M 505
#define p 1000000007
int f[M][M][M],n,k;
int main(){
    freopen("seg.in","r",stdin);
    freopen("seg.out","w",stdout);
    scanf("%d%d",&n,&k);
    f[0][0][0]=1;
    
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int l=0;l<=n;l++)
            {
                f[i+1][j+1][i+1]=(f[i+1][j+1][i+1]+1ll*f[i][j][l]*(i-l)%p)%p;
                f[i+1][j][l]=(f[i+1][j][l]+f[i][j][l])%p;
                f[i+1][j][i+1]=(f[i+1][j][i+1]+1ll*f[i][j][l]*(l+1)%p)%p;
            }
    int ans=0;
    for(int i=0;i<=n;i++)
        ans=(ans+f[n][k][i])%p;
    printf("%d\n",ans%p);
}