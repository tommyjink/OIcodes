#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
string a,b;
int n,m,sav[N];
char rev(char c)
{
    if(c=='P')return 'S';
    if(c=='S')return 'R';
    if(c=='R')return 'P';
}
bool check(int mid)
{
    int p=1,q=mid;
    for(int i=1;i<=m;i++)
        sav[i]=n;
    while(p<=m&&q<=n)
    {
        sav[p]=min(sav[p],q);
        while(q<=n&&p<=m&&rev(a[q])==b[p])
            q++;
        if(q<=n&&p<=m&&a[q]==b[p])q++,p++;
        sav[p]=min(sav[p],q);
        if(q<=n&&p<=m&&a[q]==rev(b[p]))p++;
        sav[p]=min(sav[p],q);
    }
    if(p==m+1)return false;
    return true;
}
void solve()
{
    cin>>a>>b;
    n=a.length();
    m=b.length();
    a=" "+a+" ";
    b=" "+b+" ";
    int l=1,r=n+1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    check(l);
    int p=1,ans=n;
    for(int i=1;i<=m;i++)
    {
        while(p<=n&&rev(a[p])==b[i])p++;
        ans=min(ans,sav[i]-i);
        if(a[p]==b[i]){p++;continue;}
        if(a[p]==rev(b[i]))continue;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}