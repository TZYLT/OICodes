#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,s,t,now=0;
    scanf("%d%d%d",&m,&s,&t);
    int ans1=0,ans2=0;
    for(int i=1;i<=t;i++)
    {
        ans1+=17;#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,s,t,now=0;
    scanf("%d%d%d",&m,&s,&t);
    int ans1=0,ans2=0;
    for(int i=1;i<=t;i++)
    {
        ans1+=17;
        if(m>=10) {
            ans2+=60;
            m-=10;
        }
        else m+=4;
        if(ans2>ans1) ans1=ans2;
        if(ans1>s){
            printf("Yes\n%d\n",i);
            return 0;
        }
    }
    printf("Yes\n%d\n",ans1);
}
        if(m>=10) {
            ans2+=60;
            m-=10;
        }
        else m+=4;
        if(ans2>ans1) ans1=ans2;
        if(ans1>s){
            printf("Yes\n%d\n",i);
            return 0;
        }
    }
    printf("Yes\n%d\n",ans1);
}