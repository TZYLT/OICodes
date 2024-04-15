#include<bits/stdc++.h>
using namespace std;

struct Complex{
    double r,i;
    Complex(){r=0;i=0;}
    Complex(double x,double y):r(x),i(y){}
    friend Complex operator+(Complex a,Complex b){return Complex(a.r+b.r,a.i+b.i);}
    friend Complex operator-(Complex a,Complex b){return Complex(a.r-b.r,a.i-b.i);}
    friend Complex operator*(Complex a,Complex b){return Complex(a.r*b.r-a.i*b.i,a.i*b.r+a.r*b.i);}
};
const double pi=acos((double)-1);
int rev[1<<22],len,lim;
void FFT(Complex* a,int opt){
    len=__lg(lim);
    for(int i=0;i<lim;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
    for(int i=0;i<lim;++i)
        if(i<rev[i])
            swap(a[i],a[rev[i]]);
    for(int i=1;i<=len;i++){
        int m=1<<i;
        Complex wn=Complex(cos(2.0*pi/m),opt*sin(2.0*pi/m));
        for(int k=0;k<lim;k+=m){
            Complex w=Complex(1,0);
            for(int j=0;j<m/2;++j){
                Complex t=w*a[k+j+m/2];
                Complex u=a[k+j];
                a[k+j]=u+t;
                a[k+j+m/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(opt==-1)
        for(int i=0;i<lim;i++)
            a[i].r=a[i].r/lim;
}
string a,b;
Complex f[1<<22],g[1<<22];
long long ans[1<<22];
int main(){
    cin>>a;
    cin>>b;
    lim=1<<(__lg(a.size()+b.size()+10)+1);
    for(int i=0;i<a.size();i++)
        f[a.size()-i].r=a[i]-'0';
    for(int i=0;i<b.size();i++)
        g[b.size()-i].r=b[i]-'0';
    FFT(f,1);
    FFT(g,1);
    for(int i=0;i<lim;i++)
        f[i]=f[i]*g[i];
    FFT(f,-1);
    for(int i=0;i<=a.size()+b.size();i++)
        ans[i]=(long long)(f[i].r+0.5);
    for(int i=0;i<=a.size()+b.size();i++)
        ans[i+1]+=ans[i]/10,ans[i]%=10;
    for(int i=a.size()+b.size()+1;i>=2;i--)
        if(i==a.size()+b.size()+1&&ans[i]==0)continue;
        else printf("%lld",ans[i]);
}