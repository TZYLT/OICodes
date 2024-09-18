#include<bits/stdc++.h>
using namespace std;
int x[10],n,m,y[400];
int f[360][45][45][45];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",y+i);
    for(int i=1,t;i<=m;i++)
        scanf("%d",&t),x[t]++;
    
    f[1][x[1]][x[2]][x[3]]=y[1];

    for(int i=2;i<=n;i++)
        for(int a=x[1];a>=0;a--)
            for(int b=x[2];b>=0;b--)
                for(int c=x[3];c>=0;c--)
                    if(i>=4)f[i][a][b][c]=y[i]+max(max(f[i-1][a+1][b][c],f[i-2][a][b+1][c]),
                            max(f[i-3][a][b][c+1],f[i-4][a][b][c]));
                    else if(i==3)f[i][a][b][c]=y[i]+max(max(f[i-1][a+1][b][c],f[i-2][a][b+1][c]),f[i-3][a][b][c+1]);
                    else if(i==2)f[i][a][b][c]=y[i]+max(f[i-1][a+1][b][c],f[i-2][a][b+1][c]);
                    else if(i==1)f[i][a][b][c]=y[i]+f[i-1][a+1][b][c];
    printf("%d\n",f[n][0][0][0]);
}