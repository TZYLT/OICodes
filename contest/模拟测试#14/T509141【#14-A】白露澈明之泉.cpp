#include<bits/stdc++.h>
using namespace std;
int n;
string s[3030];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++)
            if(s[i][j-1]=='0')cnt++;
        ans=min(ans,cnt);
    }
    ans+=n;
    for(int i=1;i<=n;i++){
        int cnt=1;
        for(int j=1;j<=n;j++)
            if(s[j][i-1]=='0'){
                cnt=0;
                break;
            }
        ans-=cnt;
    }
    cout<<ans<<endl;
}