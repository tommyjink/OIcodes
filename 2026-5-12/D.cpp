#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=25;
int n,a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=1e9;
    for(int i=1;i<(1ll<<n);i++)
    {
        int now=0,cnt=0;
        for(int j=1;j<=n;j++)
            if(i&(1ll<<(j-1)))now^=a[j],cnt++;
        if(now==0&&cnt%2==0)ans=min(ans,cnt);
        // if(now==0&&cnt==3){
        //     for(int j=1;j<=n;j++)
        //     if(i&(1ll<<(j-1)))cout<<j<<"!";cout<<endl;}
    }
    if(ans>n)cout<<"No"<<endl;
    else cout<<"Yes"<<endl<<ans<<endl;
    return 0;
}