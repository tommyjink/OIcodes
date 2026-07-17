#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=10;
int n,a[N];
bitset<100> b;
void print()
{
    for(int i=0;i<=10;i++)
        cout<<b[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    cin>>n;
    b[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(a[i]--)b|=(b<<i);
        // print();
    }
    cout<<b.count()-1<<endl;
    return 0;
}