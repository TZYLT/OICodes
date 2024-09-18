#include<bits/stdc++.h>
using namespace std;
void exgcd(__int128 a,__int128 b,__int128 &x,__int128 &y) {
    if(b == 0) {x = 1;y = 0;return;}
    exgcd(b, a % b,x,y);
    __int128 Last_x = x;
    x = y;
    y = Last_x - a / b * y;
}
int n;
__int128 na,nb;
int main(){
    scanf("%d",&n);
    n--;
    long long ta,tb;
    scanf("%lld%lld",&ta,&tb);
    na=ta;nb=tb;
    while(n--){
        long long a,b;
        __int128 c,x,y;
        scanf("%lld%lld",&a,&b);
        c=b-nb;
        exgcd(na,-a,x,y);
        x*=c/__gcd(na,(__int128)-a);
        nb=na*x+nb;
        na=na*a/__gcd(na,(__int128)a);
        nb%=na;
    }
    printf("%lld\n",((nb%na+na)%na));
}