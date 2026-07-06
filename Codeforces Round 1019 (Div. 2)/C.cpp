#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N],b[N];
void solve()
{
    int cntb=0,cntc=0,fb=0,fc=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=k)b[i]=1+b[i-1];
        else b[i]=b[i-1];
        if(b[i]*2>=i&&i>=2&&i<=n-1)cntb++;
        if(b[i]*2>=i&&!fb)fb=i;
    }
    b[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        if(a[i]<=k)b[i]=1+b[i+1];
        else b[i]=b[i+1];
        if(b[i]*2>=(n-i+1)&&i<=n-1&&i>=2)cntc++;
        if(b[i]*2>=(n-i+1)&&!fc)fc=i;
    }
    if(fb&&fc&&fb<fc)cout<<"YES"<<endl;
    else if(cntb>=2||cntc>=2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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