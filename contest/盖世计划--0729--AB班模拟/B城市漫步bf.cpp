#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int f[2][75];
int _map[75][75],chance[75],dg[75];
int n,m,T;
int t[100100],v[100100];
int ans[100100];
vector<int> bt[2001000];
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int main(){
    freopen("citywalk.in","r",stdin);
    freopen("citywalk.out","w",stdout);
    scanf("%d%d%d",&n,&m,&T);
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=1;j<=n;j++){
            _map[i][j]=s[j-1]-'0';
            dg[i]+=_map[i][j];
        }
    }
    for(int i=1;i<=n;i++)
        chance[i]=qpow(dg[i],p-2);
    for(int i=1;i<=m;i++)
        scanf("%d%d",t+i,v+i),bt[t[i]].push_back(v[i]);
    int anss=0;
    for(int i=0;i<T;i++){
        for(int j=1;j<=n;j++)f[(i+1)&1][j]=0;
        for(int c:bt[i+1])f[(i+1)&1][c]++;
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(_map[j][k]){
                    f[(i+1)&1][k]=(f[(i+1)&1][k]+1ll*f[i&1][j]*chance[j]%p)%p;
                }
        anss^=f[(i+1)&1][n];
    }
    printf("%d\n",anss);
        
}