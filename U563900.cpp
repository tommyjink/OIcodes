#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1000;
int n,k,f[N][N],d[N][N],cnt=0;
string s[N],t[N];
void dfs(int x,int y)
{
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]=" "+s[i];
    }
    vector<pii> v;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            d[i][j]=i+j-1;
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(s[i][j]!='a')f[i][j]++;
            if(f[i][j]==k)v.emplace_back(pii(i,j));
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    for(auto now:v)
    {
        int x=now.first,y=now.second;
        cnt++;
        for(int i=1;i<=d[n][n]-d[x][y];i++)
        {
            t[cnt].push_back(s[x][y]);

        }
    }
    // int maxx=0,maxy=0;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         if(f[i][j])
    //     }
    // }
    return 0;
}