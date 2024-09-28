#include<bits/stdc++.h>
using namespace std;
#define C 2000400
int l[C],r[C];int X[C];
long long sum[C],len[C];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        sum[p]=0;
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
}
void pushup(int p){
    if(sum[p]) len[p]=X[r[p]+1]-X[l[p]];
    else len[p]=len[p<<1]+len[(p<<1)|1];
}
void change(int p,int li,int ri,int d){
    if(X[r[p]+1]<=li||ri<=X[l[p]])return;
    if(li<=X[l[p]]&&ri>=X[r[p]+1]){
        sum[p]+=d;
        pushup(p);
        return; 
    }
    int mid=(l[p]+r[p])/2;
    change(p*2,li,ri,d);
    change(p*2+1,li,ri,d);
    pushup(p);
}

int n;
struct Sline{
    int x1,x2,h,opt;
    friend bool operator<(Sline x,Sline y){return x.h<y.h;}
    
}line[C];
int k;
int x,y;
int main(){
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++){
        int a,b,c,d;
        int t;char cc;
        cin>>cc>>t;
        //printf("%c %d\n",cc,t);
        if(cc=='N'){
            a=x;b=y;c=x+k;d=y+k+t;
            y+=t;
        }else if(cc=='E'){
            a=x;b=y;c=x+k+t;d=y+k;
            x+=t;
        }else if(cc=='W'){
            a=x-t;b=y;c=x+k;d=y+k;
            x-=t;
        }else if(cc=='S'){
            a=x;b=y-t;c=x+k;d=y+k;
            y-=t;
        }

        X[(i<<1)-1]=a;X[i<<1]=c;
        line[(i<<1)-1]={a,c,b,1};line[i<<1]={a,c,d,-1};
    }
    for(int i=n+1;i<=n+1;i++){
        int a,b,c,d;
        a=0;b=0;c=k;d=k;
        X[(i<<1)-1]=a;X[i<<1]=c;
        line[(i<<1)-1]={a,c,b,1};line[i<<1]={a,c,d,-1};
    }
    n++;
    n*=2;
    sort(line+1,line+1+n);
    sort(X+1,X+1+n);
    int tot=unique(X+1,X+1+n)-X-1;
    build(1,1,tot-1);
    long long ans=0;
    for(int i=1;i<n;i++){
        change(1,line[i].x1,line[i].x2,line[i].opt);
        ans+=1ll*len[1]*(line[i+1].h-line[i].h);
    }
    printf("%lld\n",ans);
}
