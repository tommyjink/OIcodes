#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,f[N];
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    s=" "+s;
    int p=1,now=1,tot=0;
    f[0]=1;
    for(int i=1;i<=n;i++)
    {   
        if(s[i-1]=='+')
        {
            while(p<i)now=(now+f[p])%P,p++;
            f[i]=(tot+f[i-1])%P;
        }
        else if(s[i-1]=='|')
        {
            f[i]=now%P;
            tot=(tot+f[i-1])%P;
        }
        else
        {
            f[i]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(i==n||s[i]=='|')ans=(ans+f[i])%P;
    // for(int i=1;i<=n;i++)
    //     cout<<f[i]<<endl;
    cout<<ans<<endl;
    return 0;
}