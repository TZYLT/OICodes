#include<bits/stdc++.h>
using namespace std;
int n,k,a[1001000];
int minn[1001000],maxx[1001000];
int q[1001000],h=0,t=1;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++){
        while(h-t+1>0&&q[t]<=i-k)t++;
        while(h-t+1>0&&a[q[h]]<a[i])h--;
        q[++h]=i;
        maxx[i]=q[t];
    }
    h=0,t=1;
    for(int i=1;i<=n;i++){
        while(h-t+1>0&&q[t]<=i-k)t++;
        while(h-t+1>0&&a[q[h]]>a[i])h--;
        q[++h]=i;
        minn[i]=q[t];
    }
    for(int i=k;i<=n;i++)
        printf("%d ",a[minn[i]]);
    printf("\n");
    for(int i=k;i<=n;i++)
        printf("%d ",a[maxx[i]]);
}