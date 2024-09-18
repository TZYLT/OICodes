#include<bits/stdc++.h>
using namespace std;
int bt[100100];
int n;
long long ans=0;
queue<long long> l,r;
long long read()
{
	char ch=getchar();
	int x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') 
		f=-1;
		ch=getchar();
	}
  	while(isdigit(ch)){
  		x=x*10+ch-'0',ch=getchar();
	}
  	return x*f;	
}
long long get(void){
    long long x=0;
    if(r.size()==0){x=l.front();l.pop();return x;}
    if(l.size()==0){x=r.front();r.pop();return x;}
    if(l.front()<r.front())x=l.front(),l.pop();
    else x=r.front(),r.pop();
    return x;
}
int main(){ 
    n=read();
    for(int i=1,x;i<=n;i++)
        x=read(),bt[x]++;
    for(int i=1;i<=100000;i++)
        for(int j=1;j<=bt[i];j++)
            l.push(i);
    while(l.size()+r.size()>1){
        long long x=get();
        long long y=get();
        ans+=x+y;
        r.push(x+y);
    }
    printf("%lld\n",ans);
}