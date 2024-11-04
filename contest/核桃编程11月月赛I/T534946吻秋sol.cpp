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
int n,m,q;
int sorted[25];
int a[25][2001000];
int id[25];
int t[2002000],cnt;
void merge(int x,int y){
    if(a[id[x]][n]<=a[id[y]][1])return;
    if(a[id[y]][n]<=a[id[x]][1])
        return swap(id[x],id[y]);
    
    int posx,posy;
    per(i,1,n){
        posx=i;
        if(a[id[x]][i]<=a[id[y]][1])
            break;
    }
    rep(i,1,n){
        posy=i;
        if(a[id[y]][i]>=a[id[x]][n])
            break;
    }
    vector<int> temp;
    int l=posx,r=1;
    while(l<=n||r<=posy){
        if(l>n&&r<=posy)
            t[++cnt]=a[id[y]][r++];
        else if(l<=n&&r>posy)
            t[++cnt]=a[id[x]][l++];
        else if(a[id[x]][l]<a[id[y]][r])
            t[++cnt]=a[id[x]][l++];
        else t[++cnt]=a[id[y]][r++];
    }
    per(i,1,posy)
        a[id[y]][i]=t[cnt--];
    per(i,posx,n)
        a[id[x]][i]=t[cnt--];
}
int main(){
    n=read();m=read();q=read();
    rep(i,1,m){
        rep(j,1,n)
            a[i][j]=read();
        id[i]=i;
    }
    while(q--){
        int op=read(),x=read(),y=read();
        if(op==1){
            if(sorted[id[x]]==0)
                sort(a[id[x]]+1,a[id[x]]+1+n);
            if(sorted[id[y]]==0)
                sort(a[id[y]]+1,a[id[y]]+1+n);
            sorted[id[x]]=sorted[id[y]]=1
            merge(x,y);
        }else{
            pf("%d\n",a[id[x]][y]);
        }
    }
    
}