#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e3+10;
int n,m,k,len,t[N][N];
vector<pii> d; 
void add(int x,int y,int xx,int yy)
{
    x=max(x,1ll);
    y=max(y,1ll);
    xx=min(xx,n);
    yy=min(yy,m);
    t[x][y]++;
    t[x][yy+1]--;
    t[xx+1][y]--;
    t[xx+1][yy+1]++;
}
void init()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            t[i][j]+=t[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            t[i][j]+=t[i-1][j];
}
void solve()
{
    d.clear();
    cin>>n>>m>>k;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)
            t[i][j]=0;
    string s;cin>>s;
    len=s.length();
    pii now(0,0);
    d.push_back(now);
    int lx=0,ly=0,rx=0,ry=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='U')now.first--;
        if(s[i]=='D')now.first++;
        if(s[i]=='L')now.second--;
        if(s[i]=='R')now.second++;
        d.push_back(now);
        lx=min(lx,now.first);
        ly=min(ly,now.second);
        rx=max(rx,now.first);
        ry=max(ry,now.second);
    }
    lx=1-lx,rx=n-rx;
    ly=1-ly,ry=m-ry;
    // cout<<lx<<","<<ly<<","<<rx<<","<<ry<<endl;
    if(lx>rx||ly>ry)
    {
        if(k==0)cout<<n*m<<endl;
        else cout<<"0"<<endl;
        return;
    }
    int sum=(rx-lx+1)*(ry-ly+1);
    sort(d.begin(),d.end());
    d.erase(unique(d.begin(),d.end()),d.end());
    for(auto now:d)
    {
        int x=lx+now.first,y=ly+now.second;
        int xx=rx+now.first,yy=ry+now.second;
        add(x,y,xx,yy);
    }
    init();
    int ans=0;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //         cout<<t[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(sum-t[i][j]==k)ans++;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}