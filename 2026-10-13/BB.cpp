#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,p,q,a[N],y[N],b[N],t[N],ans[N];
string s;
void solve()
{
    cin>>n>>p>>q>>s;
    s=" "+s;
    int now=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1')now++;
        else a[++cnt]=now;
    }
    int d=p-q;
    for(int i=1;i<=d;i++)
    {
        int k=0;
        for(int j=i;j<=cnt;j+=d)
            k++,y[k]=a[j]-(k-1)*q;
        priority_queue<int> pq;
        int U=now-(k-1)*q;
        for(int j=1;j<=k;j++)
        {
            y[j]=max(0ll,min(U,y[j]));
            pq.push(y[j]);
            pq.push(y[j]);
            pq.pop();
            t[j]=pq.top();
        }
        int mn=U;
        for(int j=k;j>=1;j--)
            mn=min(mn,t[j]),
            b[i+(j-1)*d]=mn+(j-1)*q;
    }
    for(int i=1;i<=n;i++)ans[i]=1;
    for(int i=1;i<=cnt;i++)ans[i+b[i]]=0;
    for(int i=1;i<=n;i++)cout<<ans[i];
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}