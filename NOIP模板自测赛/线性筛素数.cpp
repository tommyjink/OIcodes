#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e8+10;
int n,q,prime[N],cnt=0,vis[N];
void init()
{
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=n;j++)
        {
            vis[prime[j]*i]=true;
            if(i%prime[j]==0)break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    init();
    // for(int i=1;i<=cnt;i++)cout<<prime[i]<<" ";
    while(q--)
    {
        int x;
        cin>>x;
        cout<<prime[x]<<endl;
    }
    return 0;
}
/*
100 5
1
2
3
4
5

*/