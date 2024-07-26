#include<bits/stdc++.h>
using namespace std;
string s;
int sub[(1<<20)+(1<<19)];
bool v[(1<<20)+(1<<19)]; 
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++) {
        int st=0;
        for(int j=i;j-i+1<=20&&j<=(int)s.size()-1;j++){
            if(((st>>(s[j]-'a'))&1)==0){
                st|=(1<<(s[j]-'a'));
                sub[st]=__builtin_popcount(st);
                v[st]=1;
            }
            else break;
        }
    }
    for(int i=0;i<20;i++)    
        for(int s=0;s<(1<<20);s++)
            if(s&(1<<i))
                sub[s]=max(sub[s],sub[s^(1<<i)]);
    int ans=0;
    for(int s=0;s<(1<<20);s++)
        if(v[s])
            ans=max(ans,__builtin_popcount(s)+sub[(~s)&((1<<20)-1)]);
    printf("%d\n",ans);

        
}