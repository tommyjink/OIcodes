#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+100,M=550;
int n,ans[M+10];
set<int> s;
signed main()
{
    // freopen("P9809_1.in","r",stdin);
    // freopen("P9809.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(ans,127/3,sizeof(ans));
    cin>>n;
    while(n--)
    {
        char ch;
        int x;
        cin>>ch>>x;
        if(ch=='A')
        {
            for(int i=1;i<=M;i++)
                ans[i]=min(ans[i],x%i);
            s.insert(x);
        }
        else
        {
            if(x<=M)
                cout<<ans[x]<<endl;
            else
            {
                int res=1e10;
                for(int i=0;i<=N;i+=x)
                {
                    auto p=s.lower_bound(i);
                    if(p!=s.end())res=min(res,*p-i);
                }
                cout<<res<<endl;
            }
        }
    }
    return 0;
}