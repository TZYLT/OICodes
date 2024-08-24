#include<bits/stdc++.h>
using namespace std;
#define M 10009
int n;
int a[M],b[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
        char c;
		cin>>c;
        a[i]=(c=='B')?0:1;
	}
	int ansc=0x7f7f7f7f,ansl=0;
	for(int len=1;len<=n;len++){
		memset(b,0,sizeof b);
		int t=0,flag=1,cnt=0;
		for(int i=1;i<=n;++i){
			t^=b[i];
			if(a[i]^t==0){
				if(i+len-1>n){
                    flag=0;
                    break;
                }
				t^=1;
                b[i+len]^=1;
				cnt++;
			}
		}
		if(flag){
            if(cnt<ansc)
                ansc=cnt,ansl=len;
        }
	}
    printf("%d %d\n",ansl,ansc);
} 
