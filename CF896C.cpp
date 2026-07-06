#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N = 1e6 + 10, MOD = 1000000007;
int n, m, seed, vmax, a[N];
struct node
{
    int l, r;
    mutable int val;
};
bool operator<(node x, node y)
{
    return x.l < y.l;
}
set<node> s;
int qpow(int x,int y,int p)
{
    int res=1;
    x%=p;
    while(y)
    {
        if(y&1)res=res*x%p;
        y>>=1;
        x=x*x%p;
    }
    return res;
}
int rnd()
{
    int ret = seed;
    seed = (seed * 7 + 13) % MOD;
    return ret;
}
auto split(int pos)
{
    auto p=s.lower_bound((node){pos,-1,0});
    if(p!=s.end()&&p->l==pos)return p;
    p--;
    if(p->r<pos)return s.end();
    node tmp=*p;
    s.erase(p);
    s.insert((node){tmp.l,pos-1,tmp.val});
    return s.insert((node){pos,tmp.r,tmp.val}).first;
}
void add(int l,int r,int x)
{
    auto ir=split(r+1),il=split(l);
    for(;il!=ir;il++)il->val+=x;
}
void modify(int l,int r,int x)
{
    auto ir=split(r+1),il=split(l);
    s.erase(il,ir);
    s.insert((node){l,r,x});
}
int kth(int l,int r,int k)
{
    auto ir=split(r+1),il=split(l);
    vector<pii> v;
    for(auto i=il;i!=ir;++i)
        v.push_back(pii(i->val,i->r-i->l+1));
    sort(v.begin(),v.end());
    int now=0;
    for(auto i:v)
    {
        now+=i.second;
        if(now>=k)return i.first;
    }
    return 0;
}
int query(int l,int r,int x,int y)
{
    auto ir=split(r+1),il=split(l);
    int res=0;
    for(auto i=il;i!=ir;++i)
    {
        res=res+qpow(i->val,x,y)*(i->r-i->l+1);
        res%=y;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> seed >> vmax;
    for (int i = 1; i <= n; i++)
    {
        a[i] = (rnd() % vmax) + 1;
        s.insert((node){i,i,a[i]});
    }
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    for (int i = 1; i <= m; i++)
    {
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        if (l > r) swap(l, r);
        int x=0, y=0;
        if (op == 3) x = (rnd() % (r - l + 1)) + 1;
        else x = (rnd() % vmax) + 1;
        if (op == 4) y = (rnd() % vmax) + 1;
        // cout<<op<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
        switch(op)
        {
            case 1:add(l,r,x);break;
            case 2:modify(l,r,x);break;
            case 3:cout<<kth(l,r,x)<<endl;break;
            case 4:cout<<query(l,r,x,y)<<endl;break;
        }
    }

    return 0;
}
