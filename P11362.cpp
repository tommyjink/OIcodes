#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,l,m,v,c[N],dp[N];
map<int,int> mp;
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
void solve()
{
    mp.clear();
    cin>>l>>m>>v;
    int tag=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(mp.count(x)&&mp[x]!=y)
            tag=true;
        mp[x]=y;
        c[i]=x;
    }
    if(tag)
    {
        cout<<"0"<<endl;
        return;
    }
    sort(c+1,c+1+m);
    n=unique(c+1,c+1+m)-c-1;
    dp[1]=qpow(v,c[1]*2-2);
    for(int i=2;i<=n;i++)
    {
        int now=qpow(v,2*(c[i]-c[i-1]));
        now=((now-(v-1)*qpow(v,c[i]-c[i-1]-1)%P)%P+P)%P;
        dp[i]=dp[i-1]*now%P;
    }
    cout<<dp[n]*qpow(v,2*l-2*c[n])%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}