#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e6+10;
int n,m,L,k,x[N],y[N],d[N],a[N],b[N],sum1[N],sum2[N];
int cnt[N];
void solve()
{
    int ans=0,base=0;
    cin>>n>>L>>k;m=n*4+10;
    for(int i=0;i<=m;i++)x[i]=y[i]=d[i]=a[i]=b[i]=sum1[i]=sum2[i]=cnt[i]=0;
    for(int i=1;i<=n;i++)
    {
        int l;cin>>l;l++;
        d[l]++,d[l+L]--;
        cnt[l]++;
    }
    for(int i=1;i<=m;i++)
    {
        d[i]+=d[i-1];
        x[i]=(d[i]==k+1)-(d[i]==k);
        y[i]=(d[i]==k-1)-(d[i]==k);
        base+=(d[i]==k);
    }
    for(int i=0;i<=L-1;i++)
        a[0]+=x[i],b[0]+=y[i];
    for(int i=1;i<=m-L+1;i++)
    {
        a[i]=a[i-1]+x[i+L-1]-x[i-1];
        b[i]=b[i-1]+y[i+L-1]-y[i-1];
    }
    int now=0;
    for(int i=L;i<=m-L+1;i++)
    {
        now=max(now,b[i-L]);
        if(cnt[i])ans=max(ans,now+a[i]);
    }
    now=0;
    for(int i=L;i<=m-L+1;i++)
    {
        if(cnt[i-L])now=max(now,a[i-L]);
        ans=max(ans,now+b[i]);
    }
    for(int i=1;i<=m-L+1;i++)
        sum1[i]=sum1[i-1]+y[i]+x[i+L],
        sum2[i]=sum2[i-1]+x[i]+y[i+L];
    deque<int> q;
    for(int i=1;i<=m;i++)
    {
        while(!q.empty()&&q.front()<i-L+1)q.pop_front();
        while(!q.empty()&&sum1[q.back()]>sum1[i])q.pop_back();
        q.push_back(i);
        if(!q.empty()&&cnt[i])ans=max(ans,sum1[i]-sum1[q.front()]);
    }
    while(!q.empty())q.pop_front();
    for(int i=1;i<=m;i++)
    {
        while(!q.empty()&&q.front()<i-L+1)q.pop_front();
        while(!q.empty()&&sum2[q.back()]>sum2[i])q.pop_back();
        if(cnt[i])q.push_back(i);
        if(!q.empty())ans=max(ans,sum2[i]-sum2[q.front()]);
    }
    cout<<ans+base<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}