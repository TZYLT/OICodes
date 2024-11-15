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
#define int ll
int len,n,q,sz;
int st[350][100100],k[350];
ll sum[350];
int c[100100],w[100100];
int getth(int x){
    return (x-1)/len+1;
}
int geth(int x){
    return x-(x-1)%len;
}
int gett(int x){
    return min(n,geth(x)+len-1);
}
void cgc(int x,int d){
    int id=getth(x);
    st[id][c[x]]--;
    if(st[id][c[x]]==0)k[id]--;
    st[id][d]++;c[x]=d;
    if(st[id][d]==1)k[id]++;
}
void cgw(int x,int d){
    int id=getth(x);
    sum[id]-=w[x];
    w[x]=d;
    sum[id]+=w[x];
}
vector<int> A;
bool check(int id){
    if(A.size()<k[id])return 0;
    int cnt=0;
    for(int c:A)
        if(st[id][c])
            cnt++;
    if(cnt==k[id])
        return 1;
    return 0;
}
int T;
signed main(){
    T=read();
    while(T--){
        n=read();q=read();len=sqrt(n);sz=ceil((lf)n/len);
        rep(i,1,n){
            c[i]=read();
            int id=getth(i);
            st[id][c[i]]++;
            if(st[id][c[i]]==1)k[id]++;
        }
        rep(i,1,n){
            w[i]=read();
            int id=getth(i);
            sum[id]+=w[i];
        }
        while(q--){
            int op=read();
            if(op==1){
                int p=read(),k=read();
                cgc(p,k);
            }else if(op==2){
                int p=read(),k=read();
                cgw(p,k);
            }else{
                int x=read(),k=read();
                A.clear();
                rep(i,1,k)
                    A.push_back(read());
                ll ansr=0,ansl=0;
                //right
                int flg=0;
                rep(i,x,gett(x)){
                    int ps=*lower_bound(A.begin(),A.end(),c[i]);
                    if(ps!=c[i]){
                        flg=1;
                        break;
                    }
                    ansr+=w[i];
                }
                if(!flg){
                    int id=getth(x)+1,lst=id-1;
                    rep(i,id,sz){
                        if(check(i))
                            ansr+=sum[i],lst=i;
                        else break;
                    }
                    rep(i,len*lst+1,n){
                        int ps=*lower_bound(A.begin(),A.end(),c[i]);
                        if(ps!=c[i])
                            break;
                        ansr+=w[i];
                    }
                }
                //left
                x--;
                flg=0;
                per(i,geth(x),x){
                    int ps=*lower_bound(A.begin(),A.end(),c[i]);
                    if(ps!=c[i]){
                        flg=1;
                        break;
                    }
                    ansl+=w[i];
                }
                if(!flg){
                    int id=getth(x)-1,lst=id+1;
                    per(i,1,id){
                        if(check(i))
                            ansl+=sum[i],lst=i;
                        else break;
                    }
                    per(i,1,len*(lst-1)){
                        int ps=*lower_bound(A.begin(),A.end(),c[i]);
                        if(ps!=c[i])
                            break;
                        ansl+=w[i];
                    }
                }
                if(ansr!=0)prts(ansl+ansr,'\n');
                else prts(0,'\n');
            }
            
        }

        //init
        rep(i,0,sz+5){
            rep(j,0,n)
                st[i][j]=0;
            sum[i]=0;
            k[i]=0;
        }
        rep(j,0,n)c[j]=w[j]=0;
        //ms(sum,0);ms(k,0);ms(st,0);ms(c,0);ms(w,0);    
    }
}