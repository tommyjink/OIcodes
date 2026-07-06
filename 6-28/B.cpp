#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int dep[N];
int a[N];
void solve()
{ 
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=dep[a[i]];

    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[i-1])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<N;i++)
        dep[i]=dep[i/2]+1;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
5
5
1 3 2 5 4
5
1 3 4 5 2
1
1
10
1 2 3 6 5 4 7 10 9 8
10
1 2 3 6 5 4 8 9 10 7
*/