#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n,m,tot;
int col[N],bel[N],tag[N],cnt[N],q[N],siz[N][2];
vector<int> e[N];
list<int> ls;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        e[i].clear();
        col[i]=bel[i]=tag[i]=cnt[i]=0;
        siz[i][0]=siz[i][1]=0;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    ls.clear();
    for(int i=1;i<=n;i++)
        ls.push_back(i);
    tot=0;
    while(!ls.empty())
    {
        int l=1,r=1;
        q[1]=ls.front();
        ls.pop_front();
        bel[q[1]]=++tot;
        siz[tot][0]++;
        while(l<=r)
        {
            int x=q[l++];
            for(auto y:e[x])
                tag[y]=x;
            for(auto it=ls.begin();it!=ls.end();)
            {
                int y=*it;
                if(tag[y]!=x)
                {
                    col[y]=col[x]^1;
                    bel[y]=tot;
                    siz[tot][col[y]]++;
                    q[++r]=y;
                    it=ls.erase(it);
                }
                else it++;
            }
        }
    }
    for(int x=1;x<=n;x++)
        for(auto y:e[x])
            if(bel[x]==bel[y]&&col[x]==col[y])cnt[x]++;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]!=siz[bel[i]][col[i]]-1)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
