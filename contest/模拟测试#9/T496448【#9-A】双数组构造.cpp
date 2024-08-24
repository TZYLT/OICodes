#include<bits/stdc++.h>
using namespace std;
int f[101][100100];
int a[100100],b[100100];
int n,m,p;
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int j=1;j<=m;j++)
        f[1][j]=1;
    for(int j=1;j<=m;j++)
        for(int i=1;i<n;i++){
            f[i][j+1]=(f[i][j+1]+f[i][j])%p;
            f[i+1][j]=(f[i+1][j]+f[i][j])%p;
        }
    for(int j=1;j<=m;j++)
        b[j]=f[n][m-j+1];
    for(int j=1;j<=m;j++)
        a[j]=(a[j-1]+f[n][j])%p;
    int ans=0;
    for(int j=1;j<=m;j++)
        ans=(ans+1ll*b[j]*a[j]%p)%p;
    printf("%d\n",ans);
}