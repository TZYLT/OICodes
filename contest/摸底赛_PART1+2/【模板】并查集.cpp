#include<bits/stdc++.h>
using namespace std;
#define M 100100
int fa[M],n,m;
int get(int x){
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    fa[get(x)]=get(y);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=100000;i++)
        fa[i]=i;
    while(m--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            merge(x,y);
        }else{
            printf((get(x)==get(y))?"Y\n":"N\n");
        }
    }
}