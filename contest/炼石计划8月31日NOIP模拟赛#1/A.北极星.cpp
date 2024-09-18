#include<bits/stdc++.h>
using namespace std;
int sum,n;
int b[100100];
string s[10010];
void sol(int x,int i){
    vector<bool> c;
    while(x)c.push_back(x&1),x>>=1;
    s[i]+="1";c.pop_back();
    while(c.size())
        s[i]+=(c.back()?"c+1+":"c+"),sum+=c.back()?2:1,c.pop_back();
}
int main(){
    freopen("polaris2.in","r",stdin);
    freopen("polaris.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",b+i);
    for(int i=n;i>=1;i--)
        sol(b[i]+sum,i);
    for(int i=1;i<=n;i++)
        printf("%s",s[i].c_str());
}