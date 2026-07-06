#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,LOG=19;
const int INF=1e18;
int n,L,T;
vector<tuple<int,int,int,int>> g[N];

int dep[N],anc[N][LOG];
struct Mat{int m[2][2];}upm[N][LOG],dnm[N][LOG];
Mat I(){
    Mat r;
    r.m[0][0]=0;r.m[0][1]=INF;
    r.m[1][0]=INF;r.m[1][1]=0;
    return r;
}
Mat mul(Mat a,Mat b){
    Mat c;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            c.m[i][j]=INF;
            for(int k=0;k<2;k++)
                c.m[i][j]=min(c.m[i][j],a.m[i][k]+b.m[k][j]);
        }
    return c;
}
Mat emat(int w,int s){
    Mat r;
    r.m[0][0]=w;r.m[0][1]=L+s;
    r.m[1][0]=w;r.m[1][1]=s;
    return r;
}
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    anc[u][0]=fa;
    for(auto [v,a,z,tp]:g[u]){
        if(v==fa)continue;
        int sd=(tp==1)?a-z:a+z;
        int su=(tp==0)?a-z:a+z;
        upm[v][0]=emat(a,su);
        dnm[v][0]=emat(a,sd);
        dfs(v,u);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=LOG-1;i>=0;i--)if(d>>i&1)u=anc[u][i];
    if(u==v)return u;
    for(int i=LOG-1;i>=0;i--)if(anc[u][i]!=anc[v][i])u=anc[u][i],v=anc[v][i];
    return anc[u][0];
}
Mat upq(int u,int st){
    Mat r=I();
    for(int i=LOG-1;i>=0;i--)if(st>>i&1)r=mul(r,upm[u][i]),u=anc[u][i];
    return r;
}
Mat dnq(int v,int st){
    vector<pii> se;
    int c=v;
    for(int i=LOG-1;i>=0;i--)if(st>>i&1)se.emplace_back(c,i),c=anc[c][i];
    Mat r=I();
    for(int idx=se.size()-1;idx>=0;idx--){
        auto [nod,bt]=se[idx];
        r=mul(r,dnm[nod][bt]);
    }
    return r;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>L>>T;
    for(int i=1;i<n;i++){
        int x,y,a,z,tp;
        cin>>x>>y>>a>>z>>tp;
        g[x].emplace_back(y,a,z,tp);
        g[y].emplace_back(x,a,z,1-tp);
    }
    for(int i=0;i<=n;i++){
        upm[i][0]=I();
        dnm[i][0]=I();
    }
    dfs(1,0);
    for(int j=1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            anc[i][j]=anc[anc[i][j-1]][j-1];
            upm[i][j]=mul(upm[i][j-1],upm[anc[i][j-1]][j-1]);
            dnm[i][j]=mul(dnm[anc[i][j-1]][j-1],dnm[i][j-1]);
        }
    }
    while(T--){
        int u,v;
        cin>>u>>v;
        int LCA=lca(u,v);
        Mat res=I();
        res=mul(res,upq(u,dep[u]-dep[LCA]));
        res=mul(res,dnq(v,dep[v]-dep[LCA]));
        cout<<min(res.m[0][0],res.m[0][1])<<endl;
    }
    return 0;
}
