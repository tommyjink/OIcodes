#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,k[N],cnt[N];
void solve()
{
    vector<int> b;
    cin>>n>>m;
    int mx=0;
    for(int i=1;i<=m;i++)
    {
        cin>>k[i];
        mx=max(mx,k[i]);
        vector<int> a;
        a.push_back(0);
        for(int j=1;j<=k[i];j++)
        {
            int x;cin>>x;
            a.push_back(x);
        }
        if(k[i]>n/2)b=a;
    }
    if(mx<=n/2){cout<<"0"<<endl;return;}
    int s=n-mx,p=0;
    for(int i=1;i<=mx;i++)
        b[i]-=i;
    for(int i=0;i<=s;i++)cnt[i]=0;
    for(int i=1;i<=mx;i++)
    {
        if(b[i]<0||b[i]>s)continue;
        if(b[i]==0)cnt[0]++;
        else if(cnt[b[i]-1])cnt[b[i]-1]--,cnt[b[i]]++;
    }
    cout<<cnt[s]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}