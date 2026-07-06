#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005;
bitset<N> b[N];
int n,m,q,mx[N],mn[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        mx[i]=-1,mn[i]=n+1;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        mx[x]=max(mx[x],y);
        mn[x]=min(mn[x],y);
        b[x][y]=1;
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=mx[i];j++)
            b[i]|=b[j+1],mx[i]=max(mx[i],mx[j+1]);
        for(int j=i;j<mn[i];j++)
            b[i][j]=0;
        // for(int j=1;j<=n;j++)
        //     cout<<b[i][j]<<" ";
        // cout<<endl;
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(b[l][r])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}