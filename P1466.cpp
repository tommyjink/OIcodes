#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int M=1e6;
int n,sum,f[M],ans=0;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    sum=n*(n+1)/2;
    if(sum&1)
    {
        cout<<"0";
        return 0;
    }
    for(int i=0;i<(1<<(n/2));i++)
    {
        int cnt=0;
        for(int j=1;j<=n/2;j++)
            if(i&(1<<(j-1)))
                cnt+=j;
        f[cnt]++;
    }
    for(int i=0;i<(1<<(n-n/2));i++)
    {
        int cnt=0;
        for(int j=1;j<=(n-n/2);j++)
            if(i&(1<<(j-1)))
                cnt+=j+n/2;
        if(sum/2>=cnt)
            ans+=f[sum/2-cnt];
    }
    cout<<ans/2<<endl;
    return 0;
}