#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int v[2020],in[2020];
int f[2020][2020];
int ans[2020];
bool t[2020][2020];
set<int> s[2020];
vector<int> edge[2020];
int n,m,q;
int main(){
    
    //freopen("ex_graph2.in","r",stdin);
    //freopen("1.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1,x,y;i<=m;i++)
        scanf("%d%d",&x,&y),edge[x].push_back(y),in[y]++;
    for(int i=n;i>0;i--){
        if(edge[i].size()==0){
            f[i][i]=1;
            t[i][i]=1;
        }else{
            f[i][i]=1;
            t[i][i]=1;
            for(int c:edge[i])
                for(int j=1;j<=n;j++)
                    f[i][j]=(f[i][j]+f[c][j])%p,
                    t[i][j]|=t[c][j];
        }
        for(int j=1;j<=n;j++)
            if(t[i][j]==1)
                s[j].insert(i);
    }
   
    for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)
            ans[j]=(ans[j]+f[j][k]*(edge[k].size()==0))%p;
    
    while(q--){
        int aans=0;
        for(int i=0;i<=n;i++)v[i]=0;
        int k,x;
        scanf("%d",&k);
        vector<int> qs;

        for(int i=1;i<=k;i++){
            scanf("%d",&x);
            qs.push_back(x);
            v[x]=1;
        }
        for(int c:qs){
            int f=1;
            for(int d:qs)
                if(d!=c&&s[c].count(d)>0){
                    f=0;break;
                }
            if(f==1)
                aans=(aans-ans[c])%p;
        }
        for(int i=1;i<=n;i++){
            int f=1;
            for(int d:qs)
                if(d!=c&&s[c].count(d)>0){
                    f=0;break;
                }
            if(in[i]==0&&v[i]==0)
                aans=(aans+ans[i])%p;
        }
        printf("%d\n",(aans+p)%p);
    }
}