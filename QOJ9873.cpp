#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N],x,y;
void solve()
{
    x=y=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int p=1;
    if(a[1]==1)a[1]=0,y++,x++,p=2;
    for(int i=1;i<=n;i++)
        if(a[i]>1)a[i]--,y++;
    for(int i=1;i<=m;i++)
    {
        while(p<=n&&a[p]<=x)p++,x++;
        if(x>=b[i])x++;
        else if(x+y>=b[i])
            y-=b[i]-x,x++;
        else {cout<<"No"<<endl;return;}
    }
    cout<<"Yes"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}