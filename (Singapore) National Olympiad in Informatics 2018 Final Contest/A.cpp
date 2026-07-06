#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,d,k,a[N];
int f(int x,int y)
{
    if(x<1||y<1||x>n||y>m)return 0;
    return (x-1)*m+y;
}
vector<pii> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>d>>k;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='S')
            {
                int x=max(1ll,i-d);
                int y=max(1ll,j-d);
                int xx=min(n,i+d);
                int yy=min(m,j+d);
                // cout<<x<<","<<y<<","<<xx<<","<<yy<<endl;
                a[f(x,y)]++;
                a[f(x,yy+1)]--;
                a[f(xx+1,y)]--;
                a[f(xx+1,yy+1)]++;
            }
            if(s[j-1]=='M')q.push_back(pii(i,j));
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //         cout<<a[f(i,j)]<<" ";
    //     cout<<endl;
    // }
    for(int i=2;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[f(i,j)]+=a[f(i-1,j)];
    for(int i=1;i<=n;i++)
        for(int j=2;j<=m;j++)
            a[f(i,j)]+=a[f(i,j-1)];
    int ans=0;
    for(pii i:q)if(a[f(i.first,i.second)]>=k)ans++;
    cout<<ans<<endl;
    return 0;
}