#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,v[N];
void solve()
{
    int cnt=0,tot=1,now=1;
    cin>>n>>k;
    for(int i=n-1;i>=1;i--)
        if(i*(i-1)/2<=k)
            v[++cnt]=i,k-=i*(i-1)/2;
    if(k>1)
    {
        cout<<"No"<<endl;
        return;
    }
    // cout<<k<<"!"<<endl;
    cout<<"Yes"<<endl;
    v[0]=n;
    for(int i=0;i<=cnt-1;i++)
    {
        for(int j=1;j<=v[i]-v[i+1];j++)
        {
            cout<<now<<" "<<++tot<<endl;
        }
        now=tot;
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