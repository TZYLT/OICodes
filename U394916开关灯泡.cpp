#include<bits/stdc++.h>
using namespace std;
bitset<10010000> a,b;
int n,m;
int l,r;
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&l,&r);
        b.set();
        b>>=(n-r+1);
        b<<=(n-r+1)+(l-1);
        b>>=l-1;
        a^=b;
    }
    for(int i=1;i<=n;i++)
		printf("%c ",a[i]+'0');
}