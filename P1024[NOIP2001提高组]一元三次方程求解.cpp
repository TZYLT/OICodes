#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
double f(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
double 
double search(double l,double r){
    if(r-l<=0.0001)return l;
    double mid=(l+r)/2.0;
    double ans=f(mid);
    if(ans>0)return search()
}