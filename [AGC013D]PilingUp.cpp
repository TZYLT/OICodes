#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int n,m;
long long f[3030][3030][2];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)  
        f[0][i][0]=1;
    f[0][0][1]=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<=n;j++){
            f[i][j][0]%=p;f[i][j][1]%=p;
            if(j-1>=0){
                if(j==1)f[i+1][j-1][1]+=f[i][j][0];
                else f[i+1][j-1][0]+=f[i][j][0];
                f[i+1][j-1][1]+=f[i][j][1];

                if(j==1)f[i+1][j][1]+=f[i][j][0];
                else f[i+1][j][0]+=f[i][j][0];
                f[i+1][j][1]+=f[i][j][1];
            }
            if(j+1<=n){
                f[i+1][j+1][0]+=f[i][j][0];
                f[i+1][j+1][1]+=f[i][j][1];

                f[i+1][j][1]+=f[i][j][1];
                f[i+1][j][0]+=f[i][j][0];
            }
        }
    long long ans=0;
    for(int i=0;i<=n;i++)
        ans=(ans+f[m][i][1])%p;
    printf("%d\n",ans);
}