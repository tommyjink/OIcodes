#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
string a,b;
int n,m,sav[N];
char rev(char c)
{
    if(c=='N')return 'R';
    if(c=='U')return 'N';
    if(c=='R')return 'U';
}
void cal()
{
    sav[m]=n+1;
    while(sav[m]>1&&rev(a[sav[m]-1])==b[m])sav[m]--;
    for(int i=m-1;i>=1;i--)
    {
        sav[i]=sav[i+1];
        if(sav[i]>1&&a[sav[i]-1]==b[i])sav[i]--;
        while(sav[i]>1&&rev(a[sav[i]-1])==b[i])sav[i]--;
    }
}
void solve()
{
    cin>>a>>b;
    n=a.length();
    m=b.length();
    a=" "+a+" ";
    b=" "+b+" ";
    cal();
    // for(int i=1;i<=m;i++)
    //     cout<<sav[i]<<" ";
    // cout<<endl;
    int p=1,ans=n;
    int l=1,r=n;
    for(int i=1;i<=m;i++)
    {
        // cout<<i<<" "<<p<<" "<<sav[i]<<endl;
        while(p<=n&&rev(a[p])==b[i])p++;
        if(sav[i]-p<ans)
        {
            ans=sav[i]-p;
            l=p,r=sav[i]-1;
        }
        ans=min(ans,sav[i]-p);
        if(p<=n&&a[p]==b[i])p++;
    }
    cout<<l<<" "<<r<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}