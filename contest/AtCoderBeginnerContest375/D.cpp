#include<bits/stdc++.h>
using namespace std;
vector<int> st[30];
int n;
string s;
long long ans;
int main(){
    cin>>s;n=s.size();
    for(int i=1;i<=n;i++)
        st[s[i-1]-'A'].push_back(i);
    for(int i=0;i<=25;i++){
        for(int j=1;j<=st[i].size();j++)
            ans+=(2*j-st[i].size()-1)*st[i][j-1]+(j-st[i].size());
    }
    printf("%lld\n",ans);
}