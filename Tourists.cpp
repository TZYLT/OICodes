#include<bits/stdc++.h>
using namespace std;
#define M 200100
int w[M],v[M];
int idx[M],dcc[M],dccid[M][2],cutidx;
int head[M],nextt[M],ver[M],cnt;
int head2[M],nextt2[M],ver2[M],cnt2;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
void addnew(int x,int y){
    ++cnt2;
    ver2[cnt]=y;
    nextt2[cnt]=head2[x];
    head2[x]=cnt2;
}
int dfn[M],low[M],c,id;
int st[M],h;int n,m,q;
vector<int> ans[M];
void dfs(int x,int fa){
    dfn[x]=low[x]=++id;
    st[++h]=x;
    int son=0;
    for(int i=head[x];i;i=nextt[i]){
        if(ver[i]!=fa){
            if(dfn[ver[i]]==0){
                ++son;
                dfs(ver[i],x);
                low[x]=min(low[x],low[ver[i]]);
                if(low[ver[i]]>=dfn[x]){
                    ++c;
                    while(st[h]!=ver[i]){
                        ans[c].push_back(st[h]);
                        h--;
                    }
                    ans[c].push_back(ver[i]);
                    h--;
                    ans[c].push_back(x);
                    v[x]=1;
                }
            }
            else low[x]=min(low[x],dfn[ver[i]]);
        }   
    } 
    if(son==0&&fa==0)ans[++c].push_back(x);
}
int _size[M],dep[M],hson[M],fa[M],top[M];
int dfn[M],idd;
void dfsI(int x,int ffa){
    int s=-1;
    _size[x]=1;fa[x]=ffa;
    dep[x]=dep[ffa]+1;
    for(int i=head2[x];i;i=nextt2[i])
        if(ver2[i]!=ffa){
            dfsI(ver2[i],x);
            _size[x]+=_size[ver2[i]];
            if(s<_size[ver2[i]])s=_size[ver2[i]],hson[x]=ver2[i];
        }        
}
void dfsII(int x,int tp){
    top[x]=tp;dfn[x]=++idd;
    if(!hson[x])return;
    dfsII(hson[x],tp);
    for(int i=head2[x];i;i=nextt2[i])
        if(ver2[i]!=fa[x]&&ver2[i]!=hson[x])
            dfsII(ver2[i],ver2[i]);
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
		long long sum[4*C+1];
		int data[C+1];
		
		SegmentTree()=default;
		void init(void);
		void build(int p,int li,int ri);
		void change(int p,int x,int d);
		int ask(int p,int li,int ri);
}; 
template <int C>
void SegmentTree<C>::init(void){
	for(int i=1;i<=C;i++) data[i]=0,l[i]=0,r[i]=0,sum[i]=0;
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
	sum[p]=min(sum[p*2],sum[p*2+1]);
}
template <int C>
void SegmentTree<C>::change(int p,int x,int d){
    if(l[p]==r[p]&&l[p]==x){
        sum[p]=data[p]=d;
        return;
    }
	int mid=(l[p]+r[p])/2;
	if(x<=mid)change(p*2,x,d);
	else change(p*2+1,x,d);
	sum[p]=min(sum[p*2],sum[p*2+1]);
}
template <int C>
int SegmentTree<C>::ask(int p,int li,int ri){
	if(li<=l[p]&&ri>=r[p]) return sum[p];
	int mid=(l[p]+r[p])/2;
	int v=(1<<30);
	if(li<=mid)v=min(ask(p*2,li,ri),v);
	if(ri>mid)v=min(ask(p*2+1,li,ri),v);
	return v;
} 

SegmentTree<2*M> sq,cr;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    for(int i=1;i<=c;i++){
        dccid[i][0]=cutidx+1;
        for(auto c:ans[i]){
            idx[c]=++cutidx;
            dcc[c]=i;
            addnew(c,n+i);
            addnew(n+i,c);
        }
        dccid[i][1]=cutidx;
    }
    for(int i=1;i<=n;i++)
        cr.data[idx[i]]=w[i];
    cr.build(1,1,n);
    for(int i=1;i<=n+c;i++)
        if(dfn[i]<=n)sq.data[dfn[i]]=w[dfn[i]];
        else sq.data[dfn[i]]=cr.ask(1,dccid[dfn[i]-n][0],dccid[dfn[i]-n][1]);
    while(q--){
        int x,y;
        char op;
        scanf("%d%d%d",&op,&x,&y);
        if(op=='A'){
            
        }else{
            cr.change(1,x,y);
            sq.change(1,dfn[n+dcc[x]],cr.ask(1,dccid[dfn[i]-n][0],dccid[dfn[i]-n][1]));
        }
    }    

}