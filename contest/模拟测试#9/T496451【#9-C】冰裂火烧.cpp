#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int head[1000100],nextt[1000100],edge[1000100],ver[1000100],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int line[500500][2],cir[500500],tot[500500];
int v[500500],fac[500500],dot;
int dfsI(int x,int fa,int len){
    v[x]=1;
    if(tot[x]<2)return -1;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa&&v[ver[i]]==1)return len+1;
        else if(ver[i]!=fa) return dfsI(ver[i],x,len+1);
}
int dfsII(int x,int fa,int len){
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa) 
            return dfsII(ver[i],x,len+1);
    return len;
}
int n,m;

long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
        tot[x]++;tot[y]++;
    }
    for(int i=1;i<=n;i++){
        if(tot[i]==1)
            line[dfsII(i,0,0)]++;
        if(tot[i]==0)
            dot++;
    }
    for(int i=1;i<=n;i++)
        if(!v[i]&&tot[i]==2){
            int _size=dfsI(i,0,0);
            if(_size>0)cir[_size]++;
        }
    fac[0]=1;
    for(int i=1;i<=500000;i++)
        fac[i]=1ll*fac[i-1]*i%p;
    long long ans=1;
    //ans+=fac[line[0]>>1];
    //ans=(ans+1ll*fac[line[1]>>1]*qpow(2,line[1]>>1));
    for(int i=1;i<=n;i++){
        //printf("[%d:%d]",i,line[i]);
        if(i&1){
            int s=line[i][1]+line[i][0];
            ans=ans*fac[s/2]%p*qpow(2,s/2)%p;
            //ans=ans*fac[line[i][1]/2]%p*qpow(2,line[i][1]/2)%p;
        }
        else ans=ans*fac[line[i][0]]%p;
    }
    //printf("\n[%d]\n",dot);
    ans=(ans*fac[dot])%p;
    for(int i=1;i<=n;i++)
        ans=ans*qpow(i,cir[i])%p*fac[cir[i]]%p;
    printf("%lld\n",ans);
}