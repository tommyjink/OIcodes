#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int typ,n,p[N];
string a,b;
bool check()
{
    int mx=0,mn=n+1;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,p[i]);
        mn=min(mn,p[i]);
        int len=mx-mn+1;
        if(a[i]=='1'&&len!=i)return false;
        if(a[i]=='0'&&len==i)return false;
    }
    mx=0,mn=n+1;
    for(int i=n;i>=1;i--)
    {
        mx=max(mx,p[i]);
        mn=min(mn,p[i]);
        int len=mx-mn+1;
        if(b[i]=='1'&&len!=n-i+1)return false;
        if(b[i]=='0'&&len==n-i+1)return false;
    }
    return true;
}
void solve()
{
    cin>>n>>a>>b;
    a=" "+a;
    b=" "+b;
    for(int i=1;i<=n;i++)
        p[i]=i;
    while(!check()&&next_permutation(p+1,p+1+n));
    if(check())
    {
        cout<<"YES"<<endl;
        if(typ)
        {
            for(int i=1;i<=n;i++)
                cout<<p[i]<<" ";
            cout<<endl;
        }
    }
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>typ>>t;
    while(t--)solve();
    return 0;
}