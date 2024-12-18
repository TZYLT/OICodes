#include<bits/stdc++.h>
using namespace std;
template <int C>
struct FenwickTree{
    int data[C+1],c[C+1];
    FenwickTree()=default;
    int ask(int x){
        int ans=0;
        for(;x;x-=x&-x)ans+=c[x];
        return ans;
    }
    void add(int x,int d){
        for(;x<=C;x+=x&-x) c[x]+=d; 
    }
    void inti(void){
        for(int i=1;i<=C;i++) data[i]=c[i]=0;
    }
};