#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,a[N],k[N],t[N],vis[N],ans=0,tot=0;
vector<int> c[N],d[N],e[N],f[N];
map<int,int> mp;
int num(int x)
{
    if(!mp.count(x))
        mp[x]=++tot;
    return mp[x];
}
signed main()
{
    freopen("company.in","r",stdin);
    freopen("company.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[num(x)]=y;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        // cout<<"!!";
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x,y;
            cin>>x>>y;
            c[i].push_back(num(x));
            d[i].push_back(y);
        }
        // cout<<"??";
        cin>>t[i];
        for(int j=1;j<=t[i];j++)
        {
            int x,y;
            cin>>x>>y;
            e[i].push_back(num(x));
            f[i].push_back(y);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vis[j])continue;
            int tag=true;
            for(int ii=0;ii<(int)c[j].size();ii++)
                if(a[c[j][ii]]<d[j][ii])
                    tag=false;
            if(tag)
            {
                ans++;
                vis[j]=true;
                for(int ii=0;ii<(int)e[j].size();ii++)
                    a[e[j][ii]]+=f[j][ii];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*

sample.in
2 2 1 1 2
5
1 3 1
0
2 1 1 2 1
2 3 2 2 1
3 1 5 2 3 3 4
1 2 5
3 2 1 1 1 3 4
1 1 3
0
1 3 2
sample.out
4


(2,1,0)
______

1,1,0
0,1,2
(2,2,2)


0,0,1
0,0,0
(2,2,2)


0,0,0
0,0,2
(2,2,4)


1,1,4
3,0,0
(5,2,4)
______


5,3,4
0,5,0


*/