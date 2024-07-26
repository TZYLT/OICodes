#include<bits/stdc++.h>
using namespace std;
#define M 200500
int n,q,k;
vector<int> opt[M];
bool st[M];
int ans=0;
int check(){
    int ans=0;int v=0;;
    for(int i=0;i<=n+1;i++)
        if(st[i])v++;
        else if(v>0)ans++,v=0;
    return ans;
}

int main(){
    auto stt=clock();
    freopen("ex_light.in","r",stdin);
    freopen("ex_light.out","w",stdout);
    
    scanf("%d%d%d",&n,&q,&k);
    for(int i=1,x;i<=n;i++)
        scanf("%d",&x),opt[x].push_back(i);
    while(q--){
        int op;
        scanf("%d",&op);
        for(int c:opt[op]){
            //st[c]^=1;
            if(st[c-1]==1&&st[c]==0&&st[c+1]==1)st[c]=1,ans--;
            else if(st[c-1]==1&&st[c]==0&&st[c+1]==0)st[c]=1;
            else if(st[c-1]==0&&st[c]==0&&st[c+1]==1)st[c]=1;
            else if(st[c-1]==0&&st[c]==0&&st[c+1]==0)st[c]=1,ans++;
            else if(st[c-1]==1&&st[c]==1&&st[c+1]==1)st[c]=0,ans++;
            else if(st[c-1]==1&&st[c]==1&&st[c+1]==0)st[c]=0;
            else if(st[c-1]==0&&st[c]==1&&st[c+1]==1)st[c]=0;
            else if(st[c-1]==0&&st[c]==1&&st[c+1]==0)st[c]=0,ans--;
        }
        printf("%d\n",ans);
    }
    //cerr<<clock()-stt;
}