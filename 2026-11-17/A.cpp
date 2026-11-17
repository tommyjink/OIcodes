#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,l[N],r[N],t[N];
vector<int> b;
int get(int x)
{
    return lower_bound(b.begin(),b.end())
}
void solve()
{
    cin>>n>>m;
    b.push_back(n);
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i]>>t[i];
        b.push_back(l[i]);
        b.push_back(r[i]);
        b.push_back(t[i]);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}