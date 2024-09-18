#include<bits/stdc++.h>
using namespace std;
int k,n;
long long a[10010000];
long long cnt,val;
string s;
int main(){
    cin>>k>>n;
    cin>>s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i+=10){
        long long t=1;
        for(int j=0;i+j<s.size()&&j<10;j++)
            a[i/10+1]+=t*(s[i+j]-'0'),t*=10;
    }
    for(int i=1;i<=n;i++){
        a[i+1]+=a[i]/k;
        a[i]%=k;
    }
    int len=0;
    for(int i=10000000;i>=1&&(!a[i]);len=--i);
    for(int i=1;i<=len;i++){
        if(cnt==0)val=a[i],cnt++;
        else if(val==a[i])cnt++;
        else cnt--;
    }
    cout<<val<<endl;
}