#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,P=1e9+7;
int n,s[N],f[N][5][5][5],sum[5][5];
inline void add(int &x,int &y)
{
    x=(x+y+P)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;cin>>t;
    n=t.length();t=" "+t;
    for(int i=1;i<=n;i++)
    {
        if(t[i]=='A')s[i]=1;
        if(t[i]=='C')s[i]=2;
        if(t[i]=='G')s[i]=3;
        if(t[i]=='T')s[i]=4;
        if(t[i]=='?')s[i]=0;
    }
    if(s[1])for(int x=1;x<=4;x++)f[1][x][s[1]][s[1]]=1;
    else for(int x=1;x<=4;x++)for(int y=1;y<=4;y++)f[1][x][y][y]=1;
    for(int i=1;i<=n;i++)
    {
        for(int x=1;x<=4;x++)
        {
            for(int y=1;y<=4;y++)
            {
                for(int z=1;z<=4;z++)
                {
                    if(s[i]&&s[i]!=z)continue;
                    for(int c=1;c<=4;c++)
                    {
                        if(c==z)continue;
                        add(f[i][x][y][z],f[i-1][x][y][c]);
                    }
                    if(y!=z)continue;
                    for(int c=1;c<=4;c++)
                    {
                        if(s[i-1]&&s[i-1]!=c)continue;
                        add(f[i][x][y][z],f[i-1][c][x][c]);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int x=1;x<=4;x++)for(int y=1;y<=4;y++)
        add(ans,f[n][x][y][x]);
    cout<<ans<<endl;
    return 0;
}