#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10;
int n,a[N],b[N],tag[N];
map<int,int> cnt;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
    for(int i=1;i<=n;i++)cin>>b[i],cnt[b[i]]++;
    cnt[a[1]]--;
    a[1]=b[1]=0;
    for(int i=1;i<=n;i++)a[i]=max(a[i],a[i-1]);
    for(int i=1;i<=n;i++)b[i]=max(b[i],b[i-1]);
    sort(b+1,b+1+n);
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        int p=lower_bound(b+2,b+1+n,a[i])-b-1;
        // cout<<p<<"!"<<endl;
        cnt[a[i]]+=p-1;
        if(cnt[a[i]]>cnt[ans])ans=a[i];
        else if(cnt[a[i]]==cnt[ans]&&a[i]>ans)ans=a[i];
        tag[p+1]++;
    }
    for(int i=1;i<=n;i++)
    {
        tag[i]+=tag[i-1];
        cnt[b[i]]+=tag[i];
        if(cnt[b[i]]>cnt[ans])ans=b[i];
        else if(cnt[b[i]]==cnt[ans]&&b[i]>ans)ans=b[i];
    }
    cout<<ans<<" "<<cnt[ans]<<endl;
    return 0;
}