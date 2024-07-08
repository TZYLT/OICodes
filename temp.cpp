void dfsI(int x,int ine){
    s++;
    low[x]=dfn[x]=s;
    for(int i=head[x];i;i=nextt[i]){
        if(i!=ine){
            if(!dfn[ver[i]]){
                dfsI(ver[i],i^1);
                low[x]=min(low[x],low[ver[i]]);
                if(low[ver[i]]>dfn[x]) 
                    bridge[i]=bridge[i^1]=1;
            }
            else low[x]=min(low[x],dfn[ver[i]]);
        }
    }
}
void dfs(int x,int fa){
    dfn[x]=low[x]=++id;
    st[++h]=x;
    int son=0;
    for(int i=head[x];i;i=nextt[i]){
        if(ver[i]!=fa){
            if(dfn[ver[i]]==0){
                ++son;
                dfs(ver[i],x);
                low[x]=min(low[x],low[ver[i]]);
                if(low[ver[i]]>=dfn[x]){
                    ++c;
                    while(st[h]!=ver[i]){
                        ans[c].push_back(st[h]);
                        h--;
                    }
                    ans[c].push_back(ver[i]);
                    h--;
                    ans[c].push_back(x);
                }
            }
            else low[x]=min(low[x],dfn[ver[i]]);
        }   
    } 
    if(son==0&&fa==0)ans[++c].push_back(x);
}
