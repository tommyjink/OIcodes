#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],cnt=0;
void solve()
{
    cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
            b[++cnt]=a[i];
    }
    if(cnt>=2)
    {
        cout<<b[1]<<" "<<b[2]<<endl;
        return;
    }
    
    if(n<=100)
    {
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if((a[j]%a[i])%2==0)
                {
                    cout<<a[i]<<" "<<a[j]<<endl;
                    return;
                }
        cout<<"-1"<<endl;
    }
    else
    {
        for(int i=1;i<=n-1;i++)
            if((a[i+1]%a[i])%2==0)
            {
                cout<<a[i]<<" "<<a[i+1]<<endl;
                return;
            }
        cout<<"-1"<<endl;

    }
    return;
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}