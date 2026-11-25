#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=25;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0}; 
int n,mp[10*N][10*N],op[N];
int tag[10*N][10*N];
string s;
vector<pii> ans;
void dfs(int k,int x,int y)
{
    if(k>n)
    {
        tag[x][y]=true;
        return;
    }
    int xx=x+dx[op[k]],yy=y+dy[op[k]];
    dfs(k+1,x,y);
    if(!mp[xx][yy])
    {
        mp[xx][yy]=true;
        dfs(k+1,xx,yy);
        mp[xx][yy]=false;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='R')op[i]=0;
        if(s[i]=='L')op[i]=1;
        if(s[i]=='D')op[i]=2;
        if(s[i]=='U')op[i]=3;
    }
    dfs(1,n+2,n+2);
    for(int i=0;i<=n*2+10;i++)
        for(int j=0;j<=n*2+10;j++)
            if(tag[i][j])ans.push_back({i-n-2,j-n-2});
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans)cout<<x<<" "<<y<<endl;
    return 0;
}