#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n;
map<int,int> fa;
struct node
{
    int l,r;
}a[N];
bool cmp(node x,node y)
{
    if(x.r!=y.r)return x.r<y.r;
    return x.l<y.l;
}
int find(int x)
{
    if(!fa.count(x))fa[x]=x;
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void solve()
{
    fa.clear();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        int x=find(a[i].l);
        if(x>a[i].r)
        {
            cout<<"No"<<endl;
            return;
        }
        fa[x]=x+1;
    }
    cout<<"Yes"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
