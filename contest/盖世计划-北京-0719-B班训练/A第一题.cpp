#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
long long d[1001000];
long long v[1000010],p[1000010],k;
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
long long f[1001000][4],ct[1001000];
long long check(int p){
    for(int i=1;i<=n;i++) ct[i]=0;
    for(int i=1;i<=n;i++)
        if(d[i]%p==0) ct[i]=0;
        else if((d[i]+1)%p==0||(d[i]-1)%p==0) ct[i]=b;
        else ct[i]=(1ll<<60);
        
	for(int i=1;i<=n;i++)
	    f[i][0]=f[i][2]=f[i][3]=(1ll<<60);	
	    
	f[1][0]=min(f[1][0],f[0][0]+ct[1]);
    for(int i=1;i<=n;i++){
        f[i+1][0]=min(f[i+1][0],f[i][0]+ct[i+1]);
        f[i+1][2]=min(f[i+1][2],f[i][0]+a);
        f[i+1][2]=min(f[i+1][2],f[i][2]+a);
        f[i+1][3]=min(f[i+1][3],f[i][2]+ct[i+1]);
        f[i+1][3]=min(f[i+1][3],f[i][3]+ct[i+1]);
    }
    
    long long ans=min({f[n][0],f[n][2],f[n][3]});
	for(int i=1;i<=n;i++)
	    f[i][0]=f[i][2]=f[i][3]=(1ll<<60);	
	    
    for(int i=0;i<=n-2;i++){
        f[i+1][0]=min(f[i+1][0],f[i][0]+ct[i+1]);
        f[i+1][2]=min(f[i+1][2],f[i][0]+a);
        f[i+1][2]=min(f[i+1][2],f[i][2]+a);
        f[i+1][3]=min(f[i+1][3],f[i][2]+ct[i+1]);
        f[i+1][3]=min(f[i+1][3],f[i][3]+ct[i+1]);
    }
    f[n][0]=min(f[n][0],f[n-1][0]+ct[n]);
    f[n][3]=min(f[n][3],f[n-1][2]+ct[n]);
    f[n][3]=min(f[n][3],f[n-1][3]+ct[n]);   
	return min({ans,f[n][0],f[n][2],f[n][3]});
}
bool tag[1000010];
vector<int> ft;
void fc(int x){
	for(int i=1;i<=k;i++)
		if(x%p[i]==0){
			tag[i]|=1;
			while(x%p[i]==0)x/=p[i];
			if(x==1)return; 
		}
	if(x!=1) ft.push_back(x);
}
int main(){
    linearSieve(100000);
    scanf("%lld%lld%lld",&n,&a,&b);
    
    for(int i=1;i<=n;i++)
        scanf("%lld",&d[i]);
    long long t=d[1];
    for(int i=2;i<=n;i++)
        t=__gcd(t,d[i]);
    if(t!=1){
        printf("0\n");
        return 0;
    }
    
    fc(d[1]);fc(d[1]-1);fc(d[1]+1);
    fc(d[n]);fc(d[n]-1);fc(d[n]+1);
    
    long long ans=(1ll<<60);
    for(int j=1;j<=k;j++)
        if(tag[j]){
            ans=min(ans,check(p[j]));
        }
    for(auto c:ft)
		ans=min(ans,check(c));    
    printf("%lld",ans);
}
