#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int a,b,c,d;
        a=b=c=d=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='A')a++;
            else if(s[i]=='B')b++;
            else if(s[i]=='C')c++;
            else if(s[i]=='D')d++;
        cout<<min(a,n)+min(b,n)+min(c,n)+min(d,n)<<"\n";
    }
    
}