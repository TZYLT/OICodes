#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int v[2002000],p[2002000],mn[2000200],k;
void linearSieve(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i,mn[i]=i;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            mn[i*p[j]]=p[j];
            if(i%p[j]==0)break;
        }
    }
}
int pm[200200],used[200200],n;
int maxx[2002000],sum[2002000];
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=res*a;
        a=a*a;
        k>>=1;
    }
    return res;
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    linearSieve(2000000);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",pm+i);
    sort(pm+1,pm+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(maxx[pm[i]]==0)maxx[pm[i]]++,sum[pm[i]]=1,used[i]=1;
        else{
            int f=pm[i]-1;
            while(f>1){
                int t=mn[f],c=0;
                
                while(f%t==0)f/=t,c++;
               
                if(maxx[t]<c)maxx[t]=c,sum[t]=1;
                else if(maxx[t]==c)sum[t]++;
            }
        }
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        if(used[i]==1){
            if(maxx[pm[i]]==1&&sum[pm[i]]>1)flag=1;
            else if(maxx[pm[i]]>1)flag=1;
        }
        else{
            int f=pm[i]-1,sd=1;
            while(f>1){
                int t=mn[f],c=0;
                while(!(f%t))f/=t,c++;
                if(maxx[t]==c&&sum[t]==1)sd=0; 
            }
            if(sd==1)flag=1;
        } 
        if(flag)break;
    }
    long long ans=1;
    for(int i=1;i<=2000000;i++)
        ans=(ans*qpow(i,maxx[i]))%mod;
    ans+=flag;
    printf("%lld\n",ans%mod);
}