#include<bits/stdc++.h>
using namespace std;
int d[1001000],q[1001000],f[1001000],h,k,m,t,n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",d+i);
    scanf("%d",&m);
    while(m--){
        h=0;t=1;
        scanf("%d",&k);
        memset(f,0,sizeof f);
        q[++h]=1;
        for(int i=2;i<=n;i++){
            while(h-t+1>0&&q[t]<i-k)t++;
            f[i]=f[q[t]]+(d[q[t]]<=d[i]);
            while(h-t+1>0&&(f[q[h]]>f[i]||(f[q[h]]==f[i]&&d[q[h]]<=d[i])))h--;
            q[++h]=i;
        }
        printf("%d\n",f[n]);
    }
}