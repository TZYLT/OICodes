#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    double dis;
    friend bool operator<(node x,node y){
        return x.dis<y.dis;
    }
};
node edge[1001000];
pair<int,int> dt[1010];

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
DisjointSet<1010> st;

int cnt,n,k;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&dt[i].first,&dt[i].second);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)edge[++cnt]={i,j,sqrt((double)(dt[i].first-dt[j].first)*(dt[i].first-dt[j].first)+
                                (double)(dt[i].second-dt[j].second)*(dt[i].second-dt[j].second))};
    st.init();
    sort(edge+1,edge+1+cnt);
    k=n-k+2;
    for(int i=1;i<=cnt;i++){
        if(st.get(edge[i].x)!=st.get(edge[i].y)){
            st.merge(edge[i].x,edge[i].y);
            k--;
        }
        if(k==1){
            printf("%.2lf\n",edge[i].dis);
            return 0;
        }
    }
}