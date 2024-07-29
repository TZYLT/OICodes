#include<bits/stdc++.h>
using namespace std;
#define M 80050
long long x[M],r[M],L[M],R[M];
int t[M],T[M],v[M];
int read(){
    int x=0;char c=getchar();
    while(!('0'<=c&&c<='9'))c=getchar();
    while('0'<=c&&c<='9'){x*=10;x+=c-'0';c=getchar();}
    return x;
}
long long readll(){
    long long x=0;char c=getchar();
    while(!('0'<=c&&c<='9'))c=getchar();
    while('0'<=c&&c<='9'){x*=10;x+=c-'0';c=getchar();}
    return x;
}
int main(){
    //auto stt=clock();
    freopen("brain.in","r",stdin);
    freopen("brain.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++)
        t[i]=read(),v[i]=read();
    //scanf("%d%d",t+i,v+i);
    for(int i=1;i<=m;i++){
        //scanf("%d%lld%lld",T+i,x+i,r+i);
        T[i]=read();x[i]=readll();r[i]=readll();
        R[i]=x[i]+r[i];
        L[i]=x[i]-r[i];
    }
        
    for(int i=1;i<=n;i++){
        bool f=1;
        for(int j=1;j<=m;j++)
            if(T[j]>=t[i]){
                long long tp=1ll*(T[j]-t[i])*v[i];
                if(R[j]>=tp&&L[j]<=tp){f=0;break;}
            }
        putchar(f?'0':'1');
    }
    //cerr<<clock()-stt;
}