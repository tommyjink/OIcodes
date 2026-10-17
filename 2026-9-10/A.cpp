#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,a[N],b[N];
void solve()
{
    cin>>n;
    int maxa=-INF,mina=INF;
    int maxb=-INF,minb=INF;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
        mina=min(mina,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        maxb=max(maxb,b[i]);
        minb=min(minb,b[i]);
        ans+=abs(a[i]-b[i]);
    }
    // cout<<mina<<" "<<maxa<<endl;
    int cnt1=0,cnt2=0;
    int cnt3=0,cnt4=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==minb||a[i]<=minb)cnt3++;
        if(b[i]==maxb||a[i]>=maxb)cnt4++;
        if(b[i]==minb&&a[i]==maxa)cnt1++;
        if(b[i]==maxb&&a[i]==mina)cnt2++;
    }
    // cout<<cnt3<<" "<<cnt4<<" "<<cnt1<<" "<<cnt2<<endl;
    if(n==1)cout<<(a[1]==b[1]?ans:-1)<<endl;
    else if(mina<=minb&&maxa>=maxb)
    {
        if(n==2)cout<<(a[1]<=b[1]&&b[1]<=b[2]&&b[2]<=a[2]?ans:-1)<<endl;
        else if(cnt3==2&&cnt4==2&&cnt1==1&&cnt2==1)
        {
            int res=INF;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==maxa||a[i]==mina)continue;
                res=min(res,abs(a[i]-minb)+abs(minb-b[i])-abs(a[i]-b[i]));
                res=min(res,abs(a[i]-maxb)+abs(maxb-b[i])-abs(a[i]-b[i]));
            }
            // cout<<res<<"!"<<endl;
            cout<<ans+res<<endl;
        }
        else cout<<ans<<endl;
    }
    else cout<<"-1"<<endl;
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}