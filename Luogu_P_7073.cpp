#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmod(x,y) x=(x>=(y)?x-y:(x))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define msz(x) memset(x,0,sizeof(x))
#define msu(x) memset(x,0x3f,sizeof(x))
#define msl(x) memset(x,0xcf,sizeof(x))
#define gc() getchar()
#define pc(x) putchar(x)
#define psb(x) push_back(x)
#define ppb() pop_back()
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
/*------Common-Factions------*/
template<class A,class B> inline void ckmax(A &x,B y){x=(x>(y)?x:(y));}
template<class A,class B> inline void ckmin(A &x,B y){x=(x<(y)?x:(y));}
ll read(){
    ll x=0,f=1;char c=gc();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+(c^48);c=getchar();}
    return x*f;
}
void prt(ll x){
    if(x<0) return pc('-'),prt(-x);
    if(x>9)prt(x/10);
    pc(x%10+'0');
}
void prts(ll x,char c){prt(x);pc(c);}
void prts(ll x){prt(x);pc(' ');}
void prts(ll x,string s){prt(x);for(auto c:s)pc(c);}
void prtl(ll x){prt(x);pc('\n');}
/*------------------------*/
#define M 1000200
int tr[M][2];
int opt[M];
int rt,tot;
int st[M],h;
int n,q;
int num[M],dfn[M];
int cg[22][M][2],fa[22][M];
void dfs(int x){
    if(opt[x]>0){}
    else if(opt[x]==-1){
        dfs(tr[x][0]);
        dfs(tr[x][1]);
        num[x]=num[tr[x][0]]&num[tr[x][1]];
        cg[0][tr[x][0]][0]=0&num[tr[x][1]];
        cg[0][tr[x][0]][1]=1&num[tr[x][1]];
        cg[0][tr[x][1]][0]=0&num[tr[x][0]];
        cg[0][tr[x][1]][1]=1&num[tr[x][0]];
        fa[0][tr[x][0]]=x;
        fa[0][tr[x][1]]=x;
    }else if(opt[x]==-2){
        dfs(tr[x][0]);
        dfs(tr[x][1]);
        num[x]=num[tr[x][0]]|num[tr[x][1]];
        cg[0][tr[x][0]][0]=0|num[tr[x][1]];
        cg[0][tr[x][0]][1]=1|num[tr[x][1]];
        cg[0][tr[x][1]][0]=0|num[tr[x][0]];
        cg[0][tr[x][1]][1]=1|num[tr[x][0]];
        fa[0][tr[x][0]]=x;
        fa[0][tr[x][1]]=x;
    }else if(opt[x]==-3){
        dfs(tr[x][0]);
        num[x]=!num[tr[x][0]];
        cg[0][tr[x][0]][0]=1;
        cg[0][tr[x][0]][1]=0;
        fa[0][tr[x][0]]=x;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        string s;cin>>s;tot++;
        if(s[0]=='x'){
            int id;
            sscanf(s.c_str(),"x%d",&id);
            opt[tot]=id;
            dfn[id]=tot;
            st[++h]=tot;
        }else if(s[0]=='&'||s[0]=='|'||s[0]=='!'){
            if(s[0]=='&')opt[tot]=-1;
            if(s[0]=='|')opt[tot]=-2;
            if(s[0]=='!')opt[tot]=-3;
            
            if(opt[tot]==-1||opt[tot]==-2){
                tr[tot][0]=st[h--];
                tr[tot][1]=st[h--];
            }else
                tr[tot][0]=st[h--]; 
            st[++h]=tot;
        }else {
            sscanf(s.c_str(),"%d",&n);
            break;
        }
    }
    rt=st[h];tot--;
    rep(i,1,n)  
        cin>>num[dfn[i]];
    dfs(rt);
    cg[0][rt][0]=0;
    cg[0][rt][1]=1;
    fa[0][rt]=rt;
    cin>>q;
    rep(i,1,20)
        rep(j,1,tot){
            cg[i][j][0]=cg[i-1][fa[i-1][j]][cg[i-1][j][0]];
            cg[i][j][1]=cg[i-1][fa[i-1][j]][cg[i-1][j][1]];
            fa[i][j]=fa[i-1][fa[i-1][j]];
        }
    while(q--){
        int x;
        cin>>x;
        cout<<cg[20][dfn[x]][!num[dfn[x]]]<<'\n';
    }
    
}