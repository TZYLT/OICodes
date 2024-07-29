#include<bits/stdc++.h>
using namespace std;
long long k,ans,f;
string s;
set<pair<int,int> > _map;
long long sol(int &x,int &y){
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='L')x--;
        if(s[i]=='R')x++;
        if(s[i]=='U')y++;
        if(s[i]=='D')y--;
        if(_map.count(make_pair(x,y))==0){
            ans++;
            _map.insert(make_pair(x,y));
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    cin>>k;
    int x=0,y=0;
    _map.insert(make_pair(x,y));f++;
    for(int i=1;i<=min(100ll,k);i++)f+=sol(x,y);
    int lop=0;
    for(int i=1;i<=20;i++){lop+=sol(x,y);}
    //cout<<f<<' '<<lop<<endl;
    if(k<=100)  cout<<f<<endl;
    else cout<<f+lop*((k-100)/20)<<endl;
}