#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int M=1e7,N=1e6+10;
int tag[M+10],a[N];
vector<int> p;
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    int now=0,tot=0;
    for(int i=1;i<=n;i++)
    {
        tot=tot+a[i]-p[now];
        now++;
        if(tot<0)
        {
            cout<<n-i+1<<endl;
            return;
        }
    }
    cout<<"0"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=2;i<=M;i++)
    {
        if(tag[i])continue;
        p.push_back(i);
        for(int j=i;j*i<=M;j++)
            tag[j*i]=true;
    }
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}