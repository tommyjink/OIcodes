#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N],d[N],ans=0;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
        d[i]=s[i]-'0';
    for(int i=1;i<=n;i++)
        c[i]=d[i]^d[i-1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        a[i]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i])
        {
            ans+=b[i];
            c[i]^=1;
            c[a[i]]^=1;
        }
    }   
    cout<<ans<<endl;
    return 0;
}