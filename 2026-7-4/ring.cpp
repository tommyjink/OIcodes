#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,d,a[N],id[N];
inline int f(int x){return (x+n-1)%n+1;}
struct BIT
{
    int t[N];
    void init()
    {
        for(int i=0;i<=n;i++)t[i]=0;
    }
    void add(int x,int d)
    {
        for(int i=x;i<=n;i+=lowbit(i))t[i]+=d;
    }
    int sum(int x)
    {
        int res=0;
        for(int i=x;i;i-=lowbit(i))res+=t[i];
        return res;
    }
    int get(int x,int y)
    {
        x=f(x),y=f(y);
        if(x<=y)return sum(y)-sum(x-1);
        else return sum(n)-sum(x-1)+sum(y);
    }
}sum0,sum1,cnt0,cnt1;
bool cmp(int x,int y)
{
    return a[x]>a[y];
}
void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i],id[i]=i;
    sort(id+1,id+1+n,cmp);
    int ans=0;
    sum0.init(),sum1.init();
    cnt0.init(),cnt1.init();
    for(int i=1;i<=n;i++)cnt0.add(i,1),sum0.add(i,a[i]);
    for(int i=1;i<=n;i++)
    {
        int x=id[i];
        int p1=cnt1.get(x-d,x+d)*a[x];
        int p2=(cnt0.get(x-d,x+d)-1)*a[x];
        int p3=-sum1.get(x-d,x+d);
        int p4=-(sum0.get(x-d,x+d)-a[x]);
        int res=p1+p2+p3+p4;
        if(res<0)continue;
        else ans+=res;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ring.in","r",stdin);
    freopen("ring.out","w",stdout);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}