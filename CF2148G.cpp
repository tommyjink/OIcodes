#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
void solve()
{
    int ans=0,now=0;
    cin>>n;
    for(int i=1;i<=n;i++)b[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    
        if(i==1)now=a[i];
        else
        {
            if(a[i]%now)ans=i-1;
            now=gcd(now,a[i]);
        } 
        for(int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j==0)
            {
                b[j]++;
                if(b[j]!=i)ans=max(ans,b[j]);
                if(j*j!=a[i])
                {
                    b[a[i]/j]++;
                    if(b[a[i]/j]!=i)ans=max(ans,b[a[i]/j]);
                }
            }
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}