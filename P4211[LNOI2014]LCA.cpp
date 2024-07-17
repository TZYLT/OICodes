#include<bits/stdc++.h>
using namespace std;
#define M 200100
struct qs{
    int l,z,t,id;
    friend bool operator<(qs x,qs y){return x.l<y.l;}
};
int n,m;
vector<qs> q[M];
int ans[M];

int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int _size[M],dep[M],hson[M],fa[M],top[M],dfn[M],tot;
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
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}


int l[4*M+1],r[4*M+1];
long long sum[4*M+1],_add[4*M+1];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        sum[p]=0;
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    sum[p]=sum[p*2]+sum[p*2+1];
}
void spread(int p){
    if(_add[p]){
        sum[p*2]+=_add[p]*(r[p*2]-l[p*2]+1);
        sum[p*2+1]+=_add[p]*(r[p*2+1]-l[p*2+1]+1);
        _add[p*2]+=_add[p];
        _add[p*2+1]+=_add[p];
        _add[p]=0;
    }
}
void change(int p,int li,int ri,int d){
    if(li<=l[p]&&ri>=r[p]){
        sum[p]+=(long long)d*(r[p]-l[p]+1);
        _add[p]+=d;
        return; 
    }
    spread(p);
    int mid=(l[p]+r[p])/2;
    if(li<=mid)change(p*2,li,ri,d);
    if(ri>mid)change(p*2+1,li,ri,d);
    sum[p]=sum[p*2]+sum[p*2+1];
}
long long ask(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return sum[p];
    spread(p);
    int mid=(l[p]+r[p])/2;
    long long v=0;
    if(li<=mid)v+=ask(p*2,li,ri);
    if(ri>mid)v+=ask(p*2+1,li,ri);
    return v;
} 
int ask(int x){
    int ans=0;
    //printf("[%d]\n",x);
    while(x){
		ans+=ask(1,dfn[top[x]],dfn[x]);
		//printf("[%d:%d]:%d\n",top[x],x,ans);
        x=fa[top[x]];
	}
	
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        x++;
        add(i,x);
        add(x,i);
    }
    dfsI(1,0);
    dfsII(1,1);
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        x++;y++;z++;
        q[y].push_back({y,z,1,i});
        q[x-1].push_back({x-1,z,-1,i});
    }
    build(1,1,n);
    for(int i=0;i<=n;i++){
    	int x=i;
		while(x){
			change(1,dfn[top[x]],dfn[x],1);
			//printf("[%d:%d]\n",top[x],x);
            x=fa[top[x]];
		}
		
        for(int j=0;j<q[i].size();j++)
            ans[q[i][j].id]+=q[i][j].t*ask(q[i][j].z);
	}
    
    for(int i=1;i<=m;i++)
    	printf("%d\n",ans[i]%201314);
}
