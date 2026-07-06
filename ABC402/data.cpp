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
    int n=20,p=100007;
    cout<<n<<" "<<p<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<rd(1,9)<<" ";
        cout<<endl;
    }
    return 0;
}