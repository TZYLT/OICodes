#include<bits/stdc++.h>
using namespace std;

void exgcd(long long a, long long b, long long &x, long long &y) {
    if(b == 0) {x = 1;y = 0;return;}
    exgcd(b, a % b,x,y);
    long long Last_x = x;
    x = y;
    y = Last_x - a / b * y;
}
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        long long a,b,c,x,y;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(c%__gcd(a,b)!=0){
            printf("-1\n");
            continue;
        }
        exgcd(a,b,x,y);
        x*=c/__gcd(a,b);
        y*=c/__gcd(a,b);
        long long da=b/__gcd(a,b),db=a/__gcd(a,b),k;
        if(x<0)k=ceil((1.0-x)/da),x+=da*k,y-=db*k;
        else if(x>=0)k=(x-1)/da,x-=da*k,y+=db*k;
        if(y>0)
            printf("%lld %lld %lld %lld %lld\n",(y-1)/db+1,x,(y-1)%db+1,x+(y-1)/db*da,y);
        else printf("%lld %lld\n",x,y+db*(long long)ceil((1.0-y)/db));
        //y+=(x/da)*(da/b*a);

    }
}