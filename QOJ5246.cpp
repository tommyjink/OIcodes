#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,INF=1e16;
int n,k,p[N],col[N],tot=0,X=0;
int f[N],d[N],opt[N];
string s;
struct node
{
    int ans=0,cnt[N],L=1,R=0;
    void init()
    {
        for(int i=1;i<=n;i++)cnt[i]=0;
        L=1,R=0;
        ans=0;
    }
    bool in(int x)
    {
        return L<=x&&x<=R;
    }
    void add(int x)
    {
        if(!p[x])return;
        if(in(p[x]))
        {
            cnt[col[x]]++;
            ans+=cnt[col[x]];
        }
    }
    void del(int x)
    {
        if(!p[x])return;
        if(in(p[x]))
        {
            ans-=cnt[col[x]];
            cnt[col[x]]--;
        }
    }
    int w(int l,int r)
    {
        while(L>l)add(--L);
        while(R<r)add(++R);
        while(L<l)del(L++);
        while(R>r)del(R--);
        return ans;
    }
}A,B;
void upd(int i,int j,node &A)
{
    int tmp=f[j]+A.w(j+1,i)+X;
    if(tmp<f[i])
    {
        f[i]=tmp;
        opt[i]=j;
        d[i]=d[j]+1;
    }
}
void cal(int l,int r)
{
    if(r-l<=1)return;
    int mid=(l+r)>>1;
    for(int i=opt[l];i<=opt[r];i++)
        upd(mid,i,A);
    cal(l,mid);
    for(int i=l+1;i<=mid;i++)
        upd(r,i,B);
    cal(mid,r);
}
bool check(int mid)
{
    X=mid;
    for(int i=0;i<=n;i++)f[i]=INF,d[i]=0,opt[i]=0;
    f[0]=0;
    A.init();
    B.init();
    upd(n,0,A);
    cal(0,n);
    return d[n]>k;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>s;
    s=" "+s;
    stack<int> t;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==')')
        {
            if(!t.empty()&&s[t.top()]=='(')
            {
                p[i]=t.top();
                p[t.top()]=i;
                if(col[t.top()-1])
                    col[i]=col[t.top()]=col[t.top()-1];
                else col[i]=col[t.top()]=++tot;
                t.pop();
            }
            else t.push(i);
        }
        else t.push(i);
    }
    int l=0,r=n*n+1ll;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(check(mid))l=mid+1;
        else r=mid;
    }
    check(l);
    cout<<f[n]-k*l<<endl;
    return 0;
}