#include<bits/stdc++.h>
using namespace std;
bool a[1001000],b[1001000];
int r[1001000],t[1001000];
long long ans;
int n;
string s;
int main(){
    //freopen("poker.in","r",stdin);
    //freopen("poker.out","w",stdout);
    scanf("%d",&n);
    cin>>s;
    for(int i=1;i<=n;i++)   
        a[i]=s[i-1]-'0';
    for(int i=1;i<=n;i++)
        scanf("%d",r+i);
    for(int i=1;i<=n;i++)
        scanf("%d",t+i);
    for(int i=1;i<=n;i++)
        b[i]=a[i]^a[i-1];
    for(int i=1;i<=n;i++)
        if(b[i]){
            ans+=t[i];
            b[i]^=1;
            b[r[i]+1]^=1;
        }
    printf("%lld\n",ans);
}