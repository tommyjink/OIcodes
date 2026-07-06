#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
int n,a[N],b[N][N],mb[N],f[N];
struct node
{
    int x,y,z;
};
vector<node> v;
bool cmp(node x,node y)
{
    return x.z<y.z;
}
int getfa(int x)
{
    if(x==f[x])return f[x];
    else return f[x]=getfa(f[x]);
}
void merge(int x,int y)
{
    int fx=getfa(x),fy=getfa(y);
    if(fx!=fy)f[fx]=fy;
}
void solve()
{
    int ans=0;
    memset(mb,127,sizeof(mb));
    v.clear();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],f[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {   
            cin>>b[i][j],mb[i]=min(mb[i],b[i][j]);
            if(i!=j)v.push_back((node){i,j,b[i][j]});
        }
    sort(v.begin(),v.end(),cmp);
    for(auto V:v)
        if(getfa(V.x)!=getfa(V.y))
            ans+=V.z,merge(V.x,V.y);
    for(int i=1;i<=n;i++)
        ans+=mb[i]*(a[i]-1);
    cout<<ans<<endl;
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