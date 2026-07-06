#include<bits/stdc++.h>
#define int long long
#define lowbit(x) x&(-x)
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],k[N],l[N],r[N],ans[N],t[N],num[N];
vector<int> ed[N],st[N];
struct node
{
    int a,k,num;
}b[N];
bool cmp(node x,node y)
{
    return x.a<y.a;
}
void add(int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
int sum(int l,int r)
{
    return query(r)-query(l-1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>b[i].a,b[i].num=i;
    for(int i=1;i<=n;i++)
        cin>>b[i].k;
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++)
        a[i]=b[i].a,k[i]=b[i].k,num[i]=b[i].num;
    for(int i=1;i<=n;i++)
    {
        l[i]=lower_bound(a+1,a+1+n,a[i]-k[i])-a;
        r[i]=upper_bound(a+1,a+1+n,a[i]+k[i])-a-1;
        ed[r[i]].push_back(i);
        st[l[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)add(i,1);
    for(int i=1;i<=n;i++)
    {
        ans[num[i]]+=sum(l[i],i);
        for(auto j:ed[i])add(j,-1);
    }
    memset(t,0,sizeof(t));
    for(int i=1;i<=n;i++)add(i,1);
    for(int i=n;i>=1;i--)
    {
        ans[num[i]]+=sum(i,r[i])-1;
        for(auto j:st[i])add(j,-1);
    }
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" "<<k[i]<<endl;
    // cout<<"_______"<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<l[i]<<","<<r[i]<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}