#include<bits/stdc++.h>
using namespace std;
const int p=1000000000;
int k[301][301],d[301][301],a[301][301];
int n,m,t;

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
void add(int x,int y){
    a[x][y]=(a[x][y]+1)%p;
    //a[y][x]=(a[y][x]+1)%p;

    d[x][x]=(d[x][x]+1)%p;
    //d[y][y]=(d[y][y]+1)%p;
}
int _map[20][20],id[20][20],cnt;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c=getchar();
            while(c!='.'&&c!='*')
                c=getchar();
            if(c=='.')_map[i][j]=1,id[i][j]=++cnt;
            else _map[i][j]=0;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(_map[i][j])
            for(int k=0;k<4;k++)
                if(i+dx[k]<=n&&i+dx[k]>=1&&j+dy[k]<=m&&j+dy[k]>=1)
                    if(_map[i+dx[k]][j+dy[k]])
                        add(id[i][j],id[i+dx[k]][j+dy[k]]);
    
    n=cnt;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=(d[i][j]+p-a[i][j])%p;
    for(int i=2;i<=n;i++)
        for(int j=2;j<=n;j++)
            k[i-1][j-1]=d[i][j];

    n--;
    printf("%d",GE());

}