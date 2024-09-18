#include<bits/stdc++.h>
using namespace std;
int n,w;
vector<pair<int,int> > item;
//v-c
int f[40040];
int main(){
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        for(int j=1;j<=c;j<<=1)
            item.push_back(make_pair(j*a,j*b)),c-=j;
        if(c)item.push_back(make_pair(c*a,c*b));
    }
    for(auto it:item){
        for(int i=w;i>=it.second;i--)
            f[i]=max(f[i],f[i-it.second]+it.first);
    }
    int ans=0;
    for(int i=0;i<=w;i++)
        ans=max(ans,f[i]);

    printf("%d\n",ans);
}