#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3;
int n,m,k[N],p[N],ans=0;
map<int,int> mp;
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x;
        y>>=1;
        x*=x;
    }
    return res;
}
void dfs(int l,int r,int val,int mode)
{
    if(l>r)
    {
        if(mode)
            mp[val]++;
        else ans+=mp[-val];
        return;
    }
    for(int i=1;i<=m;i++)
        dfs(l+1,r,val+k[l]*qpow(i,p[l]),mode);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>k[i]>>p[i];
    dfs(1,n/2,0,true);
    dfs(n/2+1,n,0,false);
    cout<<ans<<endl;
    return 0;
}