#include<bits/stdc++.h>
using namespace std;
int n,k,p,q;
int main(){
    scanf("%d%d%d%d",&n,&k,&p,&q);
    printf("%d\n",(int)((double)k*q/p-n+0.5));
}