#include<bits/stdc++.h>
using namespace std;
#define M 200200
int head[M],nextt[M],edge[M],ver[M],d[M],now[M],cnt=1;
void add(int x,int y,int z){
    ++cnt;ver[cnt]=y;edge[cnt]=z;nextt[cnt]=head[x];head[x]=cnt;
    ++cnt;ver[cnt]=x;edge[cnt]=0;nextt[cnt]=head[y];head[y]=cnt;
}
int s,t;
bool bfs(){
    memset(d,0,sizeof d);
    queue<int> q;
    q.push(s);d[s]=1;now[s]=head[s];
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=head[x];i;i=nextt[i])
            if(edge[i]&&!d[ver[i]]){
                q.push(ver[i]);
                now[ver[i]]=head[ver[i]];
                d[ver[i]]=d[x]+1;
                if(ver[i]==t)return 1;
            }
    }
    return 0;
}
int getflow(int x,int flow){
    if(x==t)return flow;
    int rest=flow;
    for(int i=now[x];i&&rest;i=nextt[i]){
        now[x]=i;
        if(edge[i]&&d[ver[i]]==d[x]+1){
            int k=getflow(ver[i],min(rest,edge[i]));
            if(!k)d[ver[i]]=0;
            edge[i]-=k;edge[i^1]+=k;
            rest-=k;
        }
    }
    return flow-rest;
}
int dinic(){
    int flow,maxflow=0;
    while(bfs())
        while(flow=getflow(s,(1<<29)))
            maxflow+=flow;
    return maxflow;        
}
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char *p1,*p2,buf[(1<<20)+5];
inline int read(){
    int x=0,f=1;
    char c=gc();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=gc();
    }while(isdigit(c)){
        x=x*10+(c^48);
        c=gc();
    }return x*f;
}
pair<pair<int,int>,pair<int,int> > line[1010];
vector<pair<pair<int,int>,pair<int,int> > > l,r;
int n;
int id(int x,int st){
    return 3+x+st*n;
}
int main(){
    scanf("%d",&n);
    s=1;t=2*n+10;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&line[i].first.first,&line[i].first.second,&line[i].second.first,&line[i].second.second);
        if(line[i].first.second==line[i].second.second)
            l.push_back(line[i]),add(s,id(l.size(),0),1);
        if(line[i].first.first==line[i].second.first)
            r.push_back(line[i]),add(id(r.size(),1),t,1);
        
    }
    for(int i=0;i<l.size();i++)
        for(int j=0;j<r.size();j++)
            if(r[j].first.first<=max(l[i].first.first,l[i].second.first)
                    &&r[j].first.first>=min(l[i].first.first,l[i].second.first)
                    &&l[i].first.second<=max(r[j].first.second,r[j].second.second)
                    &&l[i].first.second>=min(r[j].first.second,r[j].second.second))
                add(id(i+1,0),id(j+1,1),1);
            
            
    printf("%d\n",n-dinic());
}