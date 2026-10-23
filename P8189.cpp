#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=20,M=(1<<18)+10;
int n,a[N],f[M],g[M],r[M][N];
int e[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int p=1;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
            if(a[j]==i)p=j;
        }
        for(int j=1;j<=p;j++)
            e[a[j]][i]=1;
    }
    for(int i=1;i<=n;i++)
        r[1<<(i-1)][i]=1;
    f[0]=1;
    for(int s=1;s<(1<<n);s++)
    {
        int x=n;
        for(int i=1;i<=n;i++)
            if(s&(1<<(i-1)))
                x=min(x,i);
        for(int i=x;i<=n;i++)
        {
            if(!(s&(1<<(i-1))))continue;
            for(int j=x;j<=n;j++)
            {
                if(s&(1<<(j-1)))continue;
                if(e[i][j])r[s|(1<<(j-1))][j]+=r[s][i];
            }
            if(e[i][x])g[s]+=r[s][i];
        }
        for(int t=s;t;t=(t-1)&s)
            if(t&(1<<(x-1)))
                f[s]+=g[t]*f[s^t];
        // for(int i=1;i<=n;i++)
        //     if(s&(1<<(i-1)))cout<<i<<" ";
        // cout<<":"<<g[s]<<endl;
    }
    int q;cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        s=" "+s;
        int now=0;
        for(int i=1;i<=n;i++)
            if(s[i]=='H')now^=(1<<(i-1));
        cout<<f[now]*f[((1<<n)-1)^now]<<endl;
    }
    return 0;
}