#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,cnt[N],m=0;
int a[N],b[N],id[N];
bool cmp(int x,int y){return b[x]<b[y];}
struct node{int id,b;};
bool operator <(node x,node y)
{
    return x.b==y.b?x.id<y.id:x.b<y.b;
}
vector<int> ans[N];
void solve()
{
    cin>>n;n=n*3;
    m=0;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i],id[i]=i,ans[i].clear(),cnt[i]=0;
    sort(id+1,id+1+n,cmp);
    set<node> s;
    for(int now=1;now<=n;now++)
    {
        int i=id[now];
        auto p=s.upper_bound({0,a[i]});
        if(p==s.end())
        {
            s.insert({i,b[i]});
            cnt[i]=1;
            ans[i].push_back(i);
        }
        else
        {
            cnt[p->id]++;
            ans[p->id].push_back(i);
            if(cnt[p->id]==3)s.erase(p),m++;
        }
    }
    if(m*3==n)
    {
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++)
            if(!ans[i].empty())
                cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }
    else cout<<"No"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}