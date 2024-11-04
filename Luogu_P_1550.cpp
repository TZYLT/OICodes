#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>> eg;
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
DisjointSet<10010> st;
int n;
int ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        eg.push_back({x,{i,n+1}});
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
        int x;
        scanf("%d",&x);
        eg.push_back({x,{i,j}});
    }
    st.init();
    sort(eg.begin(),eg.end());
    for(auto c:eg){
        int x,y,w;
        w=c.first;
        x=c.second.first;
        y=c.second.second;

        if(st.get(x)!=st.get(y))
            st.merge(x,y),ans+=w;
    }
    printf("%d\n",ans);
}