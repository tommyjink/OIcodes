#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,a[N];
string s[2];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s[0]>>s[1];
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x]++,a[y+1]++;
    }
    for(int i=1;i<=n;i++)a[i]+=a[i-1],a[i]%=2;
    for(int i=1;i<=n;i++)
        cout<<s[a[i]][i-1];
    return 0;
}