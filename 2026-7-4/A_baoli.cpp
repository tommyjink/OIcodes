#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=20;
int n,K,a[N],b[N],ans=0;
vector<int> fin;
inline int f(int x)
{
    return (x+n-1)%n+1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    cin>>n>>K;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<(1ll<<n);i++)
    {
        vector<int> tmp;
        for(int j=1;j<=n;j++)
            if(i&(1ll<<(j-1)))b[j]=1,tmp.push_back(a[j]);
            else b[j]=0;
        int res=0;
        for(int j=1;j<=n;j++)
        {
            for(int k=j-K;k<=j+K;k++)
            {
                int x=f(j),y=f(k);
                if(b[x]&&!b[y])res+=a[x];
                else if(!b[x]&&b[y])res-=a[x];
            }
        }
        if(ans<=res)fin=tmp,ans=res;
    }
    cout<<ans<<endl;
    for(auto i:fin)cout<<i<<" ";
    return 0;
}