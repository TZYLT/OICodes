#include<bits/stdc++.h>
using namespace std;
#define M 100100
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}

int d[M],in[M],v[M];
int t,n,m;
bool SPFA(){
    queue<int> q;
    memset(d,0x3f,sizeof d);
    memset(in,0,sizeof in);
    memset(v,0,sizeof v);
    q.push(1);v[1]=1;d[1]=0;
    while(q.size()){
        int x=q.front();q.pop();v[x]=0;
        for(int i=head[x];i;i=nextt[i]){
            int y=ver[i];
            if(d[y]>d[x]+edge[i]){
                d[y]=d[x]+edge[i];
                if(!v[y])q.push(y),in[y]=in[x]+1,v[y]=1;
                if(in[y]>=n)return 0;
            }
        }
    }
    return 1;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(head,0,sizeof head);
        memset(nextt,0,sizeof nextt);
        memset(ver,0,sizeof ver);
        memset(edge,0,sizeof edge);
        cnt=0;
        for(int i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(z<0)add(x,y,z);
            else add(x,y,z),add(y,x,z);
        }
        printf(SPFA()?"NO\n":"YES\n");
    }
}