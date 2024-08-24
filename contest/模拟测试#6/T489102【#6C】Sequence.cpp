#include<bits/stdc++.h>
using namespace std;
#define M 400400
template <int C>
struct FenwickTree{
    long long c[C+1];
    FenwickTree()=default;
    long long ask(int x){
        long long ans=0;
        for(;x;x-=x&-x)ans+=c[x];
        return ans;
    }
    void add(int x,long long d){
        for(;x<=C;x+=x&-x) c[x]+=d; 
    }
};
FenwickTree<M> tr,bt;
int a[M];
int n,q;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        bt.add(a[i],1);
    for(int i=1;i<=400000;i++)
        tr.add(i,1ll*i*(bt.ask(i)-bt.ask(i-1)));
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y;
            scanf("%d%d",&x,&y);
            bt.add(a[x],-1);
            tr.add(a[x],-a[x]);
            bt.add(y,1);
            tr.add(y,y);
            a[x]=y;
        }else{
            int x;long long ans=0;
            scanf("%d",&x);
            for(int l=1,r;l<=x;l=r+1){
                r=x/(x/l);
                int t=x/l;
                ans+=1ll*(x+t)*(bt.ask(r)-bt.ask(l-1))-1ll*t*(tr.ask(r)-tr.ask(l-1));
            }
            ans+=x*(bt.ask(400000)-bt.ask(x));
            printf("%lld\n",ans);
        }
    }
}