#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+10;
int n,k,m,a[N],p[N],d[N],c[N],ans;
priority_queue<int,vector<int>,greater<int> > q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    m=k+1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)d[i]=(p[i]-a[i]+m)%m;
    c[1]=d[1];
    for(int i=2;i<=n;i++)c[i]=d[i]-d[i-1];
    int s=0,g=0;
    // for(int i=1;i<=n;i++)cout<<d[i]<<" ";cout<<endl;
    // for(int i=1;i<=n;i++)cout<<c[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(c[i]>0)
        {
            s+=c[i];
            if(!q.empty()&&q.top()<c[i])
            {
                int t=q.top();
                q.pop();
                q.push(c[i]);
                g+=c[i]-t;
            }
        }
        else if(c[i]<0)q.push(m+c[i]);
    }
    ans=s-g;
    cout<<ans<<endl;
    return 0;
}
