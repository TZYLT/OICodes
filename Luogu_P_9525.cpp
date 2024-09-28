#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> > A,B,C;
int n;
int v[200200],a[200200],b[200200],c[200200];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[i]=x;b[i]=y;c[i]=z;
        A.push(make_pair(x,i));
        B.push(make_pair(y,i));
        C.push(make_pair(z,i));
    }
    for(int i=1;i<=n;i++){
        int x=A.top().second,y=B.top().second,z=C.top().second;
        if(b[x]==b[y]||c[x]==c[z])v[x]=1;
		if(c[y]==c[z]||a[y]==a[x])v[y]=1;
		if(a[z]==a[x]||b[z]==b[y])v[z]=1;
        //if(x==y)v[x]=1;if(x==z)v[x]=1;if(y==z)v[y]=1;
        if(!v[x]&&!v[y]&&!v[z]){
            printf("%d\n",a[x]+b[y]+c[z]);
            return 0;
        }
        while(A.size()&&v[A.top().second])A.pop();
        while(B.size()&&v[B.top().second])B.pop();
        while(C.size()&&v[C.top().second])C.pop();
        //a.pop();b.pop();c.pop();
    }
    printf("-1\n");
}