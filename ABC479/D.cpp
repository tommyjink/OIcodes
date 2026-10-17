#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e18;
int n,q;
int l[N],r[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=2;i<=n;i++)
        cin>>l[i];
    l[0]=INF;
    for(int i=1;i<=n-1;i++)
        cin>>r[i];
    r[n]=INF;
    int mn=INF;
    for(int i=1;i<=n;i++)
    {
        r[i]=min(r[i],l[i]+mn);
        mn=min(mn,r[i]);
        // cout<<r[i]<<" ";
    }
    // cout<<endl;
    mn=INF;
    for(int i=n;i>=1;i--)
    {
        l[i]=min(l[i],r[i]+mn);
        mn=min(mn,l[i]);
    }
    // for(int i=1;i<=n;i++)
    //     cout<<l[i]<<" ";
    // cout<<endl;
    while(q--)
    {
        int s,t;
        cin>>s>>t;
        if(s>t)cout<<l[s]<<endl;
        else cout<<r[s]<<endl;
    }
    return 0;
}