#include<bits/stdc++.h>
using namespace std;
#define M 200100
struct node{
    int x,y,z;
    friend bool operator<(node x,node y){return x.z>y.z;}
};
vector<node> edge;

int v[M];
int n,k;

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
long long ans;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1,x;i<=k;i++)
        scanf("%d",&x),v[x+1]=1;
    for(int i=1;i<n;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++;y++;
        edge.push_back({x,y,z});
        ans+=z;
    }
    sort(edge.begin(),edge.end());
    st.init();
    for(int i=0;i<n-1;i++){
        if(v[st.get(edge[i].x)]==1&&v[st.get(edge[i].y)]==1)continue;
        
        ans-=edge[i].z;
        int t=v[st.get(edge[i].x)]|v[st.get(edge[i].y)];
        v[st.get(edge[i].x)]|=t;v[st.get(edge[i].y)]|=t;
        st.merge(edge[i].x,edge[i].y);
    }
    printf("%lld\n",ans);
}