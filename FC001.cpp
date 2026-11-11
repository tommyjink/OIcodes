#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,k,mx1[N],mx2[N];
int a[N],b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
        if(i>=k)ans=max(ans,b[i]-b[i-k]);
        mx1[i]=max(mx1[i-1],a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        mx2[i]=max(mx2[i+1],a[i]);
    }
    deque<int> q;
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&a[q.back()]>a[i])q.pop_back();
        while(!q.empty()&&q.front()<=i-k)q.pop_front();
        q.push_back(i);
        if(i>=k)
        {
            int mx=max(mx1[i-k],mx2[i+1]);
            int mn=a[q.front()];
            ans=max(ans,b[i]-b[i-k]+mx-mn);
        }
    }
    cout<<ans<<endl;
    return 0;
}