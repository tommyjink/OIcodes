#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
int v[100];
map<pii,int> mp;
int dfs(int x,int y)
{
    if(x<y)return 0;
    if(mp.count(pii(x,y)))return mp[pii(x,y)];
    int p=upper_bound(v+1,v+1+32,x)-v-1;
    if(y==1) return mp[pii(x,y)]=p;
    return mp[pii(x,y)]=dfs(x-v[p],y-1)+dfs(v[p]-1,y);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int now=0;
    for(int i=1;i<=32;i++)
    {
        now=now*4+1;
        v[i]=now;
        mp[pii(now,1)]=i;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        cout<<dfs(y,z)-dfs(x-1,z)<<endl;
    }
    return 0;
}