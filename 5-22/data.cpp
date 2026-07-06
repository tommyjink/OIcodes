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
    int T=10;
    cout<<T<<endl;
    while(T--)
    {
        int n=rd(1,200),k=rd(1,200);
        cout<<n<<" "<<k<<endl;
    }
    
    return 0;
}