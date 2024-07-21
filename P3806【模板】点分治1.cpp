#include<bits/stdc++.h>
using namespace std;
#define M 20200
int n,m;
int ak[M];
int ans[M];
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int del[M],sum;
int _size[M],f[M];
void dfsI(int x,int fa){
    _size[x]=1;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa&&del[ver[i]]==0)
            dfsI(ver[i],x),_size[x]+=_size[ver[i]];
}
int hh,mf;
void dfsII(int x,int fa,int s){
    f[x]=s-_size[x];
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa&&del[ver[i]]==0)
            dfsII(ver[i],x,s),f[x]=max(f[x],_size[ver[i]]);
    if(mf>=f[x])mf=f[x],hh=x;
}
int gethh(int x){
    dfsI(x,0);
    mf=(1<<30);
    dfsII(x,0,_size[x]);
    return hh;
}
const int inf=10000000;
int jd[10000100],dis[M];
vector<int> rem,dt;
void dfs(int x,int w,int fa){
    dis[x]=dis[fa]+w;
    rem.push_back(dis[x]);
    for(int i=head[x];i;i=nextt[i])
        if(del[ver[i]]!=1&&ver[i]!=fa)
            dfs(ver[i],edge[i],x);
}
void soldfs(int x,int fa){
    //printf("[%d]\n",x);
    dis[x]=0;jd[0]=1;
    for(int i=head[x];i;i=nextt[i])
        if(del[ver[i]]!=1){
            dfs(ver[i],edge[i],x);
            
            for(int j=1;j<=m;j++)
                for(auto b:rem)
                    if(ak[j]-b>=0&&ak[j]-b<=10000000)
                        if(jd[ak[j]-b])
                            ans[j]|=1;
            for(int j=0;j<rem.size();j++)
                if(rem[j]<=10000000)
                    dt.push_back(rem[j]),jd[rem[j]]|=1;
            rem.clear();
        }
    
    del[x]=1;
    for(int j=0;j<dt.size();j++)
        jd[dt[j]]=0;
    dt.clear();
    for(int i=head[x];i;i=nextt[i])
        if(del[ver[i]]!=1){
            soldfs(gethh(ver[i]),x);
        }
    

}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    for(int i=1,x;i<=m;i++){
        scanf("%d",&x);
        ak[i]=x;
    }
    
    soldfs(gethh(1),0);
    for(int i=1;i<=m;i++)
        printf(ans[i]?"AYE\n":"NAY\n");
}