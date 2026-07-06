#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,a[N],b[N];
void solve()
{ 
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int res=n*(n+1)/2;
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=n;j++)
            b[j]=b[j-1]+(a[j]<=i?-1:1);
        map<int,int> mp;
        int p=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==i)while(p<j)mp[b[p]]++,p++;
            res-=mp[b[j]];
        }
    }
    cout<<res<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t;
    cin>>_t;
    while(_t--)
        solve();
    return 0;
}