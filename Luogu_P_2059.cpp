#include<bits/stdc++.h>
using namespace std;
long double dp[55][55];
int n,m;
int a[55];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[1][1]=1.0;
    for(int i=2;i<=n;i++)
        for(int t=1;t<=m;t++){
            int p=a[t]%i;
            if(p==0)p=i;
            for(int j=1;j<i;j++){
                p++;
                if(p>i)p=1;
                dp[i][p]+=dp[i-1][j]/(long double)(m);
            }
        }
    for(int i=1;i<=n;i++)
        printf("%.2Lf%% ",dp[n][i]*100.0);
}