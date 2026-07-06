#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N];
map<int,int> mp[20];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int cnt=0,x=a[i];
        a[i]%=m;
        while(x)x/=10,cnt++;
        if(!cnt)cnt++;
        if(!mp[cnt].count(a[i]))
            mp[cnt][a[i]]=0;
        mp[cnt][a[i]]++;
        // printf("mp[%lld][%lld]++\n",cnt,a[i]);
    }
    int ans=0;
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[j]=a[j]*10%m;
            ans+=mp[i][(m-a[j])%m];
            // printf("ans+=mp[%lld][%lld]\n",i,(m-a[j])%m);
        }
    }
    cout<<ans<<endl;
    return 0;
}