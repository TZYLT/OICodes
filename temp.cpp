#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define Re register int
using namespace std;
const int N=18,M=131072+3;
int n,m,x,y,o,V,v[N],cnt[M],head[N],A[N][N];LL ans,g[M],dp[N][N];
struct QAQ{int to,next;}a[N<<1];
inline void add(Re x,Re y){a[++o].to=y,a[o].next=head[x],head[x]=o;}
inline void in(Re &x){
    int f=0;x=0;char ch=getchar();
    while(ch<'0'||ch>'9')f|=ch=='-',ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
}
inline void dfs(Re x,Re fa,Re S){
    for(Re i=1;i<=v[0];++i)dp[x][i]=1;
    for(Re i=head[x],to;i;i=a[i].next)
        if((to=a[i].to)!=fa){
            dfs(to,x,S);
            for(Re j=1;j<=v[0];++j){
                LL tmp=0;
                for(Re k=1;k<=v[0];++k)if(A[v[j]][v[k]])tmp+=dp[to][k];
                dp[x][j]*=tmp;
            }
        }
}
int main(){
//    freopen("123.txt","r",stdin);
    in(n),in(m),V=(1<<n)-1;
    if(n==1){puts("1");return 0;}
    while(m--)in(x),in(y),A[x][y]=A[y][x]=1;
    m=n-1;
    while(m--)in(x),in(y),add(x,y),add(y,x);
    for(Re s=0;s<=V;++s){
        cnt[s]=cnt[s>>1]+(s&1),v[0]=0;
        for(Re i=1;i<=n;++i)if(s&(1<<i-1))v[++v[0]]=i;
        dfs(1,0,s);LL g=0;
        for(Re i=1;i<=v[0];++i)g+=dp[1][i];
        printf("[%d]:%lld\n",s,g);
        ans+=(n-cnt[s]&1)?-g:g;
    }
    printf("%lld\n",ans);
}
