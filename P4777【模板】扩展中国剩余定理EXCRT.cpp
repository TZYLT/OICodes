#include<numeric>
#include<bits/stdc++.h>
using namespace std;

void exgcd(long long a, long long b, long long &x, long long &y) {
    if(b == 0) {x = 1;y = 0;return;}
    exgcd(b, a % b,x,y);
    long long Last_x = x;
    x = y;
    y = Last_x - a / b * y;
}
long long mul(long long a,long long b,long long m){
    long long r=0;
    while(b){
        if(b&1)r=(r+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return r;
}
long long na,nm,sol;
void merge(long long a1,long long m1,long long a2,long long m2){
    na=nm=sol=0;
    if((a2-a1)%gcd(m1,m2)!=0)return;
    long long x,y;
    exgcd(m1,-m2,x,y);
    
}