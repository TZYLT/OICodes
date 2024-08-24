#include<bits/stdc++.h>
using namespace std;
string s;
int a[1001000];
int n;
int w[25][25];
vector<int> id[25];
int main(){
    cin>>s;n=s.size();
    for(int i=1;i<=n;i++)
        a[i]=s[i-1]-'a';
    for(int i=1;i<=n;i++)
        id[a[i]].push_back(i);
    
    
}