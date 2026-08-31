#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=55,M=405;
int n,m,a[N][M];
vector<pii> ans;
void solve()
{

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            cin>>a[i][j];
    if(n==2)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[1][i]==1)cnt++;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]!=1)swap(a[i][j],a[n-i+1][m-j+1]);
            }
        }
        for(int i=1;i<=n;i++)
            ans.push_back({i,n-i+1});
    }
    cout<<ans.size()<<endl;
    for(pii i:ans)cout<<i.first<<" "<<i.second<<endl;
    return 0;
}