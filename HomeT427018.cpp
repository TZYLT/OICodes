// #include<bits/stdc++.h>
// using namespace std;
// int n,p,t,a[1001000];
// long long f(int x){
//     long long ans=(long long)p*x;
//     for(int i=1;i<=n;i++){
//         long long t=a[i]-x;
//         ans+=t>=0?t:-t;
//     }
//     return ans;       
// }

// int find(int l,int r){
//     cout<<'['<<l<<','<<r<<']';
//     if(l==r)return l;
//     int mid1=(l+r)/3,mid2=2*(l+r)/3;
//     long long ans1=f(mid1),ans2=f(mid2);
//     if(ans1>=ans2)return find(mid1,r);
//     else return find(l,mid2);
// }
// int main(){
//     //ios::sync_with_stdio(0);
//     //cin.tie(0);
//     cin>>t;
//     while(t--){
//         cin>>n>>p;
//         for(int i=1;i<=n;i++)
//             cin>>a[i];
//         // long long ans=find(-1000000010,1000000010);
//         // if(ans>1000000000||ans<-1000000000)
//         //     cout<<"No\n";
//         // else cout<<ans<<'\n';

        
//     }
// }

#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int t,n,p,a[1001000];
int main(){
    t=read();
    while(t--){
        n=read();
        p=read();
        for(int i=1;i<=n;i++)
            a[i]=read();
        if(p>=2*n)printf("No\n");
        if(p>=-2*n&&p<2*n){
            sort(a+1,a+1+n);
            printf("%d\n",a[(2*n-p+3)/4]);
        }

        if(p+2*n<0)printf("No\n");
    }
}