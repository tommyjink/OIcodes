#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+100;
int n,a[N],ans=0;
unordered_map<int,int> mp;
vector<int> b;
signed main()
{
    freopen("triple.in","r",stdin);
    freopen("triple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!mp.count(a[i]))
            mp[a[i]]=0,b.push_back(a[i]);
        mp[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j*j<=a[i];j++)
        {
            if(a[i]%(j*j)==0&&mp.count(a[i]/(j*j))&&mp.count(a[i]/j))
            {
                ans+=mp[a[i]/(j*j)]*mp[a[i]/j];
            }
        }
    }
    for(auto i:b)
    {
        if(mp[i]>=3)
            ans+=mp[i]*(mp[i]-1)*(mp[i]-2);
    }
    cout<<ans<<endl;
    return 0;
}