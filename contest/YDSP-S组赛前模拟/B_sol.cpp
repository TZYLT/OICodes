#include<bits/stdc++.h>
using namespace std;
#define M 100100
#define p 998244353
int f[M],g[M],sumg[M];
int n;
int main(){
    scanf("%d",&n);
    f[1]=1;g[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=2;j<i;j++)
            if(i%j==0){
                (g[i]+=f[j])%=p;
                (g[i]+=(sumg[i-1]-sumg[j]+p))%=p;
            }
        g[i]+=1;
        sumg[i]=(sumg[i-1]+g[i])%p;
        f[i]=(f[i-1]+g[i])%p;
    }
    printf("%d\n",f[n]);
}