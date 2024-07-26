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

void add(int x,string &s){
    vector<int> path;
    path.push_back(x);
    while(x){x=tr[x].fa;path.push_back(x);}
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
            now=tr[now].son[s[i]-'a'];
        }else {
            tr[now].son[s[i]-'a']=++tot;
            tr[tot].fa=now;
            tr[tot].dep=tr[now].dep+1;
            now=tot;
        }
    }
    id[++n]=now;
}
long long ask(int x){
    vector<int> path;
    int a=x;
    path.push_back(x);
    while(x){x=tr[x].fa;path.push_back(x);}
    for(int i=path.size()-1;i>=0;i--){
        for(int j=0;j<=26;j++)
            if(tr[path[i]].son[j]){
                tr[tr[path[i]].son[j]].sum+=tr[path[i]].add;
                tr[tr[path[i]].son[j]].add+=tr[path[i]].add;
            }
        tr[path[i]].add=0;
    }
    return tr[a].sum;
}
void sol1(void){
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int i,k,x;
            cin>>i>>k>>x;
            change(getfa(id[i],tr[id[i]].dep-k),x);
        }else if(op==2){
            int i,k;
            string t;
            cin>>i>>k>>t;
            add(getfa(id[i],tr[id[i]].dep-k),t);
        }else {
            int i;
            cin>>i;
            cout<<ask(id[i])<<endl;
        }
    }
}
int main(){
    freopen("book2.in","r",stdin);
    freopen("book.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        insert(s,i);
    }
    sol1();
}