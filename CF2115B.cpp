#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N],x[N],y[N],z[N],b[N],c[N];
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i];
    for(int i=1;i<=q;i++)
        cin>>x[i]>>y[i]>>z[i];
    for(int i=q;i>=1;i--)
    {
        a[x[i]]=max(a[x[i]],a[z[i]]);
        a[y[i]]=max(a[y[i]],a[z[i]]);
        if(x[i]!=z[i]&&y[i]!=z[i])a[z[i]]=0;
    }
    for(int i=1;i<=n;i++)c[i]=a[i];
    for(int i=1;i<=q;i++)
        a[z[i]]=min(a[x[i]],a[y[i]]);
    for(int i=1;i<=n;i++)
        if(a[i]!=b[i])
        {
            cout<<"-1"<<endl;
            return;
        }
    for(int i=1;i<=n;i++)
        cout<<c[i]<<" ";
    cout<<endl;
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}