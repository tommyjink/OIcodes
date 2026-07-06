#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,r;
struct node
{
    int x,y;
}a[N];
bool cmp1(node x,node y)
{
    if(x.x==y.x)
        return x.y<y.y;
    return x.x<y.x;
}
bool cmp2(node x,node y)
{
    if(x.x==y.x)
        return x.y>y.y;
    return x.x<y.x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>r;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++)
    {
        
    }
    return 0;
}