#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=1e3+10;
int n,m,fa[N],len=0;
int id[N],L[M],R[M],lazy[M],val[N];
vector<pii> num[N];
void init()
{
    len=sqrt(n);
    for(int i=1;i<=n;i++)
        id[i]=(i+len-1)/len,
        num[i].emplace_back(pii(id[i],1));
    for(int i=1;i<=id[n];i++)
        L[i]=(i-1)*len+1,R[i]=i*len;
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int getfa(int x)
{
    if(x==fa[x])return fa[x];
    else return (fa[x]=getfa(fa[x]));
}
void add(int l,int r,int d)
{
    if(id[l]==id[r])
    {
        for(int i=l;i<=r;i++)
            val[getfa(i)]+=d;
        return;
    }
    for(int i=l;i<=R[id[l]];i++)
        val[getfa(i)]+=d;
    for(int i=id[l]+1;i<=id[r]-1;i++)
        lazy[i]+=d;
    for(int i=L[id[r]];i<=r;i++)
        val[getfa(i)]+=d;
}
int query(int x)
{
    int res=val[getfa(x)];
    for(auto i:num[getfa(x)])
        res+=i.second*lazy[i.first];
    return res;
}
void merge(int x,int y)
{
    int fx=getfa(x),fy=getfa(y);
    if(fx==fy)return;
    vector<pii> tmp;
    for(auto i:num[fx])tmp.emplace_back(i);
    for(auto i:num[fy])tmp.emplace_back(i);
    sort(tmp.begin(),tmp.end());
    num[fx].clear();
    for(auto i:tmp)
    {
        if(num[fx].size()&&i.first==num[fx].back().first)
            num[fx].back().second+=i.second;
        else num[fx].emplace_back(i);
    }
    val[fx]+=val[fy];
    fa[fy]=fx;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y;
            cin>>x>>y;
            merge(x,y);
        }
        else if(op==2)
        {
            int l,r,d;
            cin>>l>>r>>d;
            add(l,r,d);
        }
        else
        {
            int x;
            cin>>x;
            cout<<query(x)<<endl;
        }
        // for(int j=1;j<=n;j++)
        // {
        //     int f=getfa(j);
        //     printf("getfa(%lld)=%lld\n",j,f);
        //     for(auto k:num[j])
        //         printf("pii(%lld,%lld)\n",k.first,k.second);
        //     for(int k=1;k<=id[n];k++)
        //         printf("lazy[%lld]=%lld\n",k,lazy[k]);
        // }
    }
    return 0;
}