#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
map<int,int> cnt,vis;
void solve()
{
    cnt.clear();
    vis.clear();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!cnt.count(a[i]))
            cnt[a[i]]=0;
        cnt[a[i]]++;
    }
    sort(a+1,a+1+n);
    int tot=0;
    for(int i=1;i<=n;i++)
        if(a[i]!=a[i-1])
            a[++tot]=a[i];
    for(int i=1;i<=tot;i++)
    {
        // cout<<a[i]<<"!"<<cnt[a[i]]<<endl;
        if(cnt[a[i]]>=4)
        {
            cout<<"YES"<<endl;
            return;
        }
        else if(cnt[a[i]]>=2&&vis.count(a[i]+1))
        {
            cout<<"YES"<<endl;
            return;
        }
        else if(cnt[a[i]]>=2)
            vis[a[i]+2]=true;
        else if(cnt[a[i]]>=1&&vis[a[i]+1])
            vis[a[i]+2]=true;
    }
    cout<<"NO"<<endl;
    return;
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
/*
5
4
1 1 1 1
3
2 2 2
5
2 4 3 2 4
8
6 3 1 1 5 1 2 6
1
1000000000

*/