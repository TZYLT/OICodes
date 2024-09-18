#include<bits/stdc++.h>
using namespace std;
long long n,m,phi,x,y;
int v[100100],p[100100],k;
int pri[7]={2,325,9375,28178,450775,9780504,1795265022};
void linearSieve(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
long long mul(__int128 a,__int128 b,__int128 c){
	return a*b%c;
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
    if(n<=100000)return !v[n];
    if(!(n&1))return 0;
    for(int i=0;i<=6;i++)
        if(!MRtest(pri[i],n))return 0;
    return 1;
}
#define mytz __builtin_ctzll
long long gcd(long long a, long long b){
    if(!a) return b;
    if(!b) return a;
    register int t = mytz(a|b) ;
    a >>= mytz(a) ;
    do{
        b >>= mytz(b) ;
        if(a>b){long long t=b;b=a,a=t;}
        b-=a;
    }while(b);
    return a<<t;
}
long long pollard_rho(long long n){
    long long i=1,k=2,c=rand()%(n-1)+1,x=rand()%n,y=x;
    while (1){
        i++;
        x=(mul(x,x,n)+c)%n;
        long long d=gcd(abs(y-x),n);
        if(d!=1&&d!=n)return d;
        if(x==y)return n;
        if(i==k)y=x,k<<=1;
    }
}
vector<long long> fc;
void fac(long long n){
    if(n==1)return;
    if(MR(n)){
        fc.push_back(n);
        return;
    }
    long long y=n;
    while(y>=n)y=pollard_rho(y);
    fac(y);
    fac(n/y);
}
int od;

long long getord(long long a) {
	int cnt;
	long long ans = 1, pm;
	for(int i = 0; i < od; i++) {
		cnt = 0; pm = phi;
		while(pm%fc[i] == 0) pm /= fc[i], cnt++;
		//for 循环枚举阶在这个质因数上最小的次数
		for(long long px = 1; cnt; px *= fc[i], cnt--)
			if(qpow(a, pm*px, m) > 1)
				ans *= fc[i];
	}
	return ans;
}
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    srand(time(0));
    linearSieve(100000);
    scanf("%lld%lld",&m,&n);
    fc.clear();
    fac(m);
    phi=m-(m/fc[0]);
    fc.clear();
    fac(phi);

    sort(fc.begin(),fc.end());
    od=unique(fc.begin(),fc.end())-fc.begin();

    while(n--){
        scanf("%lld%lld",&x,&y);
        long long ox=getord(x),oy=getord(y);
        //if(ox<oy)swap(ox,oy);
        printf((ox%oy)?"No\n":"Yes\n");
    }
}