#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1<<22;
int n,a[N];
struct node
{
    int b,mx,mn;
};
node cal(int l,int r)
{
    if(l==r)return {0,a[l],a[l]};
    int mid=(l+r)>>1;
    node ll=cal(l,mid);
    node rr=cal(mid+1,r);
    node res={0,0,0};
    res.mx=max(ll.mx,rr.mx);
    res.mn=min(ll.mn,rr.mn);
    res.b=max(ll.b+rr.b,res.mx-res.mn);
    return res;
}
void solve()
{
    cin>>n;
    for(int i=0;i<(1<<n);i++)
        cin>>a[i];
    node res=cal(0,(1<<n)-1);
    cout<<max(res.mx,res.b)<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}