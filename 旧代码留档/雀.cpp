#include<bits/stdc++.h>
using namespace std;
int t,a,b;
int main(){
    cin>>t;
    while(t--){
        cin>>a>>b;
        int c=b-a;
        int ans;
        if(c<=24000)
            ans=5;
        else if(c<=36000)ans=6;
        else if(c<=48000)ans=8;
        else if(c<=72000)ans=11;
        else ans=13*ceil((double)c/((double)4*24000));
        printf("%d\n",ans);
    }
}