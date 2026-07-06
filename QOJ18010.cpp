#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;

const int N=1000000+10;
int n,ans;
int a[N],pre[N],suf[N],sufi[N];

int C(int x)
{
    return x*(x-1)/2;
}

void solve()
{
    cin>>n;
    pre[0]=0;
    suf[n+1]=sufi[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]=suf[i+1]+pre[i];
        sufi[i]=sufi[i+1]+i*pre[i];
    }
    ans=0;
    for(int l=1;l<=n;l++)
    {
        int p=0,cnt=0,res=0;
        for(int i=1;i<=n;i++)
        {
            p+=a[i];
            if(i>=l)cnt++;
            int x=min(p,cnt);
            res+=x*(2*p-x+1)/2;
            p-=x;
        }
        ans=max(ans,res);
        int len=n-l+1;
        int q=len*(len+1)/2;
        int w=sufi[l]-(l-1)*suf[l];
        for(int r=l;r<=n;r++)
        {
            int q1=q-(n-r+1);
            int w1=w-suf[r];
            ans=max(ans,w1-C(q1));
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
