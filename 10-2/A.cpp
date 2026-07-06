#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    int now=0,ans=0;
    for(int i=32;i>=1;i--)
    {
        int cnt=0;
        now|=(1ll<<(i-1));
        for(int j=1;j<=n;j++)
        {
            b[j]=a[j];
            while((now&b[j])&&(b[j]<=1e9))
                b[j]<<=1,cnt++;
            if(b[j]>1e9)cnt=1e9;
        }
        if(cnt<=m)
        {
            m-=cnt;
            for(int j=1;j<=n;j++)
                a[j]=b[j];
        }
        else now^=(1ll<<(i-1)),ans|=(1ll<<(i-1));
    }
    cout<<ans<<endl;
    return 0;
}