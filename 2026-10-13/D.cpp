#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=505;
int n,k,a[N],b[N],ans=0;
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    swap(a[j],a[j+1]);
                    b[++ans]=j;
                }   
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=ans;i++)
            cout<<b[i]<<" ";
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}