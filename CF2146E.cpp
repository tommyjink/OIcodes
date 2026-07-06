
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300010],b[1200010],t[1200010];
int fl(int x){return x<<1;}
int fr(int x){return x<<1|1;}
void pu(int x){b[x]=max(b[fl(x)],b[fr(x)])+t[x];}
void bd(int x,int l,int r){
    if(l==r){b[x]=t[x]=0;return;}
    int m=(l+r)>>1;
    bd(fl(x),l,m);bd(fr(x),m+1,r);pu(x);
}
void md(int x,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr){t[x]++;b[x]++;return;}
    int m=(l+r)>>1;
    if(ql<=m)md(fl(x),l,m,ql,qr);
    if(m<qr)md(fr(x),m+1,r,ql,qr);
    pu(x);
}
void up(int x,int l,int r,int p,int v){
    if(l==r){b[x]=-v;return;}
    v+=t[x];
    int m=(l+r)>>1;
    if(m>=p)up(fl(x),l,m,p,v);
    else up(fr(x),m+1,r,p,v);
    pu(x);
}
signed main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=1;i<=n*4;i++)b[i]=t[i]=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        bd(1,0,n+1);
        for(int i=1;i<=n;i++){
            md(1,0,n+1,0,a[i]);
            up(1,0,n+1,a[i],0);
            cout<<b[1]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}

