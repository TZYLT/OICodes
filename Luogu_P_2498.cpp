#include<bits/stdc++.h>
using namespace std;
int fa[10010];
int get(int x){
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    if(get(x)==get(y))return;
    fa[get(x)]=get(y);
}
void init(int n){
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
double dis(double a,double b,double c,double d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
double x[10010],y[10010];
int n;
double row,line;
bool check(double r){
    init(n+4);
    for(int i=1;i<=n;i++)
        if(abs(row-x[i])<=r)merge(n+1,i);
    for(int i=1;i<=n;i++)
        if(abs(line-y[i])<=r)merge(n+2,i);
    for(int i=1;i<=n;i++)
        if(abs(x[i]-1)<=r)merge(n+3,i);
    for(int i=1;i<=n;i++)
        if(abs(y[i]-1)<=r)merge(n+4,i);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(dis(x[i],y[i],x[j],y[j])<=2.0*r)
                merge(i,j);
    if((get(n+1)==get(n+2))||(get(n+1)==get(n+3))
        ||(get(n+4)==get(n+2))||(get(n+3)==get(n+4)))
            return 0;
    return 1;
}
double sc(double l,double r){
    if(r-l<=1e-6)return l;
    double mid=(r+l)/2.0;
    if(check(mid))return sc(mid,r);
    else return sc(l,mid);
}
int main(){
    scanf("%d%lf%lf",&n,&row,&line);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",x+i,y+i);
    printf("%.2lf\n",sc(0,10000000));
}