#include<bits/stdc++.h>
using namespace std;
#define M 75
int in[1000];
int main(){
    freopen("sq.in","w",stdout);
    printf("%d\n",M);
    for(int i=0;i<M;i++)in[i]=i+1;
    random_shuffle(in,in+M);
    for(int i=0;i<M;i++)printf("%d ",in[i]);
}