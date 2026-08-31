#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=5005;
int n,k,t[N];
struct node{int l,r;}a[N];
bool cmp(node x,node y){return x.r-x.l<y.l-y.r;}
bool cmp1(node x,node y){return x.l<y.l;}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r;
    sort(a+1,a+1+n,cmp);
    int l=n-k+1,r=l;
    while(l>1&&a[l].r-a[l].l==a[l-1].r-a[l-1].l)l--;
    while(r<n&&a[r].r-a[r].l==a[r+1].r-a[r+1].l)r++;
    int cnt=n-k+1-l+1;
    sort(a+l,a+1+r,cmp1);
    int ll=1,rr=1e6,ans=0,res=0;
    for(int i=n;i>=n-k+2;i--)
        res+=a[i].r-a[i].l;
    for(int i=1;i<l;i++)
    {
        ll=max(ll,a[i].l);
        rr=min(rr,a[i].r);
    }
    ans=res;
    int nl=1,nr=1e6;
    for(int i=l+cnt-1;i<=r;i++)
    {
        nr=a[i-cnt+1].r;
        nl=a[i].l;
        nl=max(nl,ll);
        nr=min(nr,rr);
        if(nl>nr)continue;
        ans=max(ans,res+nr-nl);
    }
    cout<<ans<<endl;
    return 0;
}