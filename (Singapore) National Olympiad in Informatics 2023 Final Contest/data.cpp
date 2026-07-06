#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    int n=2,m=n-1,lim=100000000;
    cout<<n<<" "<<m<<endl;
    cout<<"0 ";
    for(int i=2;i<n;i++)
        cout<<rand()%lim<<" ";
    cout<<"0"<<endl;
    for(int i=1;i<n;i++)
        cout<<i<<" "<<i+1<<endl;
    return 0;
}