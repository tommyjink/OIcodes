#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int x[4],y[4],ans=1e15;
int dis(int xx,int yy)
{
    int res=0;
    for(int i=1;i<=3;i++)
        res+=abs(xx-x[i])+abs(yy-y[i]);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<=3;i++)
        cin>>x[i]>>y[i];
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++)
            ans=min(ans,dis(i,j));
    cout<<ans+1;
    return 0;
}