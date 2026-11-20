#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,a[N],w[N];
int b[N],res=0;
void cop()
{
    for(int i=1;i<=n;i++)   
        b[i]=a[i];
}
void op(int x)
{
    int nxt=x%n+1;
    b[x]^=1;
    b[nxt]^=1;
    res+=w[x];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>w[i];
    int ans=1e18;
    for(int k=0;k<=1;k++)
    {
        for(int q=0;q<=1;q++)
        {
            cop();
            res=0;
            if(q)op(n);
            for(int i=1;i<=n-q;i++)
                if(b[i]!=k)op(i);
            if(b[n]==k&&b[1]==k)ans=min(ans,res);
        }   
    }
    if(ans==1e18)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}