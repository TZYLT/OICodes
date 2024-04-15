#include<bits/stdc++.h>
using namespace std;
long long t,n,m;
int ans[2][2]={{3,2},{1,-1}};
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        printf("%d\n",ans[n&1][m&1]);
    }
}