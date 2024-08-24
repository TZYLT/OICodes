#include<bits/stdc++.h>
using namespace std;
#define M 400400
int head[M],nextt[M],edge[M],ver[M],cnt;
long long dp[3<<19][21];
long long dis[21][21];
int id[25];
int n,m,k;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
bool v[M];
long long d[M];
priority_queue<pair<long long,int> > q;
void dijkstra(int s){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[s]=0;
    q.push(make_pair(0,s));
    while(q.size()){
        int x=q.top().second;
        q.pop();
        if(v[x])continue;
        v[x]=1;
        for(int i=head[x];i;i=nextt[i]){
            int y=ver[i];long long z=edge[i];
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}


#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char *p1,*p2,buf[(1<<20)+5];
inline int read(){
	int x=0;
	char c=gc();
	while(!isdigit(c)){
		c=gc();
	}while(isdigit(c)){
		x=x*10+(c^48);
		c=gc();
	}return x;
}
inline void print(long long x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

int main(){
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        add(x,y,z);
        add(y,x,z);
    }
    for(int i=1;i<=k;i++)
        id[i]=read();
    id[0]=1;
    id[++k]=n;
    for(int i=0;i<=k;i++){
        dijkstra(id[i]);
        for(int j=1;j<=k;j++)
            dis[i][j]=d[id[j]];
    }
    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    for(int i=0;i<(1<<k);i++)
        for(int j=0;j<=k;j++)
            for(int r=1;r<=k;r++)
                if(((i>>(r-1))&1)==0)
                    dp[i|(1<<(r-1))][r]=min(dp[i|(1<<(r-1))][r],dp[i][j]+dis[j][r]);
    print(dp[(1<<k)-1][k]);
}