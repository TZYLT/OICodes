#include<bits/stdc++.h>
using namespace std;
const int p=1000000007;
int k[301][301],d[301][301],a[301][301];
int n,m,t,x,y,w;

int GE(void){
    int ans=1,w=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;++j){
            while(k[i][i]){
                int d=k[j][i]/k[i][i];
                for(int l=i;l<=n;++l)
                    k[j][l]=(k[j][l]-1ll*d*k[i][l]%p+p)%p;
                swap(k[i],k[j]);w=-w;
            }
            swap(k[i],k[j]);w=-w;
        }
    }
    for(int i=1;i<=n;i++)ans=1ll*k[i][i]*ans%p;
    ans=1ll*w*ans;
    return (ans+p)%p;
}

int main(){
    scanf("%d%d%d",&n,&m,&t);
    if(t==0){
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&x,&y,&w);
            a[x][y]=(a[x][y]+w)%p;
            a[y][x]=(a[y][x]+w)%p;

            d[x][x]=(d[x][x]+w)%p;
            d[y][y]=(d[y][y]+w)%p;
        }
    }else if(t==1){
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&x,&y,&w);
            a[x][y]=(a[x][y]+w)%p;
            d[y][y]=(d[y][y]+w)%p;
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=(d[i][j]+p-a[i][j])%p;
    for(int i=2;i<=n;i++)
        for(int j=2;j<=n;j++)
            k[i-1][j-1]=d[i][j];

    n--;
    printf("%d",GE());

}