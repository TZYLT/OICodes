#include<bits/stdc++.h>
using namespace std;
int f[505][505][505],n,m;
int a[505];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        for(int l=1;l<=m;l++)
            for(int j=1;j<=l;j++)
                for(int k=1;k<=m;k++)
                    f[i+1][k][a[i+1]+j-k]=min(f[i+1][k],f[i][j][l]+abs(a[i+1]-k))
            
}