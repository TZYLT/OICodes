#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmax(x,y) x=(x>(y)?x:(y))
#define ckmin(x,y) x=(x<(y)?x:(y))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define ull unsigned long long
#define ld double
#define Ld long double
#define pii pair<int,int>
#define fi first
#define se second
constexpr int inf=0x3f3f3f3f
constexpr ll infll=0x3f3f3f3f3f3f3f3f

template<class T>
inline T read(){
    T x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=getchar();
    }while(isdigit(c)){
        x=x*10+(c^48);
        c=getchar();
    }return x*f;
}
template<class T>
inline void print(T x){
    if(x<0){
        putchar('-');
        return print(-x);
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
