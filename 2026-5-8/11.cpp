#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,k,a[N];
string s;
int gcd1(int x,int y)
{
    if(!y)return x;
    return gcd1(y,x%y);
}
void solve()
{
    cin>>n>>k>>s;
    k%=n;
    if(k==0)
    {
        string t=s;
        reverse(t.begin(),t.end());
        if(s==t)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    int g=gcd1(n,k);
    for(int i=0;i<g;i++)a[i]=0;
    for(int i=0;i<n;i++)a[i%g]^=(s[i]-'0');
    for(int i=0;i<g;i++)
        if(a[i]!=a[g-i-1])
        {
            cout<<"NO"<<endl;
            return;
        }
    if(n%2==0&&g%2==1&&a[g/2])
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
