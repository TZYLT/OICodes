#include<bits/stdc++.h>
using namespace std;
string s;bool v[1000],side[1000];
int 
int n,m;
int gets(bool *s){
    bool st=s[1];int ans=0;
    for(int i=1;i<=n;i++)
        if(st!=s[i])ans++,st=s[i];
    return ans;
}
int f(int x){
    
}
vector<pair<int,int> > sett;
int main(){
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=0;i<n;i++)
        else if(s[i]=='B')v[i+1]=0;
        else if(s[i]=='W')v[i+1]=1;

    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%c%d",&x,&y);

        sett.push_back(make_pair())
    }
}


int nxt[];
void kmp(string &s){
    nxt[1]=0;
    for(int i=2;i<=s.size();i++){
        int p=nxt[i-1];
        while(p!=0)
            if(s[p+1]==s[i]) break;
            else p=nxt[p];
        nxt[i]=(s[p+1]==s[i])?p+1:0;
    }
}