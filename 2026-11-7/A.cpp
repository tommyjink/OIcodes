#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005;
int n,r[N];
struct node
{
    int x,y,s;
}a[N];
bool cmp(node a,node b)
{
    return a.s<b.s;
}
inline int p(int x){return x*x;}
inline int dis(int x,int y,int xx,int yy)
{
    int s=p(x-xx)+p(y-yy)-1,d=sqrtl(s);
    while(p(d+1)<=s)d++;
    while(p(d)>s)d--;
    return d;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y>>a[i].s;
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=i;
        for(int j=i+1;j<=n;j++)
            if(a[j].s<a[x].s)x=j;
        swap(a[i],a[x]);
        r[i]=a[i].s;
        for(int j=i+1;j<=n;j++)
        {
            int res=dis(a[i].x,a[i].y,a[j].x,a[j].y)+r[i];
            a[j].s=min(a[j].s,res);
        }
        ans+=r[i];
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
