#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a[1000];
    a[1]=0;
    a[2]=1;
    for(int i=3;i<=990;i++)  
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    cin>>n;
    cout<<a[n];

}