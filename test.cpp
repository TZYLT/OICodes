#include<bits/stdc++.h>
#include<complex.h>
using namespace std;
complex<long double> w;
int main(){
    w=polar(1,(long duoble)1.2566370614359172953850573533118);
    complex<long double> pw[10000];pw[1]=w;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        pw[i+1]=pw[i]*w;
    
}