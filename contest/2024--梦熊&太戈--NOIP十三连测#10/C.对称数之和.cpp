#include<bits/stdc++.h>
using namespace std;
set<long long> st;
long long n,len;
long long ans=0;
int main(){
    cin>>n;
    string tt=to_string(n);
    len=pow(10,(tt.size()+1)>>1);
    for(int i=1;i<=len;i++){
        long long tmp=i;
        string s=to_string(i);
        for(int j=0,t=pow(10,s.size());j<s.size();j++,t*=10)
            tmp+=t*(s[j]-'0');
        if(tmp<=n)st.insert(tmp);
    }
    for(int i=1;i<=len;i++){
        long long tmp=i;
        string s=to_string(i);
        for(int j=0,t=pow(10,s.size());j<s.size()-1;j++,t*=10)
            tmp+=t*(s[j+1]-'0');
        if(tmp<=n)st.insert(tmp);
    }
    for(long long c:st)
        if(st.count(n-c)>0)
            ans++,printf("[%d][%d,%d]\n",ans,c,n-c);
    printf("%lld\n",ans);
}