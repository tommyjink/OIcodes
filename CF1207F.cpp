#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=5e5+10,M=375;
int ans[M][M],a[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    while(q--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
        {
            a[x]+=y;
            for(int i=1;i<M;i++)
                ans[i][x%i]+=y;
        }
        else
        {
            if(x<M)cout<<ans[x][y]<<endl;
            else
            {
                int res=0;
                for(int i=y;i<N;i+=x)
                    res+=a[i];
                cout<<res<<endl;
            }
        }
    }
    return 0;
}