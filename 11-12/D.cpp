#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
int a[N],x,y,k;
bool dfs(int now)
{
    if(a[now]==y&&a[now-1]==x)return true;
    if(now>16)return false;
    a[now+1]=a[now]+a[now-1];
    int res=0;
    if(a[now+1]>=k)res|=dfs(now+1);
    a[now+1]=max(a[now],a[now-1])-min(a[now],a[now-1]);
    if(a[now+1]>=k)res|=dfs(now+1);
    return res;
}
void solve()
{
    cin>>a[0]>>a[1]>>x>>y>>k;
    if(min({a[0],a[1],x,y})<k)
    {
        cout<<"no"<<endl;
        return;
    }
    if(dfs(1))cout<<"yes"<<endl;
    else cout<<"no"<<endl;
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
2 3 7 9 1
4 9 2 5 1
4 9 2 5 2
6 4 1 2 3
7 9 7 9 7
yes
yes
no
no
yes


*/