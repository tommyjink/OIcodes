#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=63;
int n,m,cnt[N+10],a[N+10],ans=0;
signed main()
{
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    for(int j=1;j<=N;j++)
        if(m&(1ll<<(j-1)))
            a[j]=true;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=1;j<=N;j++)
        {
            if(x&(1ll<<(j-1)))
            {
                cnt[j]++;
                break;
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(cnt[i]&&a[i])
            cnt[i]--;
        else if(a[i])
        {
            int p=i;
            while(cnt[p]==0&&p<=N)p++;
            if(p>N)
            {
                cout<<"-1"<<endl;
                return 0;
            }
            cnt[p]--;
            for(int j=p-1;j>=i;j--)
                cnt[j]++,ans++;
        }
        cnt[i+1]+=cnt[i]/2;
    }
    cout<<ans<<endl;

    return 0;
}