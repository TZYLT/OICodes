#include<bits/stdc++.h>
using namespace std;
int n,m;
double x[10010],y[10100];
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
double dis(double a,double b,double c,double d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
bool check(double d){
    st.init();
    for(int i=1;i<=n;i++)
        if(x[i]<=d)st.merge(i,n+1);
    for(int i=1;i<=n;i++)
        if(abs(x[i]-m)<=d)st.merge(i,n+2);
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(dis(x[i],y[i],x[j],y[j])<=2.0*d)st.merge(i,j);
    if(st.get(n+1)==st.get(n+2))return 1;
    return 0;
}
double sc(double l,double r){
    if(r-l<=1e-4)return l;
    double mid=(l+r)/2.0;
    if(check(mid))return sc(l,mid);
    else return sc(mid,r);
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",x+i,y+i);
    printf("%.2lf",sc(0,m));
}