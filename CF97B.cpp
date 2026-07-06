#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,cnt=0;
pii a[N],b[N];
void dfs(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    for(int i=l;i<=r;i++)
        b[++cnt]=pii(a[mid].first,a[i].second);
    dfs(l,mid);
    dfs(mid+1,r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+1+n);
    dfs(1,n);
    for(int i=1;i<=n;i++)
        b[++cnt]=a[i];
    sort(b+1,b+1+cnt);
    int tot=unique(b+1,b+1+cnt)-b-1;
    cout<<tot<<endl;
    for(int i=1;i<=tot;i++)
        cout<<b[i].first<<" "<<b[i].second<<endl;
    return 0;
}