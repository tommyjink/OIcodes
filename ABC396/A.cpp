#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,a[1000000];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>=3&&a[i]==a[i-1]&&a[i-1]==a[i-2])
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}