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
int ans;
int n,m;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d",&n,&m);
    st.init();
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(st.get(x)!=st.get(y))
            ans++,st.merge(x,y);
    }
    printf("%d\n",ans);
}