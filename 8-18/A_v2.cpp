#include <bits/stdc++.h>
using namespace std;

const int N=1e7+10;
int n, fa[N], sz[N], tot, pcnt, pri[N];
long long ans;
bool np[N];

int find(int x) {
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

bool merge(int x,int y) {
    int fx=find(x),fy=find(y);
    if(fx==fy) return 0;
    if(sz[fx]<sz[fy]) swap(fx,fy);
    fa[fy]=fx; sz[fx]+=sz[fy];
    return 1;
}

signed main() {
    cin>>n;
    tot=n-1;
    for(int i=2;i<=n;i++) {
        if(!np[i]) pri[++pcnt]=i;
        for(int j=1;j<=pcnt&&1ll*i*pri[j]<=n;j++) {
            np[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    for(int i=n/2;i>=2;i--) {
        for(int j=1;pri[j]<=n/i;j++) {
            if(merge(i,i*pri[j])) ans+=i,--tot;
        }
    }
    ans+=tot;
    cout<<ans<<endl;
    return 0;
}
