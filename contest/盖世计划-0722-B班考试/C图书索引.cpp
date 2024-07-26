#include<bits/stdc++.h>
using namespace std;
#define M 600600
struct node{
    int son[27];
    long long add,sum;
    int dep,fa;
}tr[M];
int tot;
int id[M];
int n,q;
void insert(string &s,int x){
    int now=0;
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else {
            tr[now].son[s[i]-'a']=++tot;
            tr[tot].fa=now;
            tr[tot].dep=tr[now].dep+1;
            now=tot;
        }
    }
    id[x]=now;
}
int getfa(int x,int k){
    while(k>0){x=tr[x].fa;k--;}
    return x;
}
void change(int x,long long d){
    tr[x].sum+=d;
    tr[x].add+=d;
}
vector<int> path;
void add(int x,string &s){
    path.clear();
    while(x){path.push_back(x);x=tr[x].fa;}
    //cout<<"sb"<<endl;
    for(int i=path.size()-1;i>=0;i--){
        for(int j=0;j<=26;j++)
            if(tr[path[i]].son[j]){
                tr[tr[path[i]].son[j]].sum+=tr[path[i]].add;
                tr[tr[path[i]].son[j]].add+=tr[path[i]].add;
            }
        tr[path[i]].add=0;
    }
    
    int now=path[0];
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a']){
            for(int j=0;j<=26;j++)
            if(tr[tr[now].son[s[i]-'a']].son[j]){
                tr[tr[tr[now].son[s[i]-'a']].son[j]].sum+=tr[tr[now].son[s[i]-'a']].add;
                tr[tr[tr[now].son[s[i]-'a']].son[j]].add+=tr[tr[now].son[s[i]-'a']].add;
            }
            tr[tr[now].son[s[i]-'a']].add=0;
        }else break;
    }
    now=path[0];
    for(int i=0;i<s.size();i++){
        if(tr[now].son[s[i]-'a'])now=tr[now].son[s[i]-'a'];
        else {
            tr[now].son[s[i]-'a']=++tot;
            tr[tot].fa=now;
            tr[tot].dep=tr[now].dep+1;
            now=tot;
        }
    }
    id[++n]=now;
}
long long ask(int x){
    path.clear();int a=x;
    while(x){path.push_back(x),x=tr[x].fa;}
    for(int i=path.size()-1;i>=0;i--){
        //cout<<'['<<path[i]<<']'<<':'<<tr
        for(int j=0;j<=26;j++)
            if(tr[path[i]].son[j]){
                tr[tr[path[i]].son[j]].sum+=tr[path[i]].add;
                tr[tr[path[i]].son[j]].add+=tr[path[i]].add;
            }
        tr[path[i]].add=0;
    }
    return tr[a].sum;
}
struct qs{
    int op,i,k,x;
    string t;
}qt[M];
void sol1(void){
    for(int i=1;i<=q;i++){
        if(qt[i].op==1){
            change(getfa(id[qt[i].i],tr[id[qt[i].i]].dep-qt[i].k),qt[i].x);
        }else if(qt[i].op==2){
            add(getfa(id[qt[i].i],tr[id[qt[i].i]].dep-qt[i].k),qt[i].t);
        }else {
            cout<<ask(id[qt[i].i])<<endl;
        }
    }
}

int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
void sol2(void){

}
int main(){
    double st=clock();
    freopen("book3.in","r",stdin);
    freopen("book.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        insert(s,i);
    }
    cin>>q;
    int f=1;
    for(int i=1;i<=q;i++){
        cin>>qt[i].op;
        if(qt[i].op==1)cin>>qt[i].i>>qt[i].k>>qt[i].x;
        else if(qt[i].op==2)cin>>qt[i].i>>qt[i].k>>qt[i].t;
        else cin>>qt[i].i;
        if(qt[i].op==2)f=0;
    }
    if(f==0)sol1();
    else sol2();
    cerr<<clock()-st;
}