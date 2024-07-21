#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int f[2][1024][2][2],n;
int l[10100],r[10100],x;
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int popcount(int x){
	int ans=0;
	while(x){
		if(x&1)ans++;
		x>>=1;
	}
	return ans;
}
void add(int &a,int &b){a=(a+b);if(a>=p)a-=p;}
int cal(int *a){
	for(int i=0;i<=1;i++)
		for(int s=0;s<1024;s++)
			for(int lim=0;lim<=1;lim++)
				for(int t=0;t<=1;t++)
					f[i][s][lim][t]=0;
	f[0][0][1][0]=1;
	for(int i=0;i<=n;i++)
		for(int s=0;s<1024;s++)	
			for(int nt=0;nt<=9;nt++)
				for(int lim=0;lim<=1;lim++){
					if(lim==1&&nt>a[i+1])continue;
					if(nt==0)add(f[(i+1)&1][s][(lim&(nt==a[i+1]))][0],f[i&1][s][lim][0]);
					if(nt!=0)add(f[(i+1)&1][s|(1<<nt)][(lim&(nt==a[i+1]))][1],f[i&1][s][lim][0]);
					add(f[(i+1)&1][s|(1<<nt)][(lim&(nt==a[i+1]))][1],f[i&1][s][lim][1]);
				}
	int ans=0;
	for(int s=0;s<1024;s++)	
		for(int lim=0;lim<=1;lim++)
			if(popcount(s)==x)
				add(ans,f[(n)&1][s][lim][1]);
	return ans;
					
}
int bf(int n){
	int ans=0;
	for(int i=1;i<=n;i++){
		int t=i,s=0;
		while(t)s|=(1<<(t%10)),t/=10;
		if(popcount(s)==x)ans++;
		//printf("[%d]:%d\n",i,popcount(s));
	}
	return ans;
}

int main(){
	freopen("math1.in","r",stdin);
	freopen("math.out","w",stdout);
	//double st=clock();
	scanf("%d",&n);    
    for(int i=1;i<=n;i++){
        char c=getchar();
        while('0'>c||c>'9')c=getchar();
        l[i]=c-'0';
    }
    for(int i=1;i<=n;i++){
	    char c=getchar();
	    while('0'>c||c>'9')c=getchar();
		r[i]=c-'0';
	}
	int s=0;
	for(int i=1;i<=n;i++)
		s|=(1<<l[i]);
	scanf("%d",&x);
    printf("%d\n",cal(r)-cal(l)+(popcount(s)==x));
	//cerr<<clock()-st;
}
