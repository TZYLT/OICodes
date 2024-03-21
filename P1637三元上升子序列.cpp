#include<bits/stdc++.h>
using namespace std;
#define M 100100
template <int C>
struct FenwickTree{
    int c[C+1];
    FenwickTree()=default;
    long long ask(int x){
        long long ans=0;
        for(;x;x-=x&-x)ans+=c[x];
        return ans;
    }
    void add(int x,int d){
        for(;x<=C;x+=x&-x) c[x]+=d; 
    }
    void inti(void){
        for(int i=1;i<=C;i++) c[i]=0;
    }
};
FenwickTree<M> tr1,tr2;
int n;int a[M],p[M];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        p[i]=tr1.ask(a[i]-1);
        tr1.add(a[i],1);
    }
    for(int i=1;i<=n;i++){
        ans+=tr2.ask(a[i]-1);
        tr2.add(a[i],p[i]);
    }
    printf("%lld\n",ans);
}