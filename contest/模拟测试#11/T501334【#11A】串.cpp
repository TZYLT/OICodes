#include<bits/stdc++.h>
using namespace std;
long long w[30][30];
long long a[5005000],b[5005000];
long long get(int x,int y){
    return w[a[x]][b[y]]+w[a[y]][b[x]];
}
int n,m;
string s,t;
long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    cin>>s>>t;
    for(int i=1;i<=n;i++){
        a[i]=s[i-1]-'a'+1;
        b[i]=t[i-1]-'a'+1;
    }
    for(int i=1;i<=m;i++)
        for(int j=i;j<=m;j++){
            cin>>w[i][j];
            w[j][i]=w[i][j];
        }

    int l,r;
    l=1;r=2;
    ans=get(1,2);
    for(int i=3;i<=n;i++){
        if(ans+get(r,i)>ans-get(l,r)+get(l,i))
            ans+=get(r,i),l=r,r=i;
        else ans=ans-get(l,r)+get(l,i),r=i;
        //printf("[%d,%d]:%lld\n",l,r,ans);
    }
    cout<<ans<<endl;
}