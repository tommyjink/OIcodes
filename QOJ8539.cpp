#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=N*41;
int n,ans=0;
int nxt[M][2],cnt[M],l[M];
int tot=0,siz[M];
void dfs1(int x)
{

    // cout<<x<<"!"<<cnt[x]<<endl;
    if(!nxt[x][0])nxt[x][0]=++tot;
    if(!nxt[x][1])nxt[x][1]=++tot;
    if(cnt[x]==1&&siz[x]==1)
    {
        l[x]=2;
        return;
    }
    if(cnt[x]==2&&siz[x]==2)
    {
        cnt[x]=0;
        siz[nxt[x][0]]=cnt[nxt[x][0]]=1;
        siz[nxt[x][1]]=cnt[nxt[x][1]]=1;
        l[nxt[x][0]]=2;
        l[nxt[x][1]]=2;
        l[x]=3;
        ans+=2;
        return;
    }
    if(!siz[nxt[x][0]]||l[nxt[x][0]]<l[nxt[x][1]])
    {
        // cout<<"?"<<endl;
        cnt[x]--;
        cnt[nxt[x][0]]++;
        siz[nxt[x][0]]++;
        ans++;
        dfs1(nxt[x][0]);
    }
    else
    {
        cnt[x]--;
        cnt[nxt[x][1]]++;
        siz[nxt[x][1]]++;
        ans++;
        dfs1(nxt[x][1]);
    }
    l[x]=min(l[nxt[x][0]],l[nxt[x][1]])+1;
    siz[x]=siz[nxt[x][0]]+siz[nxt[x][1]]+cnt[x];
}
int dfs(int x)
{
    siz[x]=cnt[x];
    for(int c=0;c<=1;c++)
    {
        if(nxt[x][c])
            siz[x]+=dfs(nxt[x][c]);
    }
    if(cnt[x]==1&&siz[x]==1){l[x]=2;return siz[x];}
    else if(siz[x]==0)return 0;
    else
    {
        while(cnt[x])
            dfs1(x);
    }
    l[x]=min(l[nxt[x][0]],l[nxt[x][1]])+1;
    return siz[x];
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        int p=0;
        for(char cc:s)
        {
            int c=cc-'0';
            if(!nxt[p][c])nxt[p][c]=++tot;
            p=nxt[p][c];
        }
        cnt[p]++;
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}