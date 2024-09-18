#include<bits/stdc++.h>
using namespace std;
unsigned int seed,n;
inline unsigned int getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
unsigned int v[20020000],p[20020000],k,a[20020000],b[20020000];
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
    scanf("%u%u",&n,&seed);
    for(int i=1;i<=n;i++)
        a[i]=getnext();
    linearSieve(n);
    cout<<'sb';
    unsigned int ans=0;
    for(int i=1;i<=n;i++)
	    for(int j=1;p[i]*j<=n;j++)
		    a[p[i]*j]+=a[j];
    for(int i=1;i<=n;i++)
        ans^=a[i];
    printf("%u\n",ans);
}