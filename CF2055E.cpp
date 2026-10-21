#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,c[N],mn[N],mx1[N],mx2[N];
struct node
{
    int a,b;
}p[N];
bool cmp(node x,node y)
{
    if(x.a<=x.b&&y.a>y.b)
        return true;
    else if(x.a>x.b&&y.a<=y.b)
        return false;
    else if(x.a<=x.b)
        return x.a<y.a;
    else
        return x.b>y.b;
}
void solve()
{
    int sa=0,sb=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i].a>>p[i].b,
        sa+=p[i].a,sb+=p[i].b;
    sort(p+1,p+1+n,cmp);
    mx1[0]=mx1[n+1]=mx2[0]=mx2[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        c[i]=c[i-1]-p[i-1].b+p[i].a;
        mx1[i]=c[i];
        mx2[i]=c[i];
        if(i>1)mx1[i]=max(mx1[i-1],mx1[i]);
    }
    for(int i=n-1;i>=1;i--)
        mx2[i]=max(mx2[i],mx2[i+1]);
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
        if(sb-p[i].b<sa)continue;
        int M=mx1[i-1];
        if(i<n)M=max(M,mx2[i+1]-(p[i].a-p[i].b));
        ans=min(ans,M+sa);
    }
    if(ans==1e18)cout<<-1<<endl;
    else cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}