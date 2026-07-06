#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n,m;
double lazy[N*4],a[N];
struct node
{
    int l,r;
    double s,c;
}t[N*4];
void pushdown(int k)
{
    if (lazy[k] != 0.0 && t[k].l != t[k].r) {
        double lz = lazy[k];
        double s1 = t[k*2].s, c1 = t[k*2].c;
        t[k*2].s = s1 * cos(lz) + c1 * sin(lz);
        t[k*2].c = c1 * cos(lz) - s1 * sin(lz);
        lazy[k*2] += lz;
        double s2 = t[k*2+1].s, c2 = t[k*2+1].c;
        t[k*2+1].s = s2 * cos(lz) + c2 * sin(lz);
        t[k*2+1].c = c2 * cos(lz) - s2 * sin(lz);
        lazy[k*2+1] += lz;
        lazy[k] = 0.0;
    }
}
void pushup(int k)
{
    t[k].s = t[k*2].s + t[k*2+1].s;
    t[k].c = t[k*2].c + t[k*2+1].c;
}
void build(int k,int l,int r)
{ 
    t[k].l = l;
    t[k].r = r;
    lazy[k] = 0.0;
    if(l == r)
    {
        t[k].s = sin(a[l]);
        t[k].c = cos(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void update(int k,int l,int r,int x)
{
    pushdown(k);
    if (t[k].r < l || t[k].l > r) return;
    if (t[k].l >= l && t[k].r <= r) {
        double lz = x;
        double s = t[k].s, c = t[k].c;
        t[k].s = s * cos(lz) + c * sin(lz);
        t[k].c = c * cos(lz) - s * sin(lz);
        lazy[k] += lz;
        return;
    }
    update(k*2, l, r, x);
    update(k*2+1, l, r, x);
    pushup(k);
}
double query(int k,int l,int r)
{
    pushdown(k);
    if(t[k].r<l||t[k].l>r)return 0.0;
    if(t[k].l >= l && t[k].r <= r)
    {
        return t[k].s;
    }
    return query(k*2,l,r)+query(k*2+1,l,r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    // for(int i=1;i<=n;i++)   
    //     cout<<t[i].s<<" "<<t[i].c<<endl;
    cin>>m;
    while(m--)
    { 
        int op;
        cin>>op;
        if(op == 1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            update(1,l,r,x);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            double ans = query(1,l,r);
            cout << fixed << setprecision(1) << round(ans * 10) / 10 << endl;
        }

    }
    return 0;
}