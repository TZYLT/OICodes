#include<bits/stdc++.h>
using namespace std;
#define C 200200

int l[4*C+1],r[4*C+1];
long long sum[4*C+1];
int data[C+1];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        sum[p]=data[li];
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    sum[p]=max(sum[p*2],sum[p*2+1]);
}
int ask(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return sum[p];
    int mid=(l[p]+r[p])/2;
    int v=0;
    if(li<=mid)v=max(v,ask(p*2,li,ri));
    if(ri>mid)v=max(v,ask(p*2+1,li,ri));
    return v;
} 
map<int,int> st;
int n,m;
vector<pair<int,int> > qs,dt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        pair<int,int> q;
        scanf("%d%d",&q.first,&q.second);
        dt.push_back(q);
        st[q.first]=1;
    }
    scanf("%d",&m);
    for(int i=1;i<=n;i++){
        pair<int,int> q;
        scanf("%d%d",&q.first,&q.second);
        qs.push_back(q);
        st[q.first]=1;
    }
    int l=0;
    for(auto c:st)
        st[c]=++l;
    for(int i=1;i<=n;i++)
        data[st[qs[i].first]]=qs[i].second;
    build(1,1,n);
    while(m--){
        scanf("%d")
    }
}