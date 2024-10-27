#include<bits/stdc++.h>
using namespace std;
#define M 1001000
int fa[M],n,m;
int get(int x){
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    fa[get(x)]=get(y);
}
int ans=0;
vector<pair<int,pair<int,int> > > edge;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edge.push_back({z,{x,y}});
    }
    sort(edge.begin(),edge.end());
    for(pair<int,pair<int,int> > c:edge){
        if(get(c.second.first)!=get(c.second.second)){
            merge(c.second.first,c.second.second);
            ans+=c.first;
        }
    }
    for(int i=1;i<n;i++)
        if(get(i)!=get(i+1)){
            printf("orz");
            return 0;
        }
    printf("%d\n",ans);
    
}