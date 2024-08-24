#include<bits/stdc++.h>
using namespace std;
template <int C>
struct FenwickTree{
    long long c[C+1];
    FenwickTree()=default;
    long long ask(int x){
        long long  ans=0;
        for(;x;x-=x&-x)ans+=c[x];
        return ans;
    }
    void add(int x,int d){
        for(;x<=C;x+=x&-x) c[x]+=d; 
    }
};
FenwickTree<200> sum;
int n,m;
int a[100100],b[100100];
long long ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=m;i++)
        scanf("%d",b+i);  
    for(int i=n;i>=1;i--){
        ans+=sum.ask(a[i]-1);
        sum.add(a[i],1);
    }
    for(int i=1;i<=m;i++){
        ans+=min(sum.ask(b[i]-1),sum.ask(150)-sum.ask(b[i]));
        sum.add(b[i],1);
    } 
    printf("%lld\n",ans);
}