#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
    cin>>n>>s;
    s=' '+s;
    for(int i=3;i<=n;i++)
        if(s[i-1]=='.'&&s[i-2]=='#'&&s[i]=='#')
            ans++;
    cout<<ans<<endl;
}