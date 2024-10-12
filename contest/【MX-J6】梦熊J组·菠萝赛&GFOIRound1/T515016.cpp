#include<bits/stdc++.h>
using namespace std;
#define M 1001000
int n,m,t;
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int id(int x,int y,int st){
    return x+y*n+st*n*m;
}
long long in[M],d[M],v[M];
bool SPFA(int s,int sum){
	queue<int> q;
	memset(d,0x7f,sizeof(d));
	memset(v,0,sizeof(v));
	memset(in,0,sizeof(in));
	q.push(s);in[s]=0;d[s]=0;v[s]=1;
	while(q.size()){
		int x=q.front();q.pop();
		v[x]=0;
		for(int i=head[x];i;i=nextt[i]){
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				if(!v[y])q.push(y),v[y]=1,in[y]=in[x]+1;
				if(in[y]>=sum)return 0;
			}
		}
	}
	return 1;
}
namespace bf{
    long long v[M],d[M];
    priority_queue<pair<long long,int> > q;
    void dijkstra(int s){
        memset(bf::d,0x3f,sizeof(bf::d));
        memset(bf::v,0,sizeof(bf::v));
        bf::d[s]=0;
        bf::q.push(make_pair(0,s));
        while(bf::q.size()){
            int x=bf::q.top().second;
            bf::q.pop();
            if(bf::v[x])continue;
            bf::v[x]=1;
            for(int i=head[x];i;i=nextt[i]){
                long long y=ver[i],z=edge[i];
                if(bf::d[y]>bf::d[x]+z){
                    bf::d[y]=bf::d[x]+z;
                    bf::q.push(make_pair(-bf::d[y],y));
                }
            }
        }
    }
}
long long dis[55][M];
int tag=1;
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(i>1)add(id(i,j,1),id(i-1,j,0),0);
            if(j>1)add(id(i,j,1),id(i,j-1,0),0);
            if(i<n)add(id(i,j,1),id(i+1,j,0),0);
            if(j<m)add(id(i,j,1),id(i,j+1,0),0);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int x;
            scanf("%d",&x);
            if(x<0)tag=0;
            add(id(i,j,0),id(i,j,1),x);
        }
    if(tag==1){
        for(int i=1;i<=t;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            bf::dijkstra(id(x,y,0));
            for(int j=1;j<=n;j++)
                for(int k=1;k<=m;k++)
                    dis[i][id(j,k,1)]=bf::d[id(j,k,1)];
            
        }
    }else {
        for(int i=1;i<=t;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(SPFA(id(x,y,0),n*m*2)){
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=m;k++)
                        dis[i][id(j,k,1)]=d[id(j,k,1)];
            }else{
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=m;k++)
                        dis[i][id(j,k,1)]=0xcfcfcfcfcfcfcfcf;
            }
        }
    }
    

    long long ans=0x3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            long long r=0xcfcfcfcfcfcfcfcf;
            for(int k=1;k<=t;k++)
                r=max(r,dis[k][id(i,j,1)]);
            ans=min(ans,r);
        }
    if(ans!=0xcfcfcfcfcfcfcfcf)printf("%lld\n",ans);
    else printf("No\n");
                
}