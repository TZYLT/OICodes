#include<bits/stdc++.h>
using namespace std;
int t;
int aa[11][1100];
void f(int x,int kk){
    for(int i=0;i<=x;i++){
        int k=i,ans=0;
        while(k) ans+=(k%10),k/=10; 
        aa[kk][ans]++;
    }
}
int a[110],b[10];
int main(){
    int t=1;
    for(int i=1;i<=7;i++){
        t*=10;
        f(t-1,i);
        printf("%dDone!\n",i);
    }
    for(int i=0;i<=7;i++){
        printf("{");
        for(int j=0;j<=100;j++){
            printf("%d,",aa[i][j]);
        }
        printf("},\n");
    }
        
    
}