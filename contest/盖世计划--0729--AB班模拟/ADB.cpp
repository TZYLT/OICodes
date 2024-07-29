#include<bits/stdc++.h>
using namespace std;
#define M 121
#define p 998244353
int f[M][M][M],g[M][M][M],K[M][M][M];

void cal(int n,int m){
    memset(f,0,sizeof f);
    memset(g,0,sizeof g);
    memset(K,0,sizeof K);
    K[0][0][0]=1;
    for(int i=0;i<=n;i++){
        fprintf(stderr,"[%d]",i);fflush(stderr);
        for(int a=0;a<=m;a++)
            for(int b=0;b<=m;b++){
                for(int j=a;j<=m;j++)
                    for(int k=b;k<=m;k++){
                        K[i+1][j][k]=(K[i+1][j][k]+K[i][a][b])%p;
                    }
                for(int j=a;j<=m;j++)
                    for(int k=b;k<=m;k++){
                        int t=abs((j-a)-(k-b));
                        g[i+1][j][k]=((g[i+1][j][k]+g[i][a][b])%p+1ll*K[i][a][b]*t%p)%p;
                    }
                for(int j=a;j<=m;j++)
                    for(int k=b;k<=m;k++){
                        int t=abs((j-a)-(k-b));
                        f[i+1][j][k]=(((f[i+1][j][k]+1ll*K[i][a][b]*t%p*t%p)%p+2ll*t*g[i][a][b])%p+f[i][a][b])%p;
                    }
            }
    }
}
int main(){
    freopen("bf.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    cal(n,m);
    printf("{");
    for(int i=1;i<=n;i++){
        printf("{");
        for(int j=1;j<=m;j++){
            printf("%d",f[i][j][j]);
            if(j!=m)printf(",");
            fflush(stdout);
            
            fprintf(stderr,"[%d,%d]",i,j);
            fflush(stderr);
        }
        printf("}");
        if(i!=n)printf(",\n");
    }
    printf("};");
                
}   