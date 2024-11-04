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
#define M 400400
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n;
int deg[M];
int v[M];
int bfs(int x){
    queue<int> q;
    q.push(x);v[x]=1;
    int ans=0;
    while(q.size()){
        x=q.front();q.pop();
        for(int i=head[x];i;i=nextt[i]){
            if(deg[ver[i]]==3&&!v[ver[i]]){
                q.push(ver[i]);
                v[ver[i]]=1;
            }else if(deg[ver[i]]==2){
                ans++;
            }
        }
    }
    return ans;
}
ll ans=0;
int main(){
    n=read();
    rep(i,1,n-1){
        int x=read(),y=read();
        add(x,y);add(y,x);
        deg[x]++;deg[y]++;
    }
    rep(i,1,n)
        if(!v[i]&&deg[i]==3){
            int t=bfs(i);
            ans+=1ll*t*(t-1)/2;
        }

    print(ans);
}