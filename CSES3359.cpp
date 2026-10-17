#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3005;
int n,vis[N][N];
string s[N],ans;
struct node
{
    int x,y;
};
vector<node> q[2*N];
bool cmp(node A,node B)
{
    if(A.x==B.x)return A.y<B.y;
    return A.x<B.x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i],s[i]=" "+s[i];
    q[0].push_back({1,1});
    for(int i=0;i<2*n-2;i++)
    {
        ans.push_back('Z');
        for(auto [x,y]:q[i])
            ans[i]=min(ans[i],s[x][y]);
        for(auto [x,y]:q[i])
        {
            if(ans[i]==s[x][y])
            {
                if(x+1<=n&&!vis[x+1][y])q[i+1].push_back({x+1,y}),vis[x+1][y]=true;
                if(y+1<=n&&!vis[x][y+1])q[i+1].push_back({x,y+1}),vis[x][y+1]=true;
            }
        }
    }
    ans.push_back(s[n][n]);
    cout<<ans<<endl;
    return 0;
}