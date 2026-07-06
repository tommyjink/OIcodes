#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,k[N],b[N],t[N],maxt=-1e10,mint=1e10;
vector<int> maxa,mina;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>k[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=m;i++)
        cin>>t[i],
        maxt=max(maxt,t[i]),
        mint=min(mint,t[i]);
    for(int i=1;i<=n;i++)
    {
        maxa.push_back(k[i]*maxt+b[i]);
        mina.push_back(k[i]*mint+b[i]);
    }
    sort(maxa.begin(),maxa.end());
    sort(mina.begin(),mina.end());
    cout<<max(maxa[n-1]+maxa[n-2],mina[n-1]+mina[n-2]);
    return 0;
}