#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int rd(int l,int r)
{
    return rand()%(r-l+1)+l;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n=10,m=100;
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        int l=rd(1,m),r=rd(l,m);
        cout<<l<<" "<<r<<endl;
    }
    return 0;
}