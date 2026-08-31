#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
const double eps=1e-7,e=1e-6;
int n,l[N],r[N],cnt;
double f[N];
struct node
{
    double x,y;
}a[N];
bool cmp(node x,node y)
{
    if(fabs(x.x-y.x)<eps)return x.y<y.y;
    return x.x<y.x;
}
bool cmp1(double x,double y)
{
    if(fabs(x-y)<eps)return false;
    return x<y;
}
void solve()
{
    cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {     
        cin>>l[i]>>r[i];
        if(i==1)
        {
            a[++cnt]={0.0,l[i]*1.0-1.0};
            continue;
        }
        if(l[i]>l[i-1])a[++cnt]={i*1.0-1.0+e,l[i]*1.0-1.0};
        if(r[i]>r[i-1])a[++cnt]={i*1.0-1.0,r[i-1]*1.0+e};
    }
    sort(a+1,a+1+cnt,cmp);
    // for(int i=1;i<=cnt;i++)
    //     cout<<a[i].x<<" "<<a[i].y<<endl;
    // cout<<"!!!!"<<endl;
    int ans=0;
    f[++ans]=a[1].y;
    for(int i=2;i<=cnt;i++)
    {
        int p=lower_bound(f+1,f+1+ans,a[i].y,cmp1)-f;
        if(p==ans+1)f[++ans]=a[i].y;
        else f[p]=a[i].y;
    }
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