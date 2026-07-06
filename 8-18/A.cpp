#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e7+100;
int n,fa[N],cnt=0;
pair<int,pii> v[N];
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
int getfa(int x)
{
    if(x==fa[x])return x;
    return (fa[x]=getfa(fa[x]));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            v[++cnt]=make_pair(gcd(i,j),pii(j,i));
        }
    }
    int ans=0;
    sort(v+1,v+1+cnt);
    for(int i=cnt;i>=1;i--)
    {
        int x=v[i].second.first,y=v[i].second.second;
        if(getfa(x)!=getfa(y))
        {
            fa[getfa(x)]=fa[getfa(y)];
            // cout<<x<<","<<y<<":"<<v[i].first<<endl;
            cout<<x<<" "<<y<<" "<<v[i].first<<endl;
            ans+=v[i].first;
        }
        else if(v[i].first==14) cout<<x<<" "<<y<<" "<<v[i].first<<" !!!"<<endl;
    }
    cout<<ans<<endl;
    return 0;
}