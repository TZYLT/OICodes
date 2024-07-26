#include<bits/stdc++.h>
using namespace std;
#define p 51123987
int f[160][55][55][55];
int n;
int nxt[160][3];
string s;
int main(){
    cin>>n>>s;
    nxt[n+1][0]=nxt[n+1][1]=nxt[n+1][2]=n+1;
    for(int i=n;i>=1;i--){
        nxt[i][0]=nxt[i+1][0];
        nxt[i][1]=nxt[i+1][1];
        nxt[i][2]=nxt[i+1][2];
        nxt[i][s[i-1]-'a']=i;
    }
    f[1][0][0][0]=1;
    int ans=0,k=(n+2)/3;
    for(int i=1;i<=n;i++)
        for(int a=0;a<=k;a++)
            for(int b=0;b<=k;b++)
                for(int c=0;c<=k;c++){
                    if(a+b+c==n&&abs(a-b)<=1&&abs(b-c)<=1&&abs(a-c)<=1)ans=(ans+f[i][a][b][c])%p;
                    f[nxt[i][0]][a+1][b][c]=(f[nxt[i][0]][a+1][b][c]+f[i][a][b][c])%p;
                    f[nxt[i][1]][a][b+1][c]=(f[nxt[i][1]][a][b+1][c]+f[i][a][b][c])%p;
                    f[nxt[i][2]][a][b][c+1]=(f[nxt[i][2]][a][b][c+1]+f[i][a][b][c])%p;
                }
    printf("%d\n",ans);

}