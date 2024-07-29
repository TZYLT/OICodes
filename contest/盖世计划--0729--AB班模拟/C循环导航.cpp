#include<bits/stdc++.h>
using namespace std;
long long k,ans,f,l;
string s;
set<pair<int,int> > _map;
int main(){
    freopen("loop.in","r",stdin);
    freopen("loop.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    cin>>k;
    int x=0,y=0;
    _map.insert(make_pair(x,y));f++;
    for(int i=0;i<s.size();i++){
        if(s[i]=='L')x--;
        if(s[i]=='R')x++;
        if(s[i]=='U')y++;
        if(s[i]=='D')y--;

        if(_map.count(make_pair(x,y))==0){
            f++;
            _map.insert(make_pair(x,y));
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='L')x--;
        if(s[i]=='R')x++;
        if(s[i]=='U')y++;
        if(s[i]=='D')y--;

        if(_map.count(make_pair(x,y))==0){
            l++;
            _map.insert(make_pair(x,y));
        }
    }
    cout<<f+l*(k-1)<<endl;
}