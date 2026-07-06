#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=200;
int n,k,q,tag[N],tt[N],qq=0,done[N],a[N];
vector<int> v[N];
int mp[N][N];
pii b[N];
void solve()
{
    n=qq=k=q=0;
    cin>>n>>k>>q;
    for(int i=1;i<=q;i++)
    {
        int c,l,r;
        cin>>c>>l>>r;
        if(c==1)
            for(int j=l;j<=r;j++)
                tag[j]++;
        else
        {
            qq++;
            b[qq]=pii(l,r);
        }
    }
    sort(b+1,b+1+qq);
    for(int i=1;i<=qq;i++)
    {
        for(int j=b[i].first;j<=b[i].second;j++)
        {
            v[i].emplace_back(j);
            tt[j]++;
        }
    }
    for(int i=1;i<=n;i++)
        if(tt[i]&&tag[i])a[i]=k+1,done[i]=true;
    for(int i=1;i<=n;i++)
        if(!tt[i]&&tag[i])a[i]=k,done[i]=true;
    for(int i=1;i<=qq;i++)
    {
        for(auto j:v[i])
            if(done[j]&&a[j]<k)mp[i][a[j]]=true;
        for(auto j:v[i])
        {
            if(done[j])continue;
            for(int kk=0;kk<k;kk++)
            {
                if(!mp[i][kk])
                {
                    mp[i][kk]=true;
                    a[j]=kk;
                    done[j]=true;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(!done[i])a[i]=k+1;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    memset(tag,0,sizeof(tag));
    memset(tt,0,sizeof(tt));
    memset(tag,0,sizeof(tag));
    memset(done,0,sizeof(done));
    for(int i=0;i<N;i++)v[i].clear();
    memset(mp,0,sizeof(mp));
    memset(a,0,sizeof(a));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}