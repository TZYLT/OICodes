#include<bits/stdc++.h>
using namespace std;
map<int,pair<int,int> > dp[2];
int b[110],cyc[101];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",b+i);
    for(int i=1;i<=m;i++){
        int x=b[i];cyc[i]++;
        while(x!=i)x=b[x],cyc[i]++;
    }
    for(int i=1;i<=n;i++){
        dp[(i&1)^1].clear();
        for(pair<int,int> c:dp[i&1]){
            int lc=c.second;
            int val=c.first;
            int lct=1ll*lc*cyc
            pair<int,int> dp[(i&1)^1][]
            dp[(i&1)^1][]
        }
    }
}