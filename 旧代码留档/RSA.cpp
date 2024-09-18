#include<bits/stdc++.h>
using namespace std;
int pri[7]={2,325,9375,28178,450775,9780504,1795265022};
long long mul(long long a,long long b,long long m){
   long long r=0;
   if(a>=m)a%=m;
   if(b>=m)b%=m;
   while(b){
       if(b&1){
			r+=a;
			if(r>=m)r-=m;
		}
       a<<=1;
       if(a>=m)a-=m;
       b>>=1;
   }
   return r;
}
long long qpow(long long a,long long k,long long p){
    long long res=1;
    while(k){
        if(k&1) res=mul(res,a,p);
        a=mul(a,a,p);
        k>>=1;
    }
    return res%p;
}
bool MRtest(long long a,long long n){
    long long t=n-1,u=0;
    while(!(t&1))t>>=1,u++;
    long long b=qpow(a,t,n);
    while(u--){
        long long tmp=mul(b,b,n);
        if(b!=1&&b!=(n-1)&&tmp==1)
            return 0;
        b=tmp;
    }
    if(b!=1)return 0;
    return 1;
}
bool MR(long long n){
    if(!(n&1))return 0;
    for(int i=0;i<=6;i++)
        if(!MRtest(pri[i],n))return 0;
    return 1;
}
string s="SB";
long long rsa(int a);
long long p,q,n,e,d;
const int M=10000000;
int main(){
    while(!MR(p))p=rand()%M;
    while(!MR(q))q=rand()%M;
    n=p*q;
    e=1;
    while(gcd(e,n))
}