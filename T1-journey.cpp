#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,t,p[N],pr[N],pp[N],tot=0,d[N],f[N];
bool check(int x)
{
    deque<int> dq;
    dq.push_back(1);
    f[1]=0;
    for(int i=2;i<=n;i++)
    {
        while(!dq.empty()&&dq.front()<i-x)
            dq.pop_front();
        f[i]=f[dq.front()]+d[i];
        while(!dq.empty()&&f[dq.back()]>f[i])
            dq.pop_back();
        dq.push_back(i);
    }
    return f[n]+n-1<=t;
}
signed main()
{
    freopen("journey.in","r",stdin);
    freopen("journey.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>t;
    for(int i=1;i<=n-1;i++)
        cin>>pp[i];
    for(int i=n-1;i>=1;i--)
    {
        if(pp[i]<p[tot]||i==n-1)
            p[++tot]=pp[i],pr[tot]=i;
    }
    for(int i=1;i<=tot/2;i++)
        swap(p[i],p[tot-i+1]),
        swap(pr[i],pr[tot-i+1]);
    // for(int i=1;i<=tot;i++)
    //     cout<<p[i]<<" "<<pr[i];
    for(int i=1;i<=n-1;i++)
        cin>>d[i];
    int l=1,r=tot;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(pr[mid]))
            r=mid;
        else l=mid+1;
    }
    cout<<p[l];
    return 0;
}