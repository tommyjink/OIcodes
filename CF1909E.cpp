#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
int n,m,x[N],y[N],ans=1e15,as;
vector<int> v[N];
bool check(int s)
{
    for(int i=1;i<=m;i++)
        if((s&(1ll<<(x[i]-1)))&&!(s&(1ll<<(y[i]-1))))
            return false;
    return true;
}
void cal()
{
    ans=1e15;
    for(auto i:v[n])
    {
        if(!check(i))continue;
        cout<<__builtin_popcount(i)<<endl;
        for(int j=1;j<=n;j++)
            if(i&(1ll<<(j-1)))
                cout<<j<<" ";
        cout<<endl;
        return;
    }
    cout<<"-1"<<endl;

}
void solve() 
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>x[i]>>y[i];
    if(n<20)cal();
    else 
    {
        cout<<n<<endl;
        for(int i=1;i<=n;i++)cout<<i<<" ";
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<(1ll<<i);j++)
        {
            int s=0;
            for(int k=1;k<=i;k++)
                if(j&(1ll<<(k-1)))
                    for(int kk=k;kk<=i;kk+=k)
                        s^=(1ll<<(kk-1));
            if(__builtin_popcount(s)<=i/5)v[i].push_back(j);
        }
    }
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}