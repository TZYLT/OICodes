#include<bits/stdc++.h>
using namespace std;
#define C 200200
int l[4*C+1],r[4*C+1];
long long maxx[4*C+1];
int data[C+1];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        maxx[p]=data[li];
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}
void change(int p,int d,int x){
    if(l[p]==d&&r[p]==d)return maxx[p]=x,void();
    int mid=(l[p]+r[p])/2;
    if(d<=mid)change(p<<1,d,x);
    else change((p<<1)|1,d,x);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
}
int ask(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return maxx[p];
    int mid=(l[p]+r[p])/2;
    int v=0;
    if(li<=mid)v=max(v,ask(p*2,li,ri));
    if(ri>mid)v=max(v,ask(p*2+1,li,ri));
    return v;
} 
int n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    build(1,1,n);
    while(m--){
        char c;int x,y;
        cin>>c>>x>>y;
        if(c=='Q')cout<<ask(1,x,y)<<'\n';
        else{
            if(data[x]<y)change(1,x,y),data[x]=y;
            
        }
    }
}