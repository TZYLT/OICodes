#include<bits/stdc++.h>
using namespace std;
#define M 600600
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int t,n,m,k;
int v[M],d[M];
priority_queue<pair<int,int> > q;
bool dijkstra(){
    d[1]=0;
    q.push(make_pair(0,1));
    while(q.size()){
        int x=q.top().second;
        q.pop();
        if(v[x])continue;
        v[x]=1;
        for(int i=head[x];i;i=nextt[i]){
            int p=d[ver[i]]-d[x];
            if(p<1||p>k)edge[i]=1;
            else if(1<=p&&p<k)edge[i]=p+1;
            else if(p==k&&p>1)edge[i]=p-1;
            else return 0;
            if(d[ver[i]]==d[x]+edge[i])return 0;
            if(d[ver[i]]>d[x]+edge[i]){
                d[ver[i]]=d[x]+edge[i];
                q.push(make_pair(-d[ver[i]],ver[i]));
            }
        }  
    }
    return 1;
}

int main(){
    scanf("%d",&t);
    while(t--){
        
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<=n;i++)
            d[i]=0x7f7f7f7f;
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y,0);
        }
        if(dijkstra()){
            printf("Yes\n");
            for(int i=1;i<=cnt;i++)
                printf("%d ",edge[i]);
            puts("");
        }else{
            printf("No\n");
        }
        for(int i=0;i<=cnt;i++)
            ver[i]=edge[i]=nextt[i]=0;
        for(int i=0;i<=n;i++)
            v[i]=head[i]=0;
        cnt=0;
        while(q.size())q.pop();
    }
}