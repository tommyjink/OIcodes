#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int INF=1e9;
int n,ans=0;
int l=-INF,r=-INF;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        if(c=='L')
        {
            if(l==-INF)l=x;
            ans+=abs(x-l);
            l=x;
        }
        else
        {
            if(r==-INF)r=x;
            ans+=abs(x-r);
            r=x;
        }
    }
    cout<<ans;
    return 0;
}