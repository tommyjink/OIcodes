#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,k;
vector<int> a,b;
int calc(vector<int> &a)
{
    sort(a.begin(),a.end(),greater<int>());int res=0;
    for(int i=0;i<a.size();i+=k)res+=a[i]*2;
    return res;
}
signed main()
{
    freopen("supply.in","r",stdin);freopen("supply.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        if(x>0)a.push_back(x);
        else b.push_back(-x);
    }
    int ans=calc(a)+calc(b),mx=0;
    if(a.size())mx=max(mx,a[0]);
    if(b.size())mx=max(mx,b[0]);
    cout<<ans-mx<<endl;
    return 0;
}
