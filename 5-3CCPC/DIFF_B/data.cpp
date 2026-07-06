#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int rd(int x,int y)
{
    int z=y-x;
    return x+rand()%(z+1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    freopen("test.in","w",stdout);
    int n=2;
    cout<<n<<" ";
    for(int i=1;i<=n;i++)
        cout<<i<<" "<<rd(1,3)<<" ";
    cout<<endl;
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<n<<" ";
        for(int i=1;i<=n;i++)
        cout<<i<<" "<<rd(1,3)<<" ";
        cout<<endl;
        cout<<n<<" ";
        for(int i=1;i<=n;i++)
        cout<<i<<" "<<rd(1,3)<<" ";
        cout<<endl;
    }
    return 0;
}