#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    int n=rand()%3+1;
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
        cout<<rand()%100<<" ";
    return 0;
}