#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
    cin>>s>>t;
    for(int i=1;i<=min(s.size(),t.size());i++){
        if(s[i-1]!=t[i-1]){
            printf("%d\n",i);
            return 0;
        }
    }
    if(s.size()==t.size())printf("0\n");
    else printf("%d",min(s.size(),t.size())+1);
    
}