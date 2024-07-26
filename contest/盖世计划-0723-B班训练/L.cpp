#include<bits/stdc++.h>
using namespace std;
int n;
long long ss,ts;
string s;
void pt(long long x){
    while(x)printf("%d",x&1),x>>=1;
    printf("\n");
}
int ans;
int main(){
    scanf("%d",&n);
    cin>>s;
    for(auto c:s) ss<<=1,ss|=(c)-'0';
    ts=(1<<(s.size()))-1;
    for(long long i=1;i<(1<<n);i++){
        long long t=(i<<n)+i;
        while(t){
            if((t&ts)==ss){
                ans++;
                break;
            }
            t>>=1;
        }
    }
    printf("%d\n",ans);
}