//The Version 2.0 of P3067.cpp
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=21;
int n,a[N],ans[1ll<<N],tot=0;
map<int,vector<int> > mp;
void dfs(int l,int r,int val,int mode,int now)
{
    if(l>r)
    {
        if(mode) 
            mp[val].push_back(now);
        else if(mp.count(-val))
            for(int i:mp[-val])
                ans[i|now]=true;
        return ;
    }
    dfs(l+1,r,val+a[l],mode,now|(1ll<<(l-1)));
    dfs(l+1,r,val-a[l],mode,now|(1ll<<(l-1)));
    dfs(l+1,r,val,mode,now);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,n/2,0,1,0);
    dfs(n/2+1,n,0,0,0);
    for(int i=1;i<(1ll<<n);i++)
        tot+=ans[i];
    cout<<tot<<endl;
    return 0;
}
/*
4 
1 
2 
3 
4 
*/