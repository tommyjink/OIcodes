#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int rd(int n)
{
    return rand()%n+1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("B.in","w",stdout);
    int n=3;
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        int x=rd(n),y=rd(n);
        while(y==x)y=rd(n);
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}