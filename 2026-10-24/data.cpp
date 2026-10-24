#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    int n=3,m=5,w=20,k=1;
    cout<<n<<" "<<m<<" "<<w<<" "<<k<<endl;
    for(int i=1;i<=n;i++)
        cout<<rand()%w<<" ";
    cout<<endl;
    for(int i=1;i<=m;i++)
        cout<<rand()%w<<" ";
    return 0;
}