#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int a[N],b[N];
void solve()
{
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]==-1)cnt++;
    }
    if(cnt!=n)
    {
        int tag=1,tot=-1;
        for(int i=1;i<=n;i++)
            if(b[i]!=-1)
                tot=a[i]+b[i];
        for(int i=1;i<=n;i++)
        {
            if(b[i]!=-1)
            {
                if(a[i]+b[i]!=tot)
                {
                    cout<<"0"<<endl;
                    return;
                }
            }
            else if(tot-a[i]>k||tot-a[i]<0)
            {
                cout<<"0"<<endl;
                return ;
            }
        }
        cout<<"1"<<endl;
        return ;
    }
    else
    {
        int mx=0,mn=1e10;
        for(int i=1;i<=n;i++)
            mx=max(mx,a[i]),
            mn=min(mn,a[i]);
        cout<<(mn+k-mx+1)<<endl;
        return ;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}