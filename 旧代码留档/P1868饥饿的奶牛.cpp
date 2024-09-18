#include<bits/stdc++.h>
using namespace std;
vector<int> sd[3003000];
int f[3003000],mf[3003000];
int n,x,y;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        x++;y++;
        sd[y].push_back(x);
    }
    for(int i=1;i<=3000001;i++){
        if(sd[i].size())
            for(auto c:sd[i])
                f[i]=max(f[i],mf[c-1]+(i-c+1));
        mf[i]=max(f[i],mf[i-1]);
    }
    printf("%d\n",mf[3000001]);
    
}
