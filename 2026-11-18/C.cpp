#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,a[N],b[N],rt[N],fa[N],siz[N];
int nxt[N*30][2],cnt[N],lazy[N*30];
queue<signed> q;
vector<int> V[N*30];
struct node{int x,y,z;}e[N];
bool cmp(node x,node y){return x.z<y.z;}
int getfa(int x){return x==fa[x]?x:(fa[x]=getfa(fa[x]));}
int tot()
{
    int res=q.front();
    q.pop();
    return res;
}
void cl(int x)
{
    nxt[x][0]=nxt[x][1]=0;
    cnt[x]=0;
    lazy[x]=0;
    q.push(x);
}
void insert(int p,int x,int id)
{
    cnt[p]++;
    for(int i=29;i>=0;i--)
    {
        int c=(x>>i)&1ll;
        if(!nxt[p][c])nxt[p][c]=tot();
        p=nxt[p][c];
        cnt[p]++;
    }
    V[p].push_back(id);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n*30;i++)q.push(i);
    for(int i=1;i<=n;i++)
        rt[i]=tot(),fa[i]=i,siz[i]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        insert(rt[i],a[i],i);
    }
    for(int i=1;i<n;i++)
        cin>>e[i].x>>e[i].y>>e[i].z;
    sort(e+1,e+n,cmp);
    for(int i=1;i<n;i++)
    {
        int x=getfa(e[i].x),y=getfa(e[i].y),z=e[i].z;
        if(siz[x]>siz[y])swap(x,y);
    }
    return 0;
}