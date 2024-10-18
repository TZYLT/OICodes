#include<bits/stdc++.h>
using namespace std;
double x1[100100],x2[100100],x3[100100],p[100100];
double ans=0;
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf",p+i);
    for(int i=1;i<=n;i++){
        x1[i]=(x1[i-1]+1)*p[i];
        x2[i]=(x2[i-1]+2.0*x1[i-1]+1)*p[i];
        x3[i]=x3[i-1]+(3.0*x2[i-1]+3.0*x1[i-1]+1)*p[i];
        ans+=x3[i];
    }
    printf("%.1lf\n",x3[n]);

}