#include<bits/stdc++.h>
using namespace std;


// int v[M],d[M];
// priority_queue<pair<int,int> > q;
// void dijkstra(){
//     memset(d,0x3f,sizeof(d));
//     memset(v,0,sizeof(v));
//     d[s]=0;
//     q.push(make_pair(0,s));
//     while(q.size()){
//         int x=q.top().second;
//         q.pop();
//         if(v[x])continue;
//         v[x]=1;
//         for(int i=head[x];i;i=nextt[i]){
//             int y=ver[i],z=wei[i];
//             if(d[y]>d[x]+z){
//                 d[y]=d[x]+z;
//                 q.push(make_pair(-d[y],y));
//             }
//         }
//     }
// }
