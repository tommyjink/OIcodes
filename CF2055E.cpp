#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,mn[N];
struct node
{
    int a,b;
}p[N];
bool cmp(node x,node y)
{
    if(x.a-x.b==y.a-y.b)
        return x.b>y.b;
    return x.a-x.b<y.a-y.b;
}
void solve()
{
    int sa=0,sb=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i].a>>p[i].b,
        sa+=p[i].a,sb+=p[i].b;
    sort(p+1,p+1+n,cmp);
    mn[n+1]=1e18;
    for(int i=n;i>=1;i--)
        mn[i]=min(mn[i+1],p[i].b);
    if(sb-mn[1]<sa){cout<<-1<<endl;return;}
    int k=n;
    for(int i=1;i<=n;i++)
        if(sb-mn[i+1]<sa){k=i;break;}
    int r=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i==k)continue;
        ans+=p[i].a;
        int tmp=min(r,p[i].a);
        p[i].a-=tmp,r-=tmp;
        p[k].a+=p[i].a;
        r+=p[i].b;
    }
    ans+=p[k].a;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}