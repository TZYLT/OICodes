#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int f[2020],v[2020],in[2020],out[2020];
bool si[2020],so[2020];
int n,m,q;

int head[505000],nextt[505000],ver[505000],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char *p1,*p2,buf[(1<<20)+5];
inline int read(){
	int x=0;
	char c=gc();
	while(!isdigit(c)){
		c=gc();
	}while(isdigit(c)){
		x=x*10+(c^48);
		c=gc();
	}return x;
}
inline void print(long long x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
inline void mod(int &a){
    a=(a>=p?a-p:a);
}
int main(){
    double st=clock();
    freopen("ex_graph3.in","r",stdin);
    freopen("1.out","w",stdout);
    n=read(),m=read(),q=read();
    for(int i=1,x,y;i<=m;i++){
        x=read();
        y=read();
        add(x,y);
        out[x]++;
        in[y]++;
    }
    for(int i=1;i<=n;i++)
        si[i]=in[i]==0,so[i]=out[i]==0;
    while(q--){
        for(int i=1;i<=n;i++)
            f[i]=v[i]=0;
        int k=read();
        for(int i=1;i<=k;i++)
            v[read()]=1;
           
        int ans=0;
        for(int i=1;i<=n;i++)
            if(v[i]==0){
                if(si[i])f[i]=1;

                for(int j=head[i];j;j=nextt[j])
                    if(v[ver[j]]==0)
                        f[ver[j]]=f[ver[j]]+f[i],mod(f[ver[j]]);
                
                if(so[i])
                    ans=ans+f[i],mod(ans);
            }
        print(ans);
        putchar('\n');
    }
    cerr<<clock()-st;
}