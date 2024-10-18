#include<bits/stdc++.h>
using namespace std;
int n,k;
int f[10100];
vector<int> ts[10010];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ts[x].push_back(y);
    }
    for(int i=n;i>=1;i--){
        if(ts[i].size()==0)f[i]=f[i+1]+1;
        else{
            for(int c:ts[i])
                f[i]=max(f[i+c],f[i]);
        }  
    }
    printf("%d\n",f[1]);
}