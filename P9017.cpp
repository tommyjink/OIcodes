#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=21;
int n,f[N][1<<N];
void roll(int &x)
{
    x=(x>>1)|((x&1)<<(n-1));
}
int read()
{
    int res=0;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
        res=res*2+s[i]-'0';
    return res;
}
void print(int x)
{
    string s;
    for(int i=n-1;i>=0;i--)
        if(x&(1ll<<i))cout<<1;
        else cout<<0;
    cout<<endl;
}
void solve()
{
    int aa=read(),bb=read();
    for(int ans=0;ans<=n;ans++)
    {
        int a=aa,b=bb;
        // cout<<"ans="<<ans<<endl;
        for(int i=0;i<n;i++)
        {
            if(!(b&(1ll<<i)))continue;
            int now=((1ll<<ans)-1)<<(n-ans);
            for(int j=1;j<=n-i-1;j++)roll(now);
            a^=now;
            // print(now);
        }
        // cout<<"a=";
        // print(a);
        if(f[ans][a]){cout<<ans<<endl;return;}
    }
    cout<<"-1"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t>>n;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        // cout<<"i="<<i<<endl;
        for(int j=0;j<(1ll<<n);j++)
        {
            int now=(1ll<<i)-1;
            for(int k=1;k<=n;k++,roll(now))
            {
                
                // if(j==0)cout<<"now=",print(now);
                f[i][j]|=f[i-1][j^now];
            }
        }
    }
    while(t--)solve();
    return 0;
}