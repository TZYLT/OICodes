#include<bits/stdc++.h>
using namespace std;
int n,m,a[2020];
int f[2010][1010];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
            f[i][j]=(f[i-1][j]+f[i-1][((j-a[i])%m+m)%m])%100000000;
    printf("%d\n",f[n][0]-1);
}