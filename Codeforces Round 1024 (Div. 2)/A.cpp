#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,p,q;
        cin>>n>>m>>p>>q;
        if(n%p==0&&n/p*q!=m)
            cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}