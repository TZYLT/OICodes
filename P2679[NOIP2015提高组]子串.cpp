// #include<bits/stdc++.h>
// using namespace std;
// int f[1010][210][210],g[1010][210][210];
// int n,m,K;
// #define p 1000000007
// string a,b;
// int main(){
//     scanf("%d%d%d",&n,&m,&K);
//     cin>>a;
//     cin>>b;
//     a=' '+a;
//     b=' '+b;
//     f[0][0][0]=1;
//     for(int k=0;k<=K;k++)
//         for(int i=1;i<=n;i++)
//             for(int j=1;j<=m;j++){
//                 if(k>=1)g[i][j][k]=((a[i]==b[j])?(g[i-1][j-1][k]+f[i-1][j-1][k-1])%p:0);
//                 f[i][j][k]=(f[i-1][j][k]+g[i][j][k])%p;
//             }
//     printf("%d\n",f[n][m][K]);
// }

#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
long long f[201][201]={1},g[201][201],n,m,K;
char a[1001],b[201];
int main(){
    scanf("%d%d%d",&n,&m,&K);
    cin>>a;
    cin>>b;

    for(int i=1;i<=n;i++)
      for(int j=m;j>=1;j--)
        for(int k=K;k>=1;k--){
            g[j][k]=(a[i-1]==b[j-1])?(g[j-1][k]+f[j-1][k-1])%p:0;
            f[j][k]=(f[j][k]+g[j][k])%p;
        }
              
    printf("%d\n",f[m][K]);
}