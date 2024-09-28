#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=2e6+5;
int n,k,f[N][21],ans=1e9;
pair<int,int> a[N];
int main(){
    while(scanf("%d%d",&n,&k)){
        memset(f,0,sizeof f);
        memset(a,0,sizeof a);ans=1e9;
        for(int i=1;i<=k;i++){
            scanf("%d%d",&a[i].fi,&a[i].se);
            if(a[i].fi>a[i].se) a[i].se+=n;
        }
        sort(a+1,a+1+k);
        int now=1,r=0;
        for(int i=1;i<=2*n;i++){
            while(now<=k&&a[now].fi<=i){
                r=max(r,a[now].se+1);
                now++;
            }
            f[i][0]=r;
        }
        for(int j=1;j<=20;j++){
            for(int i=1;i<=2*n;i++){
                f[i][j]=f[f[i][j-1]][j-1];
            }
        }
        for(int i=1;i<=2*n;i++){
            int x=i,ret=0;
            for(int j=20;j>=0;j--){
                if(f[x][j]-i<n){
                    x=f[x][j];
                    ret+=1<<j;
                }
            }
            x=f[x][0];ret++;
            if(x-i>=n) ans=min(ans,ret);
        }
        if(ans==1e9) printf("impossible\n");
        else printf("%d\n",ans);
    }
}