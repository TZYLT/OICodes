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
int a,b,pp;
DisjointSet<100100> st;
int v[100100],p[100100],k;
void linearSieve(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
set<int> s;
int main(){
    st.init();
    scanf("%d%d%d",&a,&b,&pp);
    linearSieve(b);
    for(int i=1;i<=k;i++)
        if(p[i]>=pp){
            int f=0;
            for(int j=(a/p[i])*p[i];j<=b;j+=p[i])
            if(j>=a){
                if(f==0)f=j;
                else st.merge(f,j);
            }
        }
    for(int i=a;i<=b;i++){
        int f=st.get(i);
        if(s.count(f)==0)s.insert(f);
    }
    printf("%d",s.size());
}