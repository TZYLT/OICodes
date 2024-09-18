#include<bits/stdc++.h>
using namespace std;
#define M 400200
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}


int v[M],d[M];
priority_queue<pair<int,int> > q;
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[1]=0;
    q.push(make_pair(0,1));
    while(q.size()){
        int x=q.top().second;
        q.pop();
        if(v[x])continue;
        v[x]=1;
        for(int i=head[x];i;i=nextt[i]){
            int y=ver[i],z=edge[i];
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}

int k;
int main(){
    scanf("%d",&k);

    for(int i=0;i<k;i++){
        add(i,(i+1)%k,1);
        add(i,(i*10)%k,0);
    }
    
    dijkstra();
    printf("%d\n",d[0]+1);
}