#include<bits/stdc++.h>
using namespace std;
int n,q,x,y,a;
struct line{
    long long data[65];
    void add(long long x){
        for(int i=62;i>=0;i--)
            if(x>>i&1){
                if(!data[i])return data[i]=x,void();
                else x^=data[i];
            }
    }
    void merge(line x){
        for(int i=0;i<=64;i++)
            add(x.data[i]);
    }
    void clear(void){
        for(int i=0;i<=64;i++)
            data[i]=0;
    }
};

