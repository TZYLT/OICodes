#include<bits/stdc++.h>
using namespace std;
int Hash(int p,int q,string &s){
    int h=0,t=1;
    for(int i=1;i<=s.size();i++)
        (h+=t*s[i-1])%=p,
        t=t*q%p;
    return h;
}
vector<pair<int,int> > ans;;
int n;
string  s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        cin>>s;
        ans.push_back({Hash(998244353,131,s),Hash(1000000007,13331,s)});
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",unique(ans.begin(),ans.end())-ans.begin());

}