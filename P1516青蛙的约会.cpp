#include<bits/stdc++.h>
using namespace std;
long long x,y,m,n,l,a,b;

void exgcd(long long a, long long b, long long &x, long long &y) {
    if(b == 0) {x = 1;y = 0;return;}
    exgcd(b, a % b,x,y);
    long long Last_x = x;
    x = y;
    y = Last_x - a / b * y;
}

int main(){
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    a=n-m;
    b=l;int c=x-y;
    if(a<0)a*=-1,c*=-1;
    exgcd(a,b,x,y);
    int g=__gcd(a,b);
    if(c%g)printf("Impossible");
    else printf("%lld\n",(c/g*x%(b/g)+b/g)%(b/g));
}