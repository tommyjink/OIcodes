#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,p[N],fa[N];
struct pii
{
    int x,y,z;
};
bool operator <(pii x,pii y)
{
    return x.z<y.z;
}
vector<pii> e;
int getfa(int x)
{
    if(x==fa[x])return fa[x];
    else return (fa[x]=getfa(fa[x]));
}
void solve()
{
    e.clear();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i],fa[i]=i;
    sort(p+1,p+1+n);
    n=unique(p+1,p+1+n)-p-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j*p[i]<=p[n];j++)
        {
            int l=lower_bound(p+1,p+1+n,j*p[i])-p;
            if(j==1)l++;
            if(p[l]<(j+1)*p[i]&&p[l]>=j*p[i]&&l>=1&&l<=n)
                e.push_back((pii){i,l,p[l]-j*p[i]});
        }
    }
    int ans=0;
    sort(e.begin(),e.end());
    for(pii i:e)
    {
        if(getfa(i.x)!=getfa(i.y))
        {
            fa[getfa(i.x)]=fa[getfa(i.y)];
            ans+=i.z;
            // cout<<i.x<<" "<<i.y<<endl;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _T;
    cin>>_T;
    while(_T--)
        solve();
    return 0;
}