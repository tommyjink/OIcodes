#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5010,INF=1e18;
int n,len[N],to[N][10],dp[(1<<18)][10],vis[30],cnt[300],need[300];
string s[N],t=" luolikong";
vector<int> g[300];
int chk(string s)
{
    int res=0;
    memset(vis,0,sizeof(vis));
    for(auto c:s)
        if(c=='l'||c=='u'||c=='o'||c=='i'||c=='k'||c=='n'||c=='g')
            vis[c-'a']=1;
    for(int i=0;i<26;i++)res+=vis[i];
    return res<=1;
}
int trans(int x,int st)
{
    for(auto c:s[x])
        if(st<9&&c==t[st+1])st++;
    return st;
}
signed main()
{
    cin>>n;
    int sum=0,fl=1;
    need['l']=2;
    need['u']=1;
    need['o']=2;
    need['i']=1;
    need['k']=1;
    need['n']=1;
    need['g']=1;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        len[i]=s[i].size();
        sum+=len[i];
        fl&=chk(s[i]);
        for(auto c:s[i])
            if(c=='l'||c=='u'||c=='o'||c=='i'||c=='k'||c=='n'||c=='g')
            {
                g[c].push_back(len[i]);
                break;
            }
    }
    if(fl)
    {
        int ans=INF;
        for(char c:{'l','u','o','i','k','n','g'})
        {
            if(g[c].size()<need[c])
            {
                cout<<sum<<endl;
                return 0;
            }
            sort(g[c].begin(),g[c].end());
            int res=0;
            for(int i=0;i<g[c].size()-need[c]+1;i++)res+=g[c][i];
            ans=min(ans,res);
        }
        cout<<sum-ans<<endl;
        return 0;
    }
    if(n<=18)
    {
        for(int i=1;i<=n;i++)
            for(int j=0;j<=8;j++)
                to[i][j]=trans(i,j);
        for(int i=0;i<(1<<n);i++)
            for(int j=0;j<=8;j++)
                dp[i][j]=-INF;
        dp[0][0]=0;
        int ans=0;
        for(int s=0;s<(1<<n);s++)
            for(int j=0;j<=8;j++)
            {
                if(dp[s][j]<0)continue;
                ans=max(ans,dp[s][j]);
                for(int i=0;i<n;i++)
                {
                    if(s>>i&1)continue;
                    int p=to[i+1][j];
                    if(p==9)continue;
                    dp[s|(1<<i)][p]=max(dp[s|(1<<i)][p],dp[s][j]+len[i+1]);
                }
            }
        cout<<ans<<endl;
        return 0;
    }
    cout<<0<<endl;
    return 0;
}
