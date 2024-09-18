#include<bits/stdc++.h>
using namespace std;
int m,phi,t;
int v[(1<<17)],p[(1<<17)],k;

long long qpow(long long a,long long k,long long p){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}

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
vector<int> fc;
void foc(int n){
    int k=1;
    while(n!=1&&p[k]*p[k]<=n){
        if(n%p[k]==0)n/=p[k],fc.push_back(p[k]);
        else k++;
    }
    if(n!=1)fc.push_back(n);
}
long long getord(long long x){
    long long ans=m-1;
    for(auto c:fc)
        if(qpow(x,ans/c,m)==1)
            ans/=c;
    return ans;
}

int main(){
    linearSieve((1<<16)+(1<<15));
    scanf("%d%d",&t,&m);
    foc(m-1);

    while(t--){
        int x;
        scanf("%d",&x);
        x=x%m;
        printf("%d\n",getord(x));

    }
}
