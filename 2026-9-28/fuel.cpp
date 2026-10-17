#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e5+10;
int n,a[N],b[N],c[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fuel.in","r",stdin);
    freopen("fuel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i+n]=a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i],b[i+n]=b[i];
    for(int i=1;i<=2*n;i++)
    {
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    for(int i=1;i<=2*n;i++)
        a[i]-=b[i];
    deque<int> q;
    for(int i=1;i<=n-1;i++)
    {
        while(!q.empty()&&a[q.back()]>=a[i])q.pop_back();
        q.push_back(i);
    }
    int ans=-1e18,cnt=0;
    for(int s=1;s<=n;s++)
    {
        while(!q.empty()&&q.front()<s)q.pop_front();
        while(!q.empty()&&a[s+n-1]<=a[q.back()])q.pop_back();
        q.push_back(s+n-1);
        c[s]=a[q.front()]-a[s-1];
        ans=max(ans,c[s]);
    }
    if(ans>=0)
    {
        for(int i=1;i<=n;i++)
            if(c[i]>=0)cnt++;
        cout<<0<<" "<<cnt<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++)
            if(c[i]==ans)cnt++;
        cout<<-ans<<" "<<cnt<<endl;
    }
    return 0;
}