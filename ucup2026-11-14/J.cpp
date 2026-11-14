#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,a[N],b[N];
pii q[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int m=0;
    for(int i=1;i<=n;)
    {
        int j=i;
        while(j<=n&&b[j]==b[i])j++;
        int cnt=j-i;
        q[++m]={b[i]-cnt,b[i]};
        i=j;
    }
    sort(q+1,q+m+1);
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        int x=q[i].second,c=x-q[i].first;
        if(sum+c>=x)
        {
            sum+=c;
        }
        else
        {
            int cnt=upper_bound(a+1,a+n+1,x)-lower_bound(a+1,a+n+1,x);
            if(cnt<c)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}