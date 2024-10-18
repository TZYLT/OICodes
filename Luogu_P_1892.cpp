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
DisjointSet<5050> st;
int n,m;
int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    st.init();
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        char c;int x,y;
        cin>>c>>x>>y;
        if(c=='F')st.merge(x,y);
        else{
            st.merge(x+n,y);
            st.merge(y+n,x);
        }
    }
    for(int i=1;i<=n;i++)
        if(st.fa[i]==i)cnt++;
    
    printf("%d\n",cnt);
}