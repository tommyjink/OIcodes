#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,ans=1;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        int res=0;
        while(n%i==0)n/=i,res++;
        if(res)ans=ans*(res*2+1);
    }
    if(n>1)ans=ans*3;
    cout<<ans<<endl;
    return 0;
}