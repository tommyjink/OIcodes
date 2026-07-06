#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10;
int n,phi[N],tag[N],prime[N],cnt=0,sum[N];
void Eulor()
{
    phi[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!tag[i])prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&prime[j]*i<N;j++)
        {
            tag[prime[j]*i]=true;
            if(i%prime[j]==0)
            {
                phi[prime[j]*i]=phi[i]*prime[j];
                break;
            }
            phi[prime[j]*i]=phi[prime[j]]*phi[i];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    Eulor();
    for(int i=1;i<N;i++)
        sum[i]=sum[i-1]+phi[i];
    // for(int i=1;i<=100;i++)
    //     cout<<prime[i]<<" ";
    int ans=0;
    for(int i=1;i<=cnt&&prime[i]<=n;i++)
        ans+=2*(sum[n/prime[i]])-1;
    cout<<ans<<endl;
    return 0;
}