#include<bits/stdc++.h>
using namespace std;
unsigned int f[32][32][32];
unsigned int n,w[32];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    for(int i=1;i<=n;i++)   
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                f[i][j][k]=1;
    for(int i=1;i<=n;i++)
        f[i][i][i]=w[i];
    
        for(int l=1;l<=n;l++)   
            for(int x=l;x+l-1<=n;x++)
                for(int i=1;i<=n;i++)
                for(int u=l;u<=i-1;u++)
                    for(int v=i+1;v<=r;v++)
                        f[i][l][r]=max(f[i][l][r],f[u][l][i-1]*f[v][i+1][r]+w[i]);
    unsigned int ans=0;
    for(int i=1;i<=n;i++)        
        ans=max(ans,f[i][1][n]);
    printf("%u",ans);
}