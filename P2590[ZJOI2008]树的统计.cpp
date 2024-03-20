#include<bits/stdc++.h>
using namespace std;
#define M 100100
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int m,n;
int _size[M],dep[M],hson[M],fa[M],top[M];
int dfn[M],id;
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
    top[x]=tp;
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
template <int C>
class SegmentTree{
	public:
		int l[4*C+1],r[4*C+1];
		long long sum[4*C+1],maxx[4*C+1];
		int data[C+1];
        void init(void){
            for(int i=1;i<=C;i++) maxx[i]=-1000000,data[i]=0,l[i]=0,r[i]=0,sum[i]=0,add[i]=0;
            //build(1,1,n);
        }
        void build(int p,int li,int ri){
            l[p]=li;r[p]=ri;
            if(li==ri){
                maxx[p]=sum[p]=data[li];
                return;
            }
            int mid=(li+ri)/2;
            build(p*2,li,mid);
            build(p*2+1,mid+1,ri);
            sum[p]=sum[p*2]+sum[p*2+1];
            maxx[p]=max(maxx[p*2],maxx[p*2+1]);
        }
        void change(int p,int x,int d){
            if(l[p]==r[p]&&l[p]==x){
                sum[p]=d;
                maxx[p]=d;
                return; 
            }
            int mid=(l[p]+r[p])/2;
            if(x<=mid)change(p*2,x,d);
            if(x>mid)change(p*2+1,x,d);
            sum[p]=sum[p*2]+sum[p*2+1];
            maxx[p]=max(maxx[p*2],maxx[p*2+1]);
        }
        int askadd(int p,int li,int ri){
            if(li<=l[p]&&ri>=r[p]) return sum[p];
            int mid=(l[p]+r[p])/2;
            int v=0;
            if(li<=mid)v+=askadd(p*2,li,ri);
            if(ri>mid)v+=askadd(p*2+1,li,ri);
            return v;
        } 
        int askmax(int p,int li,int ri){
            if(li<=l[p]&&ri>=r[p]) return maxx[p];
            int mid=(l[p]+r[p])/2;
            int v=-10000000;
            if(li<=mid)v=max(v,askmax(p*2,li,ri));
            if(ri>mid)v=max(v,askmax(p*2+1,li,ri));
            return v;
        } 
}; 
SegmentTree<M> tr;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfsI(1,0);
    dfsII(1,1);
    for(int i=1;i<=n;i++)
        scanf("%d",&tr.data[dfn[i]]);
    tr.build(1,1,n);
    scanf("%d",&m);
    while(m--){
        string s;
        int x,y;
        cin>>s>>x>>y;
        if(s[0]=='C')
            tr.change(1,dfn[x],y);
        else if(s[1]=='M'){
            int a=-10000000;
            while(x){
                a=max(a,tr.askmax(1,dfn[top[x]],dfn[x]));
                x=fa[top[x]];
            }
            printf("%d\n",a);
        }
        else {
            int a=0;
            while(x){
                a+=tr.askadd(1,dfn[top[x]],dfn[x]);
                x=fa[top[x]];
            }
            printf("%d\n",a);
        }
    }
}