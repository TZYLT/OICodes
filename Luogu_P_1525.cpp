#include<bits/stdc++.h>
using namespace std;
struct qs{
    int x,y,z;
    friend bool operator<(qs x,qs y){
        return x.z>y.z;
    }
}q[100100];
int n,m;
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
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].z);
    st.init();
    sort(q+1,q+1+m);
    for(int i=1;i<=m;i++){
        if(st.get(q[i].x)==st.get(q[i].y)){
            printf("%d",q[i].z);
            return 0;
        }
        st.merge(q[i].x,q[i].y+n);
        st.merge(q[i].x+n,q[i].y);
    }
    printf("0");
}