
#include<bits/stdc++.h>
#define N 500010
using namespace std;
int n,m,tot;
int cnt[N],book[N],fa[N][21],de[N],len[N],book2[N],step[N];
vector<int>e[N];
queue<int>q;
void dfs(int u,int f,int rt,int d){
    de[u]=d;book[u]=rt;
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(cnt[v]||v==f)continue;
        dfs(v,u,rt,d+1);
    }
}
void pre(){
    for(int p=1;p<=19;p++)
        for(int i=1;i<=n;i++)
            fa[i][p]=fa[fa[i][p-1]][p-1];
}
int lca(int x,int y){
    if(de[x]<de[y])swap(x,y);
    int tmp=de[x]-de[y];
    for(int i=19;i>=0;i--)if(tmp>>i&1)x=fa[x][i];
    if(x==y)return y;
    for(int i=19;i>=0;i--){
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}
void doit(int u,int id,int az){
    if(step[u])return;
    book2[u]=id;len[id]++;step[u]=az;
    doit(fa[u][0],id,az+1);
}
bool check(int a,int b,int c,int d){
    if(max(a,b)!=max(c,d))return max(a,b)<max(c,d);
    if(min(a,b)!=min(c,d))return min(a,b)<min(c,d);
    return a>=b;
}
signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int u;scanf("%d",&u);
        e[u].push_back(i);
        fa[i][0]=u;
        cnt[u]++;
    }
    for(int i=1;i<=n;i++)if(!cnt[i])q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        int v=fa[u][0];
        cnt[v]--;
        if(!cnt[v])q.push(v);
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]){
            dfs(i,0,i,0);
            if(!step[i])doit(i,++tot,1);
        }
    }
    pre();
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        if(book2[book[u]]!=book2[book[v]]){
            printf("-1 -1\n");
        }else if(book[u]==book[v]){
            int LCA=lca(u,v);
            printf("%d %d\n",de[u]-de[LCA],de[v]-de[LCA]);
        }else{
            int t1=book[u],t2=book[v];
            int ans1=de[u]+(step[t2]-step[t1]+len[book2[t1]])%len[book2[t1]],ans2=de[v]+(step[t1]-step[t2]+len[book2[t1]])%len[book2[t1]];
            if(check(de[u],ans2,ans1,de[v]))printf("%d %d\n",de[u],ans2);
            else printf("%d %d\n",ans1,de[v]);
        }
    }
    return 0;
}
