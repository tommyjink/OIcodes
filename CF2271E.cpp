#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N];
int check(int mid)
{
    // cout<<"mid="<<mid<<endl;
    int kk=k;
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
        q.push(a[i]);
    int now=mid;
    while(now>=kk&&!q.empty())
    {
        int t=q.top();q.pop();
        // cout<<now<<","<<kk<<","<<t<<endl;
        if(now>=t){now--;continue;}
        q.push((t+1)/2);
        q.push((t+1)/2);
        kk++;
        // cout<<now<<","<<kk<<"!!"<<endl;
    }
    if(!q.empty())return -1;
    return now-kk+1;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l=n,r=4*n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)!=-1)r=mid;
        else l=mid+1;
    }
    r=4*n;
    // cout<<l-k+1<<"!!";
    while(check(l)&1)l++;
    cout<<l-k+1<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}