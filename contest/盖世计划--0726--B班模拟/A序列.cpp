#include<bits/stdc++.h>
using namespace std;
#define M 5050
int cost[M][M],a[M];
int n;
vector<pair<int,int> > odd,even;
vector<int> ansl,ansr;
void cal(int st,vector<pair<int,int> > &tk,vector<int> &ans){
    memset(cost,0,sizeof cost);
    for(int j=0;j<tk.size();j++)
        for(int i=1;i<=tk.size();i++)
            cost[j+1][i]=abs(tk[j].second-((i-1)*2+st));
    for(int j=0;j<tk.size();j++)tk[j].second=j+1;
    // for(int j=0;j<tk.size();j++){
    //     for(int i=1;i<=tk.size();i++)
    //         printf("%d ",cost[j+1][i]);
    //     printf("\n");
    // }
        
    sort(tk.begin(),tk.end());
    bool v[M]={0};
    for(int i=1;i<=tk.size();i++){
        for(int j=0;j<tk.size();j++)
            if(!v[j])if(cost[i][i]+cost[tk[j].second][tk[j].second]==cost[tk[j].second][i]+cost[i][tk[j].second]){
                ans.push_back(tk[j].first);
                //swap(cost[i],cost[tk[j].second]);
                v[j]=1;
                //swap(v[j],v[])
                break;    
            }
    }
}
long long ct1,ct2;
int main(){
    freopen("ex_sequence.in","r",stdin);
    freopen("ex_sequence.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(a[i]&1)odd.push_back(make_pair(a[i],i));
        else even.push_back(make_pair(a[i],i));
    }
    //cal(1,odd);
    //for(auto c:ans)printf("%d ",c);
    //for(int i=(odd.size()>even.size()))

    if(n&1){
        if(odd.size()>even.size()){
            cal(1,odd,ansl);
            cal(2,even,ansr);
            for(int i=1;i<=n;i++)
               if(i&1)printf("%d ",ansl[i/2]);
               else printf("%d ",ansr[(i-1)/2]);
        }else {
            cal(2,odd,ansl);
            cal(1,even,ansr);
            for(int i=1;i<=n;i++)
               if(i&1)printf("%d ",ansr[i/2]);
               else printf("%d ",ansl[(i-1)/2]);
        }
    }else {
        for(int i=1;i<=n;i+=2)
            ct1+=abs(i-odd[i/2].second);
        for(int i=2;i<=n;i+=2)
            ct1+=abs(i-even[(i-1)/2].second);
        for(int i=1;i<=n;i+=2)
            ct2+=abs(i-even[i/2].second);
        for(int i=2;i<=n;i+=2)
            ct1+=abs(i-odd[(i-1)/2].second);
        //printf("[%d %d]",ct1,ct2);
        if(ct1<ct2){
            cal(1,odd,ansl);
            cal(2,even,ansr);
            for(int i=1;i<=n;i++)
               if(i&1)printf("%d ",ansl[i/2]);
               else printf("%d ",ansr[(i-1)/2]);
        }else if(ct1>ct2){
            cal(2,odd,ansl);
            cal(1,even,ansr);
            for(int i=1;i<=n;i++)
               if(i&1)printf("%d ",ansr[i/2]);
               else printf("%d ",ansl[(i-1)/2]);
        }else {
            vector<int> ans1,ans2;
            cal(1,odd,ansl);
            cal(2,even,ansr);
            for(int i=1;i<=n;i++)
               if(i&1)ans1.push_back(ansl[i/2]);
               else ans1.push_back(ansr[(i-1)/2]);
            ansl.clear();
            ansr.clear();
            cal(2,odd,ansl);
            cal(1,even,ansr);
            for(int i=1;i<=n;i++)
               if(i&1)ans2.push_back(ansr[i/2]);
               else ans2.push_back(ansl[(i-1)/2]);
            int f=1;
            for(int i=1;i<=n;i++)
                if(ans1[i-1]>ans2[i-1]){
                    f=2;
                    break;
                }else if(ans1[i-1]<ans2[i-1])break;
            for(int i=1;i<=n;i++)
                if(f==1)printf("%d ",ans1[i-1]);
                else printf("%d ",ans2[i-1]);
        }
    }
}