#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
// const int N=1e6+10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,now=0;
        cin>>n>>a;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            now+=x;
        }
        if(a*n==now)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}