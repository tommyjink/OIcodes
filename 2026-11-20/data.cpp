#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int rd(int x)
{   
    return rand()%x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    int n=10;
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
        cout<<rd(n)<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<rd(n)<<" ";
    cout<<endl;
    return 0;
}