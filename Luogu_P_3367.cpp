#include<bits/stdc++.h>
using namespace std;
int sz[100100],fa[100100],h;
pair<int,int> st[200200];
int get(int x){
    if(fa[x]==x)return x;
    return get(fa[x]);
}
void merge(int x,int y){
    x=get(x);y=get(y);
    if(x==y)return;
    if(sz[x]>sz[y])swap(x,y);
    st[++h]={x,sz[y]};
    sz[y]=max(sz[x]+1,sz[y]);
    fa[x]=y;
}
void undo(void){
    if(h==0)return;
    sz[fa[st[h].first]]=st[h].second;
    fa[st[h].first]=st[h].first;
    h--;
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    while(m--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            merge(x,y);
        }else if(op==2){
            printf(get(x)==get(y)?"Y\n":"N\n");
        }else{
            undo();
        }
    }
}