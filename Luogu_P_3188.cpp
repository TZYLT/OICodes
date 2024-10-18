#include<bits/stdc++.h>
using namespace std;
long long n,m,w,a[2020],b[2020],v[2020];
long long f[32][1010];
int main(){
    while(1){
        scanf("%lld%lld",&n,&w);
        if(n==-1)return 0;
        memset(f,0,sizeof f);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld",a+i,v+i);
            b[i]=__builtin_ctzll(a[i]);
            a[i]>>=b[i];
        }
        for(int i=1;i<=n;i++)
            for(int j=1000;j>=a[i];j--)
                f[b[i]][j]=max(f[b[i]][j],f[b[i]][j-a[i]]+v[i]);
        int len=0;
        for(int s=w>>1;s;s>>=1)len++;
        for(int i=1;i<=len;i++)
            for(int j=1000;j>=0;j--)
                for(int k=0;k<=j;k++)
                    f[i][j]=max(f[i][j],f[i][j-k]+f[i-1][min(1000ll,(long long)(k<<1)|((w&(1ll<<(i-1)))!=0))]);
        printf("%lld\n",f[len][1]);
    }
}