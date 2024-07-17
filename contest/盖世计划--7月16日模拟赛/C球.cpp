#include<bits/stdc++.h>
using namespace std;
#define M 200200
struct node{
    int l,r,len;
    int fl,flc,sl;
    int fr,frc,sr;
    int l01,l10;
    int rev;
}tr[4*M+10];
int a[M];
void updata(int p){
    if(tr[p<<1].fl==tr[p<<1].len&&tr[(p<<1)|1].flc==tr[p<<1].flc)
        tr[p].fl=tr[(p<<1)|1].fl+tr[p<<1].fl,tr[p].flc=tr[p<<1].flc;
    else tr[p].fl=tr[p<<1].fl,tr[p].flc=tr[p<<1].flc;

    if(tr[(p<<1)|1].fr==tr[(p<<1)|1].len&&tr[p<<1].frc==tr[p<<1].frc)
        tr[p].fr=tr[(p<<1)|1].fr+tr[p<<1].fr,tr[p].frc=tr[p<<1].frc;
    else tr[p].fr=tr[(p<<1)|1].fr,tr[p].frc=tr[(p<<1)|1].frc;

    if(tr[p<<1].fl==tr[p<<1].len&&tr[(p<<1)|1].flc==tr[p<<1].flc)
        tr[p].sl=tr[(p<<1)|1].sl;
    else if(tr[p<<1].fl==tr[p<<1].len) tr[p].sl=tr[(p<<1)|1].fl;


}
void build(int p,int l,int r){
    tr[p].l=l;
    tr[p].r=r;
    tr[p].len=tr[p].r-tr[p].l+1;
    if(l==r){
        tr[p].len=1;
        tr[p].fl=1;tr[p].flc=a[l];tr[p].sl=0;
        tr[p].fr=1;tr[p].frc=a[l];tr[p].sr=0;
        tr[p].l01=tr[p].l10=0;
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build((p<<1)|1,mid+1,r);
    updata(p);
}
