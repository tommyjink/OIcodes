#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=25,M=2e5+100,NN=2e6+10;
int n,q,tag[N],b[N],g[N][N],f[NN][N];
pii op[M];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        int x;char y;
        cin>>x>>y;
        op[i]=pii(x,y=='+');
        tag[x]+=op[i].second;
        b[x]=max(b[x],tag[x]);
    }
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=n;y++)
        {
            if(x==y)continue;
            int rx=0,ly=1,now=1;
            for(int i=1;i<=q;i++)
            {
                if(op[i].first==x&&op[i].second==1)rx++;
                if(op[i].first==y&&op[i].second==0)ly++;
                while(rx>=ly)ly++,now++;
            }
            g[x][y]=now-tag[x];
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //         cout<<g[i][j]<<" ";
    //     cout<<endl;
    // }
    memset(f,63,sizeof(f));
    for(int i=1;i<=n;i++)
        f[1ll<<(i-1)][i]=tag[i]+1;
    for(int i=0;i<(1ll<<n)-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!(i&(1ll<<(j-1))))continue;
            for(int k=1;k<=n;k++)
            {
                if(i&(1ll<<(k-1)))continue;
                int ii=(i|(1ll<<(k-1)));
                f[ii][k]=min(f[ii][k],f[i][j]+g[j][k]+tag[k]);
            }
        }
    }
    int ans=1e15;
    for(int i=1;i<=n;i++)
        ans=min(ans,f[(1ll<<n)-1][i]);
    cout<<ans<<endl;
    return 0;
}