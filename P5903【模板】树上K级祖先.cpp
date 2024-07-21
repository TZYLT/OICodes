#include<bits/stdc++.h>

using namespace std;
#define M 1001000
unsigned int n,q,ans;long long output;
int rt;
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
unsigned int s;
inline unsigned int get(unsigned int x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}
int _size[M],dfn[M],id[M],dep[M],hson[M],fa[M],top[M],tot;
void dfsI(int x,int ffa){
    int s=-1;
    _size[x]=1;fa[x]=ffa;
    dep[x]=dep[ffa]+1;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=ffa){
            dfsI(ver[i],x);
            _size[x]+=_size[ver[i]];
            if(s<_size[ver[i]])s=_size[ver[i]],hson[x]=ver[i];
        }
}
void dfsII(int x,int tp){
    top[x]=tp;dfn[x]=++tot;
    if(!hson[x])return;
    dfsII(hson[x],tp);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa[x]&&ver[i]!=hson[x])
            dfsII(ver[i],ver[i]);
}
int main(){
    scanf("%u%u%u",&n,&q,&s);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==0)rt=i;
        else add(i,x),add(x,i);
    }
    dfsI(rt,0);
    dfsII(rt,rt);
    for(unsigned int i=1;i<=n;i++)
        id[dfn[i]]=i;
    for(unsigned int i=1;i<=q;i++){
        unsigned int x=(get(s)^ans)%n+1;
        unsigned int k=(get(s)^ans)%dep[x];
        //printf("[%d:%d]",x,k);
        while(k>=dfn[x]-dfn[top[x]]+1){
            k-=(dfn[x]-dfn[top[x]]+1);
            x=fa[top[x]];
        }
        x=id[dfn[x]-k];
        //printf("[%d]",x);
        ans=x;
        output^=(1ll*i*ans);
    }
    printf("%lld",output);
}
