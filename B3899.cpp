#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+10;
int n,k,M;
int a[N],b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>M;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i],a[i]-=b[i];
    for(int i=1;i<=n-k+1;i++)
    {
        int sum=0;
        for(int j=i;j<=i+k-1;j++)
            sum+=a[j];
        // cout<<sum<<","<<endl;
        if(sum>=M)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}