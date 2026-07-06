#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N],b[N];
void solve()
{
    cin>>n>>q;
    for(int i=0;i<=n+1;i++)
        a[i]=b[i]=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x<=n)a[x]=y;
    }
    int ll=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=min(a[i],a[i-1]);
        if(a[i])ll=i;
    }
    for(int i=n;i>=0;i--)
        b[i]=b[i+1]+(i+1)*(a[i]-a[i+1]);
    while(q--)
    {
        int x;
        cin>>x;
        if(x>b[0])
        {
            cout<<"-1"<<endl;
            continue;
        }
        int l=0,r=n+1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(b[mid]>=x)l=mid+1;
            else r=mid;
        }
        int ans=a[l]+(x-b[l]+l-1)/(l);
        if(x==0&&ll==0)cout<<"1"<<endl;
        else if(x==0)cout<<"-1"<<endl;
        else if(ans==1&&x<ll+1)
            cout<<"2"<<endl;
        else cout<<ans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("mexdnc2.in","r",stdin);
    // freopen("mexdnc.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
253865

1
4 5
0 3
1 4
2 1
4 1
0
3
4
7
8

1
6 6
0 1
1 1
2 1
3 1
4 1
5 1
2
1
10
3
0
9


2
2
-1
2
-1
-1
*/