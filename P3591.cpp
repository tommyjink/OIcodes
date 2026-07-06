
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+5,B=223*20,K=N/B+1;
int sum[B][K][K],val[N],a[N],n;
inline int R(int b){return b*K;}
inline int L(int b){return R(b-1)+1;}
inline int bl(int x){return (x-1)/K+1;}
int dfn[N],fa[N],dep[N],sz[N],son[N],top[N];
vector<int> G[N];
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') f=-1,ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void dfs1(int u,int f){
    fa[u]=f;dep[u]=dep[f]+1;sz[u]=1;
    for(int v:G[u]) if(v!=f){
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t){
    static int clk=0;
    top[u]=t;dfn[u]=++clk;
    if(son[u]) dfs2(son[u],t);
    for(int v:G[u]) if(v!=fa[u]&&v!=son[u]) dfs2(v,v);
}
int get_sum(int l,int r,int k,int m){
    if(!m) m=k;
    int res=0;
    for(int i=l+m-1;i<=r;i+=k) res+=val[i];
    return res;
}
int block_query(int l,int r,int k,int m){
    if(bl(l)==bl(r)) return get_sum(l,r,k,m);
    int res=get_sum(l,R(bl(l)),k,m);
    m=(m+k-(R(bl(l))-l+1)%k)%k;
    for(int i=bl(l)+1;i<bl(r);++i){
        if(k>=K){
            if(k==K&&m==0) res+=val[R(i)];
            else if(m<=K&&m) res+=val[L(i)+m-1];
        }else res+=sum[i][k][m];
        m=(m+k-K%k)%k;
    }
    res+=get_sum(L(bl(r)),r,k,m);
    return res;
}
int tree_query(int u,int v,int k){
    int wu=1%k,wv=1%k,ans=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v),swap(wu,wv);
        ans+=block_query(dfn[u],dfn[top[u]],k,wu);
        wu=(wu+k-(dfn[top[u]]-dfn[u]+1)%k)%k;
        u=fa[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v),swap(wu,wv);
    ans+=block_query(dfn[u],dfn[v],k,wu);
    return ans;
}
int main(){
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<n;++i){
        int u=read(),v=read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0);dfs2(1,1);
    for(int i=1;i<=n;++i) dfn[i]=n-dfn[i]+1;
    for(int i=1;i<=n;++i) val[dfn[i]]=a[i];
    for(int k=1;k<K;++k)
        for(int i=2;i<bl(n);++i)
            for(int j=L(i);j<=R(i);++j)
                sum[i][k][(j-L(i)+1)%k]+=val[j];
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<n;++i){
        int w=read();
        printf("%d\n",tree_query(a[i],a[i+1],w));
    }
    return 0;
}
