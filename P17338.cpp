#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N],tot=0,b[N],cnt=0,tag[N];
void spl(int l,int r)
{
    if(r-l+1<=4)return;
    int mid=(l+r)>>1;
    b[++cnt]=mid;
    spl(l,mid);
    spl(mid+1,r);
}
void solve()
{
    tot=cnt=0;
    cin>>n>>k;
    if(k*4>(1ll<<n)){cout<<"No"<<endl;return;}
    a[++tot]=0;
    for(int i=1;i<=n;i++)
    {
        int tt=tot;
        for(int j=tt;j>=1;j--)
        {
            a[++tot]=a[j]+(1ll<<(i-1));
        }
    }
    b[++cnt]=tot;
    spl(1,tot);
    cout<<"Yes"<<endl;
    for(int i=1;i<=tot;i++)tag[i]=0;
    for(int i=1;i<=k;i++)tag[b[i]]=1;
    for(int i=1;i<=tot;i++)
    {
        int r=i;
        while(!tag[r])r++;
        cout<<r-i+1<<" ";
        for(int j=i;j<=r;j++)cout<<a[j]<<" ";
        cout<<endl;
        i=r;
    }
    // for(int i=1;i<=tot;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}