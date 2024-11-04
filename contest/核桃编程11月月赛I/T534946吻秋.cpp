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
struct node{
    int lc,rc;
    int key,pri;
    int size;
}tr[20001000];
int cnt;
void newnode(int x){
    cnt++;
    tr[cnt].size=1;
    tr[cnt].lc=tr[cnt].rc=0;
    tr[cnt].key=x;
    tr[cnt].pri=rand();
}
void upd(int p){
    tr[p].size=tr[tr[p].lc].size+tr[tr[p].rc].size+1;
}
void split(int p,int x,int &L,int &R){
    pf("[%d]:%d %d\n",p,tr[p].size,tr[p].key);
    if(p==0)return L=R=0,void();
    if(tr[p].key<=x){
        L=p;
        split(tr[p].rc,x,tr[p].rc,R);
    }else{
        R=p;
        split(tr[p].lc,x,L,tr[p].lc);
    }
    upd(p);
}
void Split(int p,int &L,int &R,int k){
    pf("[%d]:%d %d\n",p,tr[p].size,tr[p].key);
    if(p==0)return L=R=0,void();
    if(tr[tr[p].lc].size+1<=k){
        L=p;
        Split(tr[p].rc,tr[p].rc,R,k-tr[tr[p].lc].size-1);
    }else if(tr[tr[p].lc].size+1==k){
        L=p;
        R=tr[p].rc;
    }else{
        R=p;
        Split(tr[p].lc,L,tr[p].lc,k);
    }
    upd(p);
}
int merge(int L,int R){
    if(L==0||R==0)return L+R;
    if(tr[L].pri>tr[R].pri){
        tr[L].rc=merge(tr[L].rc,R);
        upd(L);
        return L;
    }else{
        tr[R].lc=merge(L,tr[R].lc);
        upd(R);
        return R;
    }
}
void insert(int &p,int x){
    int L,R;
    split(p,x,L,R);
    newnode(x);
    p=merge(merge(L,cnt),R);
}
void pt(int p){
    if(p==0)return;
    pt(tr[p].lc);
    pf("%d ",tr[p].key);
    pt(tr[p].rc);
}
int kth(int p,int k){
    if(p==0)return -1;
    pf("[%d]:%d %d\n",p,tr[p].size,tr[p].key);
    if(k==tr[tr[p].lc].size+1)return tr[p].key;
    if(k<tr[tr[p].lc].size+1)return kth(tr[p].lc,k);
    if(k>tr[tr[p].lc].size+1)return kth(tr[p].rc,k-tr[tr[p].lc].size-1);
}
int n,m,q;
int rt[25];
int sorted[25];
int a[25][2001000];
int main(){
    srand(time(0));
    n=read();m=read();q=read();
    rep(i,1,m){
        rep(j,1,n)
            a[i][j]=read();
        newnode(a[i][1]);
        rt[i]=cnt;
        rep(j,2,n)
            insert(rt[i],a[i][j]);
    }
    while(q--){
        int op=read(),x=read(),y=read();
        if(op==1){
            sorted[x]=sorted[y]=1;
            pf("%d %d\n",rt[x],rt[y]);
            pt(rt[x]);pc('\n');pt(rt[y]);pc('\n');
            int t=merge(rt[x],rt[y]);
            pt(t);pc('\n');
            Split(t,rt[x],rt[y],n);
            pt(rt[x]);pc('\n');pt(rt[y]);pc('\n');
            pf("%d %d\n",rt[x],rt[y]);
        }else{
            if(sorted[x]==0)
                pf("%d\n",a[x][y]);
            else pf("%d\n",kth(rt[x],y));
        }
    }
    
}