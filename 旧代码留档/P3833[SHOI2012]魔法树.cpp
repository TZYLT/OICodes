#include<bits/stdc++.h>
using namespace std;
#define M 200200
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int id,maxdfn[M],dfn[M],_size[M],dep[M],hson[M],fa[M],top[M];
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
    top[x]=tp;dfn[x]=++id;
    if(!hson[x])return;
    dfsII(hson[x],tp);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa[x]&&ver[i]!=hson[x])
            dfsII(ver[i],ver[i]);
}
void dfs(int x,int f){
    maxdfn[x]=dfn[x];
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=f){
            dfs(ver[i],x);
            maxdfn[x]=max(maxdfn[x],maxdfn[ver[i]]);
        }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}

template <int C>
class SegmentTree{
	public:
		int l[4*C+1],r[4*C+1];
		long long sum[4*C+1],add[4*C+1];
		int data[C+1];
		
		SegmentTree()=default;
		void init(void);
		void build(int p,int li,int ri);
		void spread(int p);
		void change(int p,int li,int ri,int d);
		long long ask(int p,int li,int ri);
}; 
 
 
template <int C>
void SegmentTree<C>::init(void){
	for(int i=1;i<=C;i++) data[i]=0,l[i]=0,r[i]=0,sum[i]=0,add[i]=0;
	//build(1,1,n);
}

template <int C>
void SegmentTree<C>::build(int p,int li,int ri){
	l[p]=li;r[p]=ri;
	if(li==ri){
		sum[p]=data[li];
		return;
	}
	int mid=(li+ri)/2;
	build(p*2,li,mid);
	build(p*2+1,mid+1,ri);
	sum[p]=sum[p*2]+sum[p*2+1];
}

template <int C>
void SegmentTree<C>::spread(int p){
	if(add[p]){
		sum[p*2]+=add[p]*(r[p*2]-l[p*2]+1);
		sum[p*2+1]+=add[p]*(r[p*2+1]-l[p*2+1]+1);
		add[p*2]+=add[p];
		add[p*2+1]+=add[p];
		add[p]=0;
	}
}

template <int C>
void SegmentTree<C>::change(int p,int li,int ri,int d){
	if(li<=l[p]&&ri>=r[p]){
		sum[p]+=(long long)d*(r[p]-l[p]+1);
		add[p]+=d;
		return; 
	}
	spread(p);
	int mid=(l[p]+r[p])/2;
	if(li<=mid)change(p*2,li,ri,d);
	if(ri>mid)change(p*2+1,li,ri,d);
	sum[p]=sum[p*2]+sum[p*2+1];
}

template <int C>
long long SegmentTree<C>::ask(int p,int li,int ri){
	if(li<=l[p]&&ri>=r[p]) return sum[p];
	spread(p);
	int mid=(l[p]+r[p])/2;
	long long v=0;
	if(li<=mid)v+=ask(p*2,li,ri);
	if(ri>mid)v+=ask(p*2+1,li,ri);
	return v;
	
} 
int n,m;
SegmentTree<150100> tr;
void change(int x,int d){
    int t=x;
    while(x){
       // printf("[%d]:%d,%d\n",t,dfn[x],dfn[top[x]]);
        tr.change(1,dfn[top[x]],dfn[x],d);
        x=fa[top[x]];
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x+1,y+1);
        add(y+1,x+1);
    }
    tr.init();
    tr.build(1,1,n);
    dfsI(1,0);
    dfsII(1,1);
    dfs(1,0);
    scanf("%d",&m);
    while(m--){
        char c;
        cin>>c;
        if(c=='A'){
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            x++;y++;
            change(x,d);
            change(y,d);
            change(lca(x,y),-d);
            change(fa[lca(x,y)],-d);
        }else {
            int x;
            scanf("%d",&x);x++;
            printf("%lld\n",tr.ask(1,dfn[x],maxdfn[x]));
        }
    }
}