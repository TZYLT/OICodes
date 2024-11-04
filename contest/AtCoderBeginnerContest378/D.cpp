#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmax(x,y) x=(x>(y)?x:(y))
#define ckmin(x,y) x=(x<(y)?x:(y))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define gc() getchar()
#define pc(x) putchar(x)
#define ll long long
#define ull unsigned long long
#define lf double
#define Lf long double
#define pii pair<int,int>
#define fi first
#define se second
#define pf printf
constexpr int inf=0x3f3f3f3f;
constexpr ll infll=0x3f3f3f3f3f3f3f3f;
/*------Common-Fictions------*/
ll read(){
    ll x=0,f=1;char c=gc();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+(c^48);c=getchar();}
    return x*f;
}
void print(ll x){
    if(x<0) return pc('-'),print(-x);
    if(x>9)print(x/10);
    pc(x%10+'0');
}
/*------------------------*/
int _map[15][15];
int ans;
int n,m,k;
int v[15][15];
void dfs(int x,int y,int t){
    if(t==k)return ans++,void();
    if(x<n&&!v[x+1][y]&&_map[x+1][y]){
        v[x+1][y]=1;
        dfs(x+1,y,t+1);
        v[x+1][y]=0;
    }if(y<m&&!v[x][y+1]&&_map[x][y+1]){
        v[x][y+1]=1;
        dfs(x,y+1,t+1);
        v[x][y+1]=0;
    }if(x>1&&!v[x-1][y]&&_map[x-1][y]){
        v[x-1][y]=1;
        dfs(x-1,y,t+1);
        v[x-1][y]=0;
    }if(y>1&&!v[x][y-1]&&_map[x][y-1]){
        v[x][y-1]=1;
        dfs(x,y-1,t+1);
        v[x][y-1]=0;
    }
}
int main(){
    n=read();m=read();k=read();
    rep(i,1,n)
        rep(j,1,m){
            char c=gc();
            while(c!='.'&&c!='#')c=gc();
            _map[i][j]=(c=='.');
        }
    rep(i,1,n)
        rep(j,1,m)
            if(_map[i][j]){
                v[i][j]=1;
                dfs(i,j,0);
                v[i][j]=0;
            }
    print(ans);
}