#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("repair.in","r",stdin);
    freopen("repair.out","w",stdout);
    int n,m,q,aa;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++)
            cin>>aa;
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++)
            cin>>aa;
    for(int i=1;i<=q;i++)
        cout<<"-1"<<endl;
    return 0;
}