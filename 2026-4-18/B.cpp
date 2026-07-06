#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3010;
int n,q,k,b;
int a[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q>>k>>b;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int l,r,v;
            cin>>l>>r>>v;
            for(int i=l;i<=r;i++) a[i]+=v;
        }
        else
        {
            int i;
            cin>>i;
            int ans=0;
            for(int r=1;i-r>0&&i+r<=n;r++)
            {
                if(a[i+r]-a[i-r]==k*r+b) ans=r;
                else break;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
