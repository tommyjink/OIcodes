#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e18;
int n,d[N],cnt=0;
vector<int> x[2],y[2];
int cal1()
{
    cnt=0;
    if(x[0].size()!=y[0].size()||x[1].size()!=y[1].size())
        return INF;
    for(int i=0;i<x[0].size();i++)
        d[++cnt]=x[0][i]-y[0][i];
    for(int i=0;i<x[1].size();i++)
        d[++cnt]=x[1][i]-y[1][i];
    sort(d+1,d+1+cnt);
    int sum=0,res=0;
    for(int i=1;i<=cnt;i++)
    {
        res+=d[i]*(i-1)-sum;
        sum+=d[i];
    }
    return res/2;
}
int cal2()
{
    cnt=0;
    if(x[0].size()!=y[1].size()||x[1].size()!=y[0].size())
        return INF;
    for(int i=0;i<x[0].size();i++)
        d[++cnt]=x[0][i]-y[1][i];
    for(int i=0;i<x[1].size();i++)
        d[++cnt]=x[1][i]-y[0][i];
    sort(d+1,d+1+cnt);
    int sum=0,res=0;
    for(int i=1;i<=cnt;i++)
    {
        res+=d[i]*(i-1)-sum;
        sum+=d[i];
    }
    return res/2;
}
void solve()
{
    cin>>n;
    x[0].clear(),x[1].clear();
    y[0].clear(),y[1].clear();
    for(int i=1;i<=n;i++)
    {
        int c;cin>>c;
        x[(c%2+2)%2].push_back(c);
    }
    for(int i=1;i<=n;i++)
    {
        int c;cin>>c;
        y[(c%2+2)%2].push_back(c);
    }
    sort(x[0].begin(),x[0].end());
    sort(x[1].begin(),x[1].end());
    sort(y[0].begin(),y[0].end());
    sort(y[1].begin(),y[1].end());
    int res=min(cal1(),cal2());
    if(res==INF)cout<<"-1"<<endl;
    else cout<<res<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}