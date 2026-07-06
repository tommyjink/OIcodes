#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int rd(int x,int y)
{
    int z=y-x;
    return x+(rand()%z)*(rand()%z)%(z+1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    freopen("test.in","w",stdout);
    int n=3,m=3,k=3,v=4;
    printf("%lld %lld %lld %lld\n",n,m,k,v);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<rd(1,10)<<" ";
        cout<<endl;
    }
    return 0;
}