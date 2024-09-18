#include<bits/stdc++.h>
using namespace std;  
int f[201][7];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m&&j<=i;j++)
            f[i][j]=f[i-j][j]+f[i-1][j-1];
    printf("%d",f[n][m]);
}