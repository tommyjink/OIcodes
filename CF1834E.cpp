#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;

const int N=5e6+10;

int t,n,tot1,tot2;
int f[100],g[100],tag[N];

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    for(int T=1;T<=t;T++)
    {
        cin>>n;
        tot1=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            tot2=0;
            if(x<N)g[++tot2]=x;
            for(int j=1;j<=tot1;j++)
            {
                int y=f[j]/gcd(f[j],x)*x;
                if(y<N&&(tot2==0||g[tot2]!=y))g[++tot2]=y;
            }
            tot1=tot2;
            for(int j=1;j<=tot1;j++)
            {
                f[j]=g[j];
                tag[f[j]]=T;
            }
        }
        int ans=1;
        while(tag[ans]==T)ans++;
        cout<<ans<<endl;
    }
    return 0;
}
