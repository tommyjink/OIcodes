#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,k,t[N],fa[N];
set<int> s;
int getfa(int x)
{
    return x==fa[x]?x:(fa[x]=getfa(fa[x]));
}
bool merge(int x,int y)
{
    x=getfa(x),y=getfa(y);
    if(x==y)return false;
    fa[x]=y;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>t[i],t[i]%=k;
    int cnt=0;
    while(cnt<n-1)
    {
        for(int x=1;x<=n;x++)
        {
            
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
} 