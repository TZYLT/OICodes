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
void prt(ll x){
    if(x<0) return pc('-'),prt(-x);
    if(x>9)prt(x/10);
    pc(x%10+'0');
}
void prts(ll x,char c){prt(x);pc(c);}
/*------------------------*/
#define p 1000000007
string s;
ll n,m,q;
ll pos[65][200200],det[65][200200];
ll nxt[200200];
string t;
void getnxt(void){
    int lst=-1,tp;
    if(m<n){
        string t=s+s;
        per(i,1,m)
            if(t[i]=='1'){lst=i;break;}
        if(lst!=-1)pos[0][0]=lst,det[0][0]=lst;
        else pos[0][0]=1,det[0][0]=1;
        tp=m;
        rep(i,1,n-1){
            tp++;
            if(t[tp]=='1')
                lst=tp;
            if(lst>i)pos[0][i]=lst%n,det[0][i]=lst-i;
            else pos[0][i]=(i+1)%n,det[0][i]=1;
        }
    }else{
        per(i,0,n-1)
            if(s[i]=='1'){lst=i;break;}
        int tpp=lst;
        if(lst==-1){
            rep(i,0,n-1){
                pos[0][i]=i%n;
                det[0][i]=1;
            }
            return;
        }
        lst=-1;
        rep(i,0,n-1){
            if(s[i]=='1')lst=i;
            nxt[i]=lst;
        }
        rep(i,0,n-1){
            if(nxt[(m+i)%n]==-1){
                pos[0][i]=tpp;
                det[0][i]=m-((m+i)%n+n-tpp);
            }else{
                pos[0][i]=nxt[(m+i)%n];
                det[0][i]=m-((m+i)%n-nxt[(m+i)%n]);
            }
        }
    }
}
int main(){
    n=read();m=read();q=read();
    cin>>s;
    getnxt();
    rep(i,0,n-1)
        det[0][i]%=p;
    rep(i,1,64)
        rep(j,0,n-1){
            pos[i][j]=pos[i-1][pos[i-1][j]];
            det[i][j]=(det[i-1][j]+det[i-1][pos[i-1][j]])%p;
        }
    while(q--){
        ll st,k,asd;
        asd=st=read();k=read();
        ll ans=0;
        st--;st%=n;
        per(i,0,62)
            if(k>>i&1){
                (ans+=det[i][st])%=p;
                st=pos[i][st];
            }
        prts((ans+asd)%p,'\n');
    }
}