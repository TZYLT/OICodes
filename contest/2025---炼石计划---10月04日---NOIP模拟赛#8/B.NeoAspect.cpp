#include<bits/stdc++.h>
using namespace std;
int n,a[10100];
int dp[20][1<<18];
string t;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        cin>>t;
    for(int i=1;i<=n;i++)
        a[i]=s[i-1]-'0';
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
            for(int k=1;k<=n;k++)
                if(!((j>>k)&1)){
                    if(a[k]){
                        int f=1;
                        for(int l=1;l<=n;l++)
                            if((j>>l)&1)if(a[l]==0)
                                if(])
                    }else{
                        
                    }
                }
}