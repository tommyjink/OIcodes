#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,ans=0;
map<string,bool> mp;
struct node
{
    string s;
    int len;
}a[N];
bool cmp(node x,node y)
{
    return x.len<y.len;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].s;
        a[i].len=a[i].s.length();
    }
    sort(a+1,a+1+n,cmp);
    // for(int i=1;i<=n;i++)
        // cout<<a[i].s<<endl;
    for(int i=1;i<=n;i++)
    {
        if(a[i].len==1)
        {
            ans=1;
            mp[a[i].s]=true;
            continue;
        }
        int len=a[i].len;
        if(mp[a[i].s.substr(0,len-1)]&&mp[a[i].s.substr(1,len)])
            mp[a[i].s]=true,ans=max(ans,a[i].len);
    }
    cout<<ans<<endl;
    return 0;
}