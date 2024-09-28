#include<bits/stdc++.h>
using namespace std;
double dp[101][1<<15];
int s[16],p[16];
int n,k;
int main(){
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",p+i);
        while(1){
            scanf("%d",&x);
            if(x==0)break;
            s[i]|=(1<<(x-1));
        }
    }
    //dp[0][(1<<15)-1]=1;
    for(int i=k;i>=1;i--)
        for(int j=0;j<(1<<n);j++){
            for(int k=1;k<=n;k++)
                if((j&s[k])==s[k])
                    dp[i][j]+=max(dp[i+1][j],dp[i+1][j|(1<<(k-1))]+p[k]);
                else dp[i][j]+=dp[i+1][j];
            dp[i][j]/=n;
        }
        printf("%.6lf",dp[1][0]);
}