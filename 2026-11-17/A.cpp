#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,l[N],r[N],t[N];
int id[N],tag[N];
bool cmp(int x,int y)
{
    return l[x]<l[y];
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>l[i]>>r[i]>>t[i],
        id[i]=i,tag[i]=0;
    sort(id+1,id+1+m,cmp);
    int nowr=1,nowt=1,ans=0,from=id[1];
    for(int ii=1;ii<=m;ii++)
    {
        int i=id[ii];
        if(l[i]>nowt){cout<<-1<<endl;return;}
        if(l[i]>nowr)ans++,tag[from]=1,nowr=nowt;
        nowr=max(nowr,r[i]);
        if(t[i]>nowt)nowt=t[i],from=i;
    }
    if(nowr<n&&nowt<n){cout<<-1<<endl;return;}
    if(nowr<n)ans++,tag[from]=1;
    cout<<ans<<endl;
    for(int i=1;i<=m;i++)
        cout<<tag[i];
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}