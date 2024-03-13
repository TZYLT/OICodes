#include<bits/stdc++.h>
using namespace std;
#define M 3000500
#define l(x) x+1000000
#define r(x) x+2000000
int head[M],nextt[M],ver[M],cnt;
int w[M],used[M];

void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int low[M],dfn[M],sta[M],v[M],h=0,cc=0;
int sum[M],scnt,s[M],in[M],f[M];
void dfs(int x){
    dfn[x]=low[x]=++cc;
    sta[++h]=x;
    v[x]=1;
    for(int i=head[x];i;i=nextt[i]){
        if(dfn[ver[i]==0]){
            dfs(ver[i]);
            low[x]=min(low[x],low[ver[i]]);
        }else if(v[ver[i]])low[x]=min(low[x],dfn[ver[i]]);

    }
    if(dfn[x]==low[x]){
        ++scnt;
        while(sta[h]!=x){
            int p=sta[h--];
            v[p]=0;s[p]=scnt;
            sum[scnt]+=w[p];
        }
        v[x]=0;s[x]=scnt;
        sum[scnt]+=w[x];
        h--;
    }
}
struct eg{
    int x,y,z,id;
    bool operator< (eg d)const{return y<d.y;}
}edg[100100];
bool cmp(eg x,eg y){
    if(x.x!=y.x)return x.x<y.x;
    else return x.y<y.y;
}
bool cmp2(eg x,eg y){
    return x.y<y.y;
}
vector<eg> sorted[1001000];
queue<int> q;
vector<int> dga[M];
int n,r,c;
int main(){
    scanf("%d%d%d",&n,&r,&c);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&edg[i].x,&edg[i].y,&edg[i].z) ;

    sort(edg+1,edg+1+n,cmp);
    for(int i=1;i<=n;i++){
        edg[i].id=i;
        sorted[edg[i].x].push_back(edg[i]);
    }
        
    
    for(int i=1;i<=n;i++){
        used[i]=1;
        if(edg[i].z==1){
            add(i,l(edg[i].x));
            add(l(edg[i].x),i);
            w[i]=1;used[l(edg[i].x)]=1;
        }
        else if(edg[i].z==2){
            add(i,r(edg[i].y));
            add(r(edg[i].y),i);
            w[i]=1;used[r(edg[i].y)]=1;
        }
        else {
            vector<int> v;
            //x-1;
            eg tt=edg[i];
            tt.y--;
            w[i]=1;
            if(sorted[edg[i].x-1].size()>0){
                auto t=lower_bound(sorted[edg[i].x-1].begin()
                                    ,sorted[edg[i].x-1].end(),tt);
                if((*t).y==(edg[i].y-1)||(*t).y==(edg[i].y)||(*t).y==(edg[i].y+1))
                    v.push_back((*t).id);
                if(t!=sorted[edg[i].x-1].end())t++;
                if((*t).y==(edg[i].y-1)||(*t).y==(edg[i].y)||(*t).y==(edg[i].y+1))
                    v.push_back((*t).id);
                if(t!=sorted[edg[i].x-1].end())t++;
                if((*t).y==(edg[i].y-1)||(*t).y==(edg[i].y)||(*t).y==(edg[i].y+1))
                    v.push_back((*t).id);
            }
            if(sorted[edg[i].x].size()>0){
                auto t=lower_bound(sorted[edg[i].x].begin()
                                    ,sorted[edg[i].x].end(),tt);
                if((*t).y==(edg[i].y-1)||(*t).y==(edg[i].y)||(*t).y==(edg[i].y+1))
                    v.push_back((*t).id);
                if(t!=sorted[edg[i].x].end())t++;
                if((*t).y==(edg[i].y-1)||(*t).y==(edg[i].y)||(*t).y==(edg[i].y+1))
                    v.push_back((*t).id);
                if(t!=sorted[edg[i].x-1].end())t++;
                if((*t).y==(edg[i].y-1)||(*t).y==(edg[i].y)||(*t).y==(edg[i].y+1))
                    v.push_back((*t).id);
            }
            if(sorted[edg[i].x+1].size()>0){
                auto t=lower_bound(sorted[edg[i].x+1].begin()
                                    ,sorted[edg[i].x+1].end(),tt);
                if((*t).y==(edg[i].y-1)||(*t).y==(edg[i].y)||(*t).y==(edg[i].y+1))
                    v.push_back((*t).id);
                if(t!=sorted[edg[i].x+1].end())t++;
                if((*t).y==(edg[i].y-1)||(*t).y==(edg[i].y)||(*t).y==(edg[i].y+1))
                    v.push_back((*t).id);
                if(t!=sorted[edg[i].x+1].end())t++;
                if((*t).y==(edg[i].y-1)||(*t).y==(edg[i].y)||(*t).y==(edg[i].y+1))
                    v.push_back((*t).id);
            }
            for(auto k:v) add(i,k);
            //printf("[%d,%d(%d,%d,%d)]:",i,v.size(),sorted[edg[i].x-1].size()
            //    ,sorted[edg[i].x].size(),sorted[edg[i].x+1].size());
            //for(auto c:v) printf("%d ",c);
            //putchar('\n');
        }
    }

    for(int i=1; i<=r(c); i++)
		if(!dfn[i]&&used[i]) dfs(i);
    
    for(int i=1; i<=r(c); i++)
		if(used[i])
            for(int j=head[i];j;j=nextt[j])
                if(s[i]!=s[ver[j]])
                    dga[s[i]].push_back(s[ver[i]]),in[s[ver[i]]]++;
    for(int i=1; i<=r(c); i++)
        if(!in[i])q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto v:dga[x]){
            f[v]=max(f[v],f[x]+sum[v]);
            --in[v];
            if(!in[v])q.push(v);
        }
    }
    int ans=-1;
    for(auto k:f)
        ans=max(k,ans);
    printf("%d\n",ans);
}