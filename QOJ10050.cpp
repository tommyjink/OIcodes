#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
int n,a[N],b[N],c[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i+n]=a[i];
    for(int i=2;i<=n+1;i++)cin>>b[i];
    for(int i=n+2;i<=2*n;i++)b[i]=b[i-n];
    for(int i=1;i<=2*n;i++)b[i]+=b[i-1];
    for(int i=1;i<=2*n;i++)c[i]=a[i]-b[i];
    deque<int> q;
    int ans=1e10;
    for(int i=1;i<=2*n;i++)
    {
        while(!q.empty()&&c[i]>c[q.back()])q.pop_back();
        while(!q.empty()&&q.front()<=i-n)q.pop_front();
        q.push_back(i);
        if(i>=n)ans=min(ans,c[q.front()]+b[i-n+1]);
    }
    cout<<ans<<endl;
    return 0;
}