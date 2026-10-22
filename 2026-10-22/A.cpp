#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=3e5+10;
int n,k,a[N];
int lg[N],f[N][21];
vector<pii> v;
void init()
{
    for(int i=2;i<N;i++)
        lg[i]=lg[i/2]+1;
    for(int i=1;i<=n;i++)
        f[i][0]=a[i];
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n-(1<<i)+1;j++)
            f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
}
int query(int l,int r)
{
    if(l>r)return -1;
    if(l==r)return a[l];
    int len=r-l+1,k=lg[len];
    return min(f[l][k],f[r-(1<<k)+1][k]);
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    init();
    // while(1)
    // {
    //     int l,r;
    //     cin>>l>>r;
    //     cout<<query(l,r)<<endl;
    // }
    int nowl=1,nowr=1;
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(query(mid,n)<a[i])l=mid;
            else r=mid-1;
        }
        
    }
    return 0;
}