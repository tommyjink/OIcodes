#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=1e18;
int n,a[N],b[N];
int sum[N],c[N];
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-1;i++)
        cin>>b[i];
    s="1"+s+"1";
    for(int i=0;i<=n;i++)
        c[i]=(i==0?0:c[i-1])+(s[i]=='1'&&s[i+1]=='1')*b[i]+(s[i]=='1')*a[i];
    for(int i=0;i<=n;i++)
        sum[i]=(i==0?0:sum[i-1])+(s[i]=='0'&&s[i+1]=='0')*b[i]+(s[i]=='0')*a[i];
    // for(int i=0;i<=n;i++)
    //     cout<<sum[i]<<" ";
    // cout<<endl;
    int mn=INF,ans=0;
    for(int i=0;i<=n;i++)
    {
        if(s[i]=='0'&&s[i+1]=='1')
        {
            ans=max(ans,sum[i]+b[i]-mn+c[n]-c[i]);
        }
        if(s[i]=='1'&&s[i+1]=='0')
            mn=min(mn,sum[i]-b[i]-c[i]);
    }
    cout<<max(ans,c[n])<<endl;
    return 0;
}