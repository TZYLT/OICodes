#include<bits/stdc++.h>
using namespace std;
#define M 18
#define p 1000000007
long long n,a[M][M],b[M][M],d[M][M][M];
long long g[(1<<M)];
int GE(void){
    int ans=1,w=1;
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n-1;++j){
            while(a[i][i]){
                int d=a[j][i]/a[i][i];
                for(int k=i;k<=n-1;++k)
                    a[j][k]=(a[j][k]-1ll*d*a[i][k]%p+p)%p;
                swap(a[i],a[j]);w=-w;
            }
            swap(a[i],a[j]);w=-w;
        }
    }
    for(int i=1;i<=n-1;i++)ans=1ll*a[i][i]*ans%p;
    ans=1ll*w*ans;
    return (ans+p)%p;
}

int main(){
    scanf("%d",&n);
    for(int i=1,m;i<n;i++){
        scanf("%d",&m);
        for(int j=1;j<=m;j++){
            int x,y;
            scanf("%d%d",&x,&y);
            d[i][x][y]=1;
            d[i][y][x]=1;
        }
    }
    for(int s=1;s<(1<<(n-1));s++){
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                b[i][j]=a[i][j]=0;
        for(int t=0;t<n-1;t++)
            if((s>>t)&1)
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                        a[i][j]+=d[t+1][i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                b[i][i]+=a[i][j];    

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=b[i][j]-a[i][j];
        
        for(int i=2;i<=n;i++)
            for(int j=2;j<=n;j++)
                a[i-1][j-1]=a[i][j];
        for(int i=1;i<=n;i++)
            a[i][n]=a[n][i]=0;
        g[s]=GE();
    }
    int ans=0;
    for(int s=0;s<(1<<(n-1));s++){
        
        int t=0,tt=s;
        while(tt)t+=tt&1,tt>>=1;
        ans=((ans+g[s]*(((n-t-1)&1)?-1:1))%p+p)%p;
        //printf("[%d]:%d ans:%d\n",s,g[s],ans);
    }
    cout<<ans<<endl;
}