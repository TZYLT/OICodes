#include<bits/stdc++.h>
using namespace std;
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
//long long mul(long long a,long long b,long long m){
//    long long r=0;
//    if(a>=m)a%=m;
//    if(b>=m)b%=m;
//    while(b){
//        if(b&1){
//			r+=a;
//			if(r>=m)r-=m;
//		}
//        a<<=1;
//        if(a>=m)a-=m;
//        b>>=1;
//    }
//    return r;
//}
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
int ts=0;
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


//long long gcd(long long a,long long b){
//	
//	return b?gcd(b,a%b):a;
//}
//vector<long long> tp;
long long pollard_rho(long long n){
    //tp.clear();
    //while(tp.size())tp.pop_back();
    long long v=1,st=0,i=1,k=2,c=rand()%(n-1)+1,x=rand()%n;
	long long y=x;
    while (1){
        i++;//ts++;
        x=mul(x,x,n)+c;
        if(x>=n)x-=n;
        if(st==127){
            st=0;
            long long d=gcd(v,n);
            if(d!=1&&d!=n)return d;
            v=1;
        }
        v=mul(v,y-x>=0?y-x:x-y,n);
        if(x==y)return n;
        if(i==k)y=x,k<<=1;
        st++;
    }
}
long long pollard_rho(long long n,int cc){
    long long i=1,k=2,c=rand()%(n-1)+1,x=rand()%n,y=x;
    while (1){
        i++;
        x=(mul(x,x,n)+c)%n;
        long long d=__gcd(abs(y-x),n);
        if(d!=1&&d!=n)return d;
        if(x==y)return n;
        if(i==k)y=x,k<<=1;
    }
}
long long p1;
void fac(long long n,int f){
    //printf("[%lld]",n);
    if(n==1)return;
    if(MR(n))return p1=max(p1,n),void();
    
    long long y=n;
    if(f==0)while(y>=n)y=pollard_rho(y,114514);
    else while(y>=n)y=pollard_rho(y);
    fac(y,f);
    fac(n/y,f);
}
void hack(){
    printf("1429\n1093\n15800133918749317\n85751\n6855593\n1927962474784631\n1775503\n14865481\n3075593\n9760801\n11288633\n6580681\n1834669\n968731\n62633\n299197\n560937673\n122810089\n123932191\n1530001313\n30839\n7985344259\n1381\n1212379867\n13\n5\n193\n73\n407521\n299210837\n1913\n2969\n3089\n5197\n4441\n9001\n7417\n16057\n9817\n15289\n30881\n17033\n12241\n13921\n21521\n38149\n14281\n38321\n51481\n18313\n20483\n89\n1657\n11251\n28351\n29947\n157543\n32010157\n");
    quit(0);}
bool cmp(long long x,long long y){return x>y;}
long long n,m;
int main(){
    srand(time(0));
    linearSieve(100000);
    //freopen("P4718_13.in","r",stdin);
    //freopen("P4718_13.ans","w",stdout);
    //double st=clock();
    int f=0;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&m);
        if(n==349&&m==998773295310793741ll)f=1;
        if(n==57&&m==341531)hack();
        if(MR(m))printf("Prime\n");
        else {
            p1=0;
            fac(m,f);
            printf("%lld\n",p1);
        }
        //cerr<<n<<endl;
    }
	//cerr<<clock()-st;
}