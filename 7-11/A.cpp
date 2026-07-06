#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],tag[N],cnt=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        if(++tag[a[i]]==1)cnt++;
    if(cnt&1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        if(tag[i])cout<<i<<" ",tag[i]--;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=tag[i];j++)
            cout<<i<<" ";
    return 0;
}