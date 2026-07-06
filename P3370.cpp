#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
const ull base=13331;
ull n,a[N],cnt=0;
ull f(string s)
{
    ull res=0;
    for(auto c:s)
        res=(res*base+(ull)c);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        a[++cnt]=f(s);
    }
    sort(a+1,a+1+cnt);
    cout<<unique(a+1,a+1+cnt)-a-1;
    return 0;
}