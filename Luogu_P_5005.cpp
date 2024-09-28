#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int dp[2][1<<6][1<<6];
int n,m;
// bool check(int s1,int s2,int t){
//     for(int i=0;i<m;i++){
//         if(((s2>>i)&1)&&(((~s2)>>(i-1))&1)&&((t>>(i-2))&1))return 0;
//         if(((s2>>i)&1)&&(((~s2)>>(i+1))&1)&&((t>>(i+2))&1))return 0;
//     }
//     for(int i=0;i<m;i++)
//         if(((s1>>i)&1)&&(((~s2)>>i)&1))
//             if(((t>>(i-1))&1)|((t>>(i+1))&1))
//                 return 0;
//     for(int i=0;i<m;i++)
//         if((t>>i)&1){
//             if(((~s2)>>i)&1)if((s1>>(i-1))&1)return 0; 
//             if(((~s2)>>i)&1)if((s1>>(i+1))&1)return 0;
//             if(((~t)>>(i-1))&1)if((s2>>(i-2))&1)return 0;
//             if(((~t)>>(i+1))&1)if((s2>>(i+2))&1)return 0;
//         }            
//     return 1;
// }
bool check(int s1,int s2,int t){
    if((((~s2)&s1)<<1)&t)return 0;
    if((((~s2)&s1)>>1)&t)return 0;
    if((s2&((~s2)<<1))&(t<<2))return 0;
    if((s2&((~s2)>>1))&(t>>2))return 0;
    if((((~s2)&t)<<1)&s1)return 0;
    if((((~s2)&t)>>1)&s1)return 0;
    if((t&((~t)<<1))&(s2<<2))return 0;
    if((t&((~t)>>1))&(s2>>2))return 0;
    return 1;
}
int main(){
    cin>>n>>m;
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<m);j++)
            for(int k=0;k<(1<<m);k++)
                dp[(i+1)&1][j][k]=0;
        for(int j=0;j<(1<<m);j++)
            for(int k=0;k<(1<<m);k++)
                for(int t=0;t<(1<<m);t++)
                    if(check(j,k,t))
                        dp[(i+1)&1][k][t]=(dp[(i+1)&1][k][t]+dp[i&1][j][k])%p;
    }
    int ans=0;
    for(int j=0;j<(1<<m);j++)
        for(int k=0;k<(1<<m);k++)
            ans=(ans+dp[n&1][j][k])%p;
    cout<<ans<<endl;
}