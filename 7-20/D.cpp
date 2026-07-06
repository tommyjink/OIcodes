#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,k,id[N],a[N],len=0,tag[N],cnt[N],now=0,ans[N];
struct node
{
    int l,r,id;
}q[N];
bool cmp(node x,node y)
{
    return (id[x.l]==id[y.l])?(x.r<y.r):(id[x.l]<id[y.l]);
}
bool check(int x)
{
    return tag[x]&&abs(tag[x]-(cnt[x]-tag[x]))<=k;
}
void add(int i)
{
    // printf("add(%lld)\n",i);
    int x=a[i],tmp=check(x);
    tag[x]++;
    if(check(x)&&!tmp)now++;
    if(!check(x)&&tmp)now--;
    // cout<<now<<endl;
}
void del(int i)
{
    // printf("del(%lld)\n",i);
    int x=a[i],tmp=check(x);
    tag[x]--;
    if(check(x)&&!tmp)now++;
    if(!check(x)&&tmp)now--;
    // cout<<now<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    len=sqrt(n);
    for(int i=1;i<=n;i++)
        cin>>a[i],id[i]=i/len+1,cnt[a[i]]++;
    for(int i=1;i<=m;i++)
        cin>>q[i].l>>q[i].r,q[i].id=i;
    sort(q+1,q+1+m,cmp);
    int l=1,r=0;
    for(int i=1;i<=m;i++)
    {
        // cout<<q[i].l<<"!"<<q[i].r<<endl;
        while(l<q[i].l)del(l++);
        while(l>q[i].l)add(--l);
        while(r<q[i].r)add(++r);
        while(r>q[i].r)del(r--);
        ans[q[i].id]=now;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}