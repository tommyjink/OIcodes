#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,h,f[N];
struct node
{
    int x,y,s,e;
}a[N];
bool cmp(node x,node y)
{
    return x.y>y.y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>h;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y>>a[i].s>>a[i].e;
    sort(a+1,a+1+n,cmp);
    // for(int i=1;i<=n;i++)
    //     cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].s<<" "<<a[i].e<<endl;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=a[i].s;
        for(int j=1;j<i;j++)
        {
            if(max(abs(a[j].x-a[i].x),abs(a[j].y-a[i].y))>a[j].e)continue;
            f[i]=max(f[i],f[j]+a[i].s);
        }
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;

    return 0;
}