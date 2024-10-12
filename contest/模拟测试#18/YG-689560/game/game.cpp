#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int v[501000],cnt[501000];
priority_queue<int> q;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[y]=(v[y]!=0)?-1:x;
    }
    for(int i=1;i<=n;i++)
        if(v[i]>=1&&v[v[i]]!=0)
            v[i]=-1;
    for(int i=1;i<=n;i++)
        cnt[v[i]]+=(v[i]>=1);
    for(int i=1;i<=n;i++)
        if(v[i]==0)q.push(-cnt[i]);
    while(q.size()>1){
        int x=-q.top();q.pop();
        int y=-q.top();q.pop();
        q.push(-max(x,y)-1);
        ans++;
    }
    printf("%d\n",ans-q.top()-1);
}
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=getchar();
    }while(isdigit(c)){
        x=x*10+(c^48);
        c=getchar();
    }return x*f;
}