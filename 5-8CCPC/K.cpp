#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,m,k,b[N];
struct node
{
    int t,x,y;
}a[N];
bool cmp(node x,node y)
{
    return x.t>y.t;
}
bool check(int x)
{
    memset(b,0,sizeof(b));
    int xx=x;
    for(int i=1;i<=m;i++)
    {
        int tmp=x-(a[i].t)-(a[i].y+k-1)/k-b[a[i].x]+2;
        if(tmp>0)
        {
            xx-=tmp;
            if(xx+1<a[i].t)return false;
            b[a[i].x]+=tmp;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>a[i].t>>a[i].x>>a[i].y;
    sort(a+1,a+1+m,cmp);
    int l=0,r=4e18;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    if(l>=4e18)cout<<"-1"<<endl;
    else cout<<l<<endl;

    return 0;
}