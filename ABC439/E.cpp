#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,f[N],now=0,ans=0,b[N];
pii a[N];
bool cmp(pii x,pii y)
{
    return x.first==y.first?x.second>y.second:x.first<y.first;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)b[i]=a[i].second;
    for(int i=1;i<=n;i++)
    {
        int p=lower_bound(f+1,f+1+now,b[i])-f;
        f[p]=b[i];
        now=max(now,p);
    }
    cout<<now<<endl;
    return 0;
}