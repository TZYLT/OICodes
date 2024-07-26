#include<bits/stdc++.h>
using namespace std;
#define M 10010000
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int dfn[M],low[M],v[M],st[M],top,T,C,s[M];
void tarjan(int x){
    dfn[x]=low[x]=++T;
    st[++top]=x;
    v[x]=1;
    for(int i=head[x];i;i=nextt[i]){
        if(!dfn[ver[i]]){
            tarjan(ver[i]);
            low[x]=min(low[x],low[ver[i]]);
        }
        else if(v[ver[i]])low[x]=min(low[x],dfn[ver[i]]);
    }
    if(dfn[x]==low[x]){
        C++;
        while(st[top]!=x){
            s[st[top]]=C;
            v[st[top]]=0;
            top--;
        }
        s[st[top]]=C;
        v[st[top]]=0;
        top--;
    }
}
vector<pair<int,int> > edge;
int n,m,k;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        edge.push_back(make_pair(x,y));
    }
    for(int j=1;j<=k;j++){
        int w;
        vector<int> S;
        scanf("%d",&w);
        for(int i=1,x;i<=w;i++)
            scanf("%d",&x),S.push_back(x);
        if(w==1){
            add(S[0],S[0]+3*n);
            continue;
        }
        for(int i=0;i<S.size();i++){
            add(S[i]+n,S[i]);
            if(i!=S.size()-1)add(S[i]+n,S[i+1]+n);
        }
        for(int i=S.size()-1;i>=0;i--){
            add(S[i]+n*2,S[i]);
            if(i!=0)add(S[i]+n*2,S[i-1]+n*2);
        }
        //if(S.size()==1)add(s[i],s[i]+3*n);
        for(int i=0;i<S.size();i++){
            if(i!=S.size()-1)add(S[i]+n*3,S[i+1]+n);
            if(i!=0)add(S[i]+n*3,S[i-1]+n*2);
        }
    }

    for(int i=1;i<=m;i++){
        add(edge[i-1].first,edge[i-1].second+3*n);
        add(edge[i-1].second,edge[i-1].first+3*n);
    }
    for(int i=1;i<=4*n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=n;i++)
        if(s[i]==s[i+3*n]){
            printf("NIE\n");
            return 0;
        }
    printf("TAK");

}