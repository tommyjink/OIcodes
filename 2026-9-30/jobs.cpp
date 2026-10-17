#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n;
struct node{int s,t;}a[N];
bool cmp(node x,node y)
{
    if(x.s==y.s)return x.t<y.t;
    return x.s<y.s;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].s>>a[i].t,a[i].s+=a[i].t;
    sort(a+1,a+1+n,cmp);
    priority_queue<int> q;
    int now=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(now+a[i].t>a[i].s)
        {
            if(!q.empty()&&q.top()>a[i].t)
                now+=a[i].t-q.top(),q.pop(),q.push(a[i].t);
        }
        else q.push(a[i].t),now+=a[i].t,cnt++;
    }
    cout<<cnt<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("jobs.in","r",stdin);
    freopen("jobs.out","w",stdout);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}