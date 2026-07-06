#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,t[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        t[i]+=x;
        t[i+1]-=x;
    }
    while(m--)
    {
        int c,l,r;
        cin>>c>>l>>r;
        if(c==1)
        {
            vector<int> tmp;
            int ans=0,sum=0,now=0;
            for(int i=1;i<=l-1;i++)
                now+=t[i];
            for(int i=l;i<=r;i++)
            {
                now+=t[i];
                tmp.push_back(now),
                sum^=tmp.back();
            }
            for(auto i:tmp)
                if((sum^i)<=i)
                    ans++;
            cout<<ans<<endl;
        }
        if(c==2)
        {
            int w;
            cin>>w;
            t[l]+=w;
            t[r+1]-=w;
        }
    }
    return 0;
}