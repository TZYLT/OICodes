#include<bits/stdc++.h>
using namespace std;
double getw(int w){
    double ans=0;
    ans+=3.0*(w>310?310:w); w-=310;
    if(w<=0)return ans;
    ans+=3.3*(w>210?210:w);w-=210;
    if(w<=0)return ans;
    ans+=4.2*w;
    return ans;
}
int main(){
    int a,s=0;
    double w,lw=0;
    for(int i=1;i<=12;i++){
        scanf("%d",&a);
        w=getw(s+=a);
        printf("%.1lf\n",w-lw);
        lw=w;
    }
}