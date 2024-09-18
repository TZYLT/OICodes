#include<bits/stdc++.h>
using namespace std;
#define M 200200
int l[4*M],r[4*M];
long long maxx[4*M];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        maxx[p]=0;
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}
void change(int p,int x,long long d){
    if(l[p]==r[p]&&l[p]==x){maxx[p]=d;return;}
    int mid=(l[p]+r[p])/2;
    if(x<=mid)change(p*2,x,d);
    if(x>mid)change(p*2+1,x,d);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}
long long ask(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return maxx[p];
    int mid=(l[p]+r[p])/2;
    long long v=-(1ll<<60);
    if(li<=mid)v=max(v,ask(p*2,li,ri));
    if(ri>mid)v=max(v,ask(p*2+1,li,ri));
    return v;
} 
int n,m;
long long h=0,last=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    build(1,1,n);
    while(n--){
        long long x;
        char c;
        cin>>c>>x;
        if(c=='A')change(1,++h,(x+last)%m);
        else cout<<(last=ask(1,h-x+1,h))<<'\n';
    }
}