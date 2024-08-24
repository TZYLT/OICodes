#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    if(n==m){
        int cnt=0;
        while(m--){
            int x,y;
            char c;
            cin>>x>>y>>c;
            if(c=='(') cnt++;
            else cnt--;
        }

        if(cnt==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
}