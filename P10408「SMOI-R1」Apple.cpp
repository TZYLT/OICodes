#include<bits/stdc++.h>
using namespace std;
long long a[1050][1050],b[1050][1050];
void cal(int t){
    for(int s=0;s<(1<<10);s++)
        b[t][s]=a[t][s];
    for(int i=0;i<10;i++)
        for(int s=0;s<(1<<10);s++)
            if(s&(1<<i))b[t][s]+=b[t][s^(1<<i)];
}
int n,q;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<(1<<n);i++)
        scanf("%lld",&a[(i>>10)&((1<<10)-1)][i&((1<<10)-1)]);
    for(int i=0;i<(1<<10);i++)
        cal(i);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int s,t;
            scanf("%d",&s);
            t=s&((1<<10)-1);
            s=(s>>10)&((1<<10)-1);
            long long ans=0;
            for(int i=0;i<(1<<10);i++)
                if((i&s)==i)
                    ans+=b[i][t];
            printf("%lld\n",ans);
        }else{
            int s,t,x;
            scanf("%d%d",&s,&x);
            t=s&((1<<10)-1);
            s=(s>>10)&((1<<10)-1);
            int y=a[s][t];
            a[s][t]=x;
            for(int i=0;i<(1<<10);i++)
                if((i&t)==t)
                    b[s][i]+=(x-y);
        }
    }
}