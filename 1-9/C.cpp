#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=(1<<16)+10;
const int MOD=998244353;
int c,t,sd,k,n,q,p[N],s[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    if(t==1) cin>>sd;
    cin>>k;
    n=(1<<k);
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        s[i+1]=(s[i]+p[i])%MOD;
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int a,l,r,xor_s=0;
        cin>>a>>l>>r;
        int p_out=(s[n]-s[r+1]+s[l]+2*MOD)%MOD;
        for(int j=1;j<=a;j++)
        {
            int x;
            if(t==0) cin>>x;
            else x=sd*i%n*j%n*50007%n;
            int w_in=0;
            for(int v=l;v<=r;v++)
            {
                if(__builtin_popcountll(v|x)%2==0)
                    w_in=(w_in+p[v])%MOD;
            }
            int ans=(p_out+w_in)%MOD;
            if(t==0) cout<<ans<<(j==a?"":" ");
            else xor_s^=ans;
        }
        if(t==0) cout<<endl;
        else cout<<xor_s<<endl;
    }
    return 0;
}