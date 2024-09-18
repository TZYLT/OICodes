#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int dp[3<<23];
int n,m,a[101],b[3];
int sum[3<<23],at[3<<23];
inline lowbit(int x){return x&(-x);}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   
        scanf("%d",a+i),at[1<<(i-1)]=a[i];
    scanf("%d",&m);
    b[1]=b[2]=0x7f7f7f7f;
    for(int i=1;i<=m;i++)
        scanf("%d",b+i);
    dp[0]=1;
    for(int s=1;s<(1<<n);s++)
        sum[s]=sum[s-lowbit(s)]+at[lowbit(s)];
    
    for(int s=1;s<(1<<n);s++){
        if(sum[s]!=b[1]&&sum[s]!=b[2]){
            int i=s;
            while(i){
                dp[s]=(dp[s]+dp[s^lowbit(i)])%p;
                i-=lowbit(i);
            }
        }
    }
    printf("%d\n",dp[(1<<n)-1]);
}