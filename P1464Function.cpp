#include <bits/stdc++.h>
using namespace std;
long long m[25][25][25];
bool v[25][25][25];
long long w(long long a,long long b,long long c){
    //printf("(%lld,%lld,%lld:%lld)",a,b,c,m[a][b][c]);
    //fflush(stdout);
    if(a<=0||b<=0||c<=0) return 1;
    else if(v[a][b][c]==1) return m[a][b][c];
    else if(a>20||b>20||c>20) m[a][b][c]=w(20,20,20);
    else if(a<b&&b<c) m[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else m[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    v[a][b][c]=1;
    //printf("(%lld,%lld,%lld:%lld)",a,b,c,m[a][b][c]);
    return m[a][b][c];
}
int main(){
    long long a,b,c;
    memset(m,0,sizeof(m));
    while(scanf("%lld%lld%lld",&a,&b,&c)==3){
        
        if(a==-1&&b==-1&&c==-1)break;
        printf("w(%lld, %lld, %lld) = ",a,b,c);
        if(a>20)a=21;if(b>20)b=21;if(c>20)c=21;
        printf("%lld\n",w(a,b,c));
    }
    return 0;
}