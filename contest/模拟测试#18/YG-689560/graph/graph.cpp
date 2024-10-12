#include<bits/stdc++.h>
using namespace std;
template <int C>
struct DisjointSet{
    int fa[C];
    DisjointSet<C>& init(void){
        for(int i=0;i<C;i++)
                fa[i]=i; 
            return *this;
    }
    int get(int x){
        if(x==fa[x]) return x;
        return fa[x]=get(fa[x]);
    } 
    void merge(int x,int y){
        fa[get(x)]=get(y);
    }
};
DisjointSet<100100> st;
int n,m;
int x[500500],y[500500],v[500500];
unsigned long long z[500500];
int main(){
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    scanf("%d%d",&n,&m);
    unsigned long long ans=0xffffffffffffffff;
    for(int i=1;i<=m;i++)
        scanf("%d%d%llu",x+i,y+i,z+i);
    for(int i=63;i>=0;i--){
        st.init();
        for(int j=1;j<=m;j++)
            if(!v[j]&&((z[j]>>i)&1)==0)
                st.merge(x[j],y[j]);
        if(st.get(1)==st.get(n)){
            ans^=(1ull<<i);
            for(int j=1;j<=m;j++)
                if(((z[j]>>i)&1)==1)
                    v[j]=1;
        }
    }
    printf("%llu\n",ans);
}