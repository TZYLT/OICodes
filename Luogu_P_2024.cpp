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
DisjointSet<200100> st;
int n,m,ans;
int id(int x,int st){
    return x+st*n;
}

int main(){
    scanf("%d%d",&n,&m);
    st.init();
    for(int i=1;i<=m;i++){
        int x,y,op;
        scanf("%d%d%d",&op,&x,&y);
        //if(y==x)continue;
        if(y>n||x>n)continue;
        if(op==1){
            if(st.get(id(x,0))==st.get(id(y,1))||st.get(id(x,1))==st.get(id(y,0)))continue;
            st.merge(id(x,0),id(y,0));
            st.merge(id(x,1),id(y,1));
            st.merge(id(x,2),id(y,2));
            ans++;
        }else{
            if(st.get(id(x,0))==st.get(id(y,0))||st.get(id(x,0))==st.get(id(y,1)))continue;
            st.merge(id(x,1),id(y,0));
            st.merge(id(x,2),id(y,1));
            st.merge(id(x,0),id(y,2));
            ans++;
        }
        
    }
    printf("%d",m-ans);
}
