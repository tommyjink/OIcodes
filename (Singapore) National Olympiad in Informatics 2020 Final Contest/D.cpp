#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e7+10;
int n,m;
pii a[N];
vector<pii> b;
struct node
{
    int T,A;
}q[N];
bool cmp(node x,node y)
{
    if(x.A+x.T==y.A+y.T)
        return x.T-x.A<y.T-y.A;
    return x.A+x.T<y.A+y.T;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    for(int i=1;i<=n;i++)cin>>q[i].T;
    for(int i=1;i<=n;i++)cin>>q[i].A;
    sort(q+1,q+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        a[i]=pii(-(q[i].T-q[i].A),-(q[i].T+q[i].A));
        auto p=lower_bound(b.begin(),b.end(),a[i]);
        if(p==b.end())b.push_back(a[i]);
        else *p=a[i];
    }
    cout<<b.size();
    return 0;
}