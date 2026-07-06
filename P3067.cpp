//The Version 1.0 of P3067_V2.cpp
//Reason: TLE
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=30;
int n,a[N],b[N],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<(1ll<<n);i++)
    {
        int cnt=0,sum=0,tag=0;
        for(int j=1;j<=n;j++)
            if(i&(1<<(j-1)))
                b[++cnt]=a[j],sum+=a[j];
        if(sum&1)continue;
        // for(int i=1;i<=cnt;i++)
        //     cout<<b[i]<<" ";
        // cout<<endl;
        map<int,bool> mp;
        for(int j=1;j<(1ll<<(cnt/2));j++)
        {
            int tot=0;
            for(int k=1;k<=cnt/2;k++)
                if(j&(1<<(k-1)))
                    tot+=b[k];
            mp[tot]=true;
        }
        for(int j=0;j<(1ll<<(cnt-cnt/2));j++)
        {
            int tot=0;
            for(int k=1;k<=cnt-cnt/2;k++)
                if(j&(1<<(k-1)))
                    tot+=b[cnt/2+k];
            if(mp.count(sum/2-tot))
                tag=1;
        }
        // if(tag)
        // {
        //     for(int i=1;i<=cnt;i++)
        //         cout<<b[i]<<" ";
        //     cout<<endl;
        // }
        ans+=tag;
    }
    cout<<ans<<endl;
    return 0;
}