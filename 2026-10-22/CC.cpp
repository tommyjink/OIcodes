#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],k=0,b[N];
void solve()
{
    k=0;
    string s;
    cin>>s;
    n=s.length();
    s=" "+s;
    for(int i=1;i<=n;i++)
        a[i]=s[i]-'0';
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            cnt0=0,cnt1++;
        }   
        else
        {
            cnt1=0,cnt0++;
        }
        if(cnt1>1)
        {

        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}