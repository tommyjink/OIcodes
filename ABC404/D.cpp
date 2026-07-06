#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=500,M=300;
int n,m,c[N],k[M],ans=1e15;
vector<int> a[M];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>c[i],c[i+n]=c[i];
    for(int i=1;i<=m;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x;
            cin>>x;
            a[i].push_back(x);
            a[i].push_back(x+n);
        }
    }
    n*=2;
    for(int i=0;i<(1ll<<n);i++)
    {
        int val=0;
        for(int j=1;j<=n;j++)
            if(i&(1ll<<(j-1)))
                val+=c[j];
        int tag=1;
        for(int j=1;j<=m;j++)
        {
            int res=0;
            for(auto ii:a[j])
                if(i&(1ll<<(ii-1)))
                    res++;
            if(res<2)tag=0;
        }
        if(!tag)continue;
        ans=min(ans,val);
    }
    cout<<ans<<endl;
    return 0;
}