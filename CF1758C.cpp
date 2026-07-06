#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,x,a[N];
void solve()
{
    cin>>n>>x;
    if(n%x)
    {
        cout<<"-1"<<endl;
        return;
    }
    a[1]=x,a[n]=1;
    for(int i=2;i<=n-1;i++)a[i]=i;
    int now=n;
    while(1)
    {
        int i=now-x;
        while(i>=1&&now%i)i-=x;
        if(i==0)break;
        a[i]=now,now=i;
        if(i==x)break;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}