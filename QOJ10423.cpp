#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,q,b[N],c[N],pre[N],r[N];
struct node{int len,r;}a[N];
bool cmp(node x,node y){return x.r==y.r?x.len<y.len:x.r<y.r;}
void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>a[i].len;
    for(int i=1;i<=n;i++)cin>>a[i].r;
    for(int i=1;i<=m;i++)cin>>b[i],b[i]+=b[i-1];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i].len,r[i]=a[i].r;
    for(int i=1;i<=n;i++)
        c[i]=r[i]-pre[i];
    for(int i=n-1;i>=1;i--)
        c[i]=min(c[i+1],c[i]);
    while(q--)
    {
        int t;cin>>t;
        int p=upper_bound(r+1,r+1+n,t)-r-1;
        int x;
        if(p==n)x=t-pre[p];
        else x=min(t-pre[p],c[p+1]);
        int h=upper_bound(b+1,b+1+m,x)-b-1;
        cout<<h<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}