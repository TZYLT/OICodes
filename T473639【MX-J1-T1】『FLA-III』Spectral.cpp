#include<bits/stdc++.h>
using namespace std;
int t,n,k;
double c,m;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        c=0;
        double tp=1;
        while(tp<=1e60&&n>0) {
            c+=(double)k/(double)tp;
            tp*=n--;
        }
        printf("%.1lf\n",c);

    }
}
