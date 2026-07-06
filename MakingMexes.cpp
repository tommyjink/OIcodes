#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N],tag[N],sum[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        tag[a[i]]++;
    for(int i=0;i<=n;i++)
        sum[i]=sum[i-1]+(bool)tag[i];
    if(!tag[0])cout<<"0"<<endl;
    else cout<<tag[0]<<endl;
    for(int i=1;i<=n;i++)
    {
        if(sum[i-1]==i)
            cout<<tag[i]<<endl;
        else cout<<max(i-sum[i-1],tag[i])<<endl;
    }
    return 0;
}