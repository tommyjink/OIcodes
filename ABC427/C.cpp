#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1000;
int n,m,ans=N,x[N],y[N];
void print(int x)
{
    while(x)
    {
        cout<<x%2<<" ";
        x/=2;
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<(1ll<<n)-1;i++)
    {
        int res=0;
        for(int j=1;j<=m;j++)
        {
            if(((1ll<<(x[j]-1))&i)&&((1ll<<(y[j]-1))&i))
                res++;
            if(!((1ll<<(x[j]-1))&i)&&!((1ll<<(y[j]-1))&i))
                res++;
            // cout<<x[j]<<","<<y[j]<<endl;
            // print((1ll<<(x[j]-1))&i);
            // cout<<"___";
        }
        ans=min(ans,res);
        // cout<<res<<"!"<<i<<endl;
        // print(i);
    }
    cout<<ans<<endl;
    return 0;
}