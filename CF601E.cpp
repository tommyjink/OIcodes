
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e4+5,M=1e3+5;
int n,k,q,op[N],L[N],R[N];
pair<int,int>a[N];
vector<pair<int,int>>t[N<<2];
ll st[N][M],ans[N];
int tp;
#define ls (x<<1)
#define rs (x<<1|1)
inline void upd(int x,int l,int r,int L,int R,pair<int,int>v){
    if(l>=L&&r<=R){
        t[x].push_back(v);
        return;
    }
    int m=l+r>>1;
    if(L<=m)upd(ls,l,m,L,R,v);
    if(R>m)upd(rs,m+1,r,L,R,v);
}
const ll p=1e7+19,mod=1e9+7;
inline void qry(int x,int l,int r){
    int tp0=tp;
    for(auto nw:t[x]){
        ++tp;
        for(int i=1;i<=k;++i)st[tp][i]=max(st[tp-1][i],i>=nw.second?st[tp-1][i-nw.second]+nw.first:0ll);
    }
    int m=l+r>>1;
    if(l==r){
        if(op[l]==3){
            ll fac=1;
            for(int m=1;m<=k;++m){
                ans[l]=(ans[l]+st[tp][m]*fac%mod)%mod;
                fac=fac*p%mod;
            }
        }
        goto brk;
    }
    qry(ls,l,m);
    qry(rs,m+1,r);
    brk:;
    while(tp!=tp0)--tp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i].first>>a[i].second;
    cin>>q;
    for(int i=1;i<=n;++i)L[i]=1,R[i]=q;
    for(int i=1;i<=q;++i){
        cin>>op[i];
        if(op[i]==1){
            ++n;
            cin>>a[n].first>>a[n].second;
            L[n]=i;R[n]=q;
        }
        if(op[i]==2){
            int x;cin>>x;R[x]=i;
        }
    }
    for(int i=1;i<=n;++i)upd(1,1,q,L[i],R[i],a[i]);
    qry(1,1,q);
    for(int i=1;i<=q;++i)if(op[i]==3)cout<<ans[i]<<'\n';
    return 0;
}
