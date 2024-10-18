#include<bits/stdc++.h>
using namespace std;
int n,m,q;
pair<int,int> qs[30030];
int ans[30030];
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
DisjointSet<10010> st[25];
int t[25];
struct eg{
    int x,y,z;
    friend bool operator<(eg x,eg y){
        return x.z>y.z;
    }
}e[50100];
void sol(int d,int l,int r,vector<int> &qq){
    
    if(!qq.size())return;
    if(l==r){
        for(int c:qq)
            ans[c]=l;
        return;
    }
    if(l-1==r)return;
    
    if(l+1==r){
        int mid=r;
        if(t[d]==0)st[d].init();
        for(int i=t[d]+1;e[i].z>=mid&&i<=m;i++)
            st[d].merge(e[i].x,e[i].y),t[d]=max(t[d],i);

        vector<int> q1,q2;
        for(int c:qq)
            if(st[d].get(qs[c].first)==st[d].get(qs[c].second))q1.push_back(c);
            else q2.push_back(c); 
        sol(d+1,r,r,q1);sol(d+1,l,l,q2);
        return;
    }
    int mid=(l+r)>>1;
    if(t[d]==0)st[d].init();
    for(int i=t[d]+1;e[i].z>=mid&&i<=m;i++)
        st[d].merge(e[i].x,e[i].y),t[d]=max(t[d],i);
    vector<int> q1,q2;
    for(int c:qq)
        if(st[d].get(qs[c].first)==st[d].get(qs[c].second))q1.push_back(c);
        else q2.push_back(c);
    sol(d+1,mid,r,q1);sol(d+1,l,mid-1,q2);
}

int main(){
    scanf("%d%d",&n,&m);
    st[0].init();
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z),st[0].merge(e[i].x,e[i].y);;
    sort(e+1,e+1+m);
    scanf("%d",&q);
    vector<int> qq;
    for(int i=1;i<=q;i++){
        scanf("%d%d",&qs[i].first,&qs[i].second);
        if(st[0].get(qs[i].first)==st[0].get(qs[i].second))
            qq.push_back(i);
        else ans[i]=-1;
    }
        
    
    sol(1,0,100000,qq);
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    
}