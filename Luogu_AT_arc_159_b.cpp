#include<bits/stdc++.h>
using namespace std;
long long ans,a,b;
int v[2000100],p[2000100],k;
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

int main(){
    linearSieve(2000000);
    cin>>a>>b;
    while(a>0&&b>0){
       
        long long g=__gcd(a,b);
        a/=g;b/=g;
        if(a>b)swap(a,b);
        
        if(a+1==b){ans+=a;break;}
        if(a==1){ans++;break;}
        long long t=b-a;
        for(int i=1;p[i]*p[i]<=b&&i<=k;i++)
            if((b-a)%p[i]==0)
                if(a%t>a%p[i])t=p[i];
        ans+=a%t;
        a-=a%t;b-=b%t;
    }
    cout<<ans<<endl;
}