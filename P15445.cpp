#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int highbit(int x)
{
    int now=1;
    while(now*2<=x)now*=2;
    return now;
}
void solve()
{
    int x,y,z;
    cin>>x>>y>>z;
    for(int i=30;i>=0;i--)
    {
        if(x&(1ll<<i))
        {
            int now=x&((1ll<<(i+1))-1),h=highbit(now);
            if(now<2*x-z)continue;
            if(h-(now^h)<=y)
            {
                cout<<"YES"<<endl;
                return;
            }

        }
    }
    cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    while(q--)solve();
    return 0;
}