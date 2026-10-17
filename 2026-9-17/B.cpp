#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,T,K,q;
pair<int,int>a[N];
int cal(int i,int c,int d)
{
    return abs(a[i].first*(T-c)+a[i].second*c-d*T);
}
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>T>>K;
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1);
    cin>>q;
    while(q--)
    {
        int c,d;
        cin>>c>>d;
        int l=1,r=n,ans=cal(1,c,d),len=2*K;
        while(r-l+1>2*len+5)
        {
            int mid=(l+r)>>1;
            int y=a[mid].first*(T-c)+a[mid].second*c;
            ans=min(ans,abs(y-d*T));
            if(y<d*T)l=mid-len+1;
            else r=mid+len-1;
        }
        for(int i=l;i<=r;i++)ans=min(ans,cal(i,c,d));
        int g=gcd(ans,T);
        cout<<ans/g<<" "<<T/g<<endl;
    }
    return 0;
}
