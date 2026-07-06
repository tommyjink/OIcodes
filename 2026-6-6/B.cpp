#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;

const int N=3e5+10;

int t,n,m,q,k,ans,num;
int eu[N],ev[N],nxt[N],head[N],c[N];
int f1[N],siz1[N],p[N];
int f2[N],siz2[N];
int hx[N],hy[N],hs[N],hp[N],top;

inline int find1(int x)
{
    while(f1[x]!=x)x=f1[x];
    return x;
}

inline int find2(int x)
{
    if(f2[x]==x)return x;
    return f2[x]=find2(f2[x]);
}

inline void merge2(int x,int y)
{
    x=find2(x);
    y=find2(y);
    if(x==y)return;
    if(siz2[x]>siz2[y])swap(x,y);
    f2[x]=y;
    siz2[y]+=siz2[x];
}

inline void merge1(int x,int y,int w)
{
    x=find1(x);
    y=find1(y);
    top++;
    if(x==y)
    {
        hx[top]=0;
        return;
    }
    if(siz1[x]>siz1[y])swap(x,y);
    if(p[x]&&p[y]&&find2(p[x])!=find2(p[y]))
    {
        merge2(p[x],p[y]);
        ans+=w;
        num--;
    }
    hx[top]=x;
    hy[top]=y;
    hs[top]=siz1[y];
    hp[top]=p[y];
    f1[x]=y;
    siz1[y]+=siz1[x];
    p[y]=max(p[x],p[y]);
}

inline void undo()
{
    if(hx[top])
    {
        f1[hx[top]]=hx[top];
        siz1[hy[top]]=hs[top];
        p[hy[top]]=hp[top];
    }
    top--;
}

void solve(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1,cnt=0;
    for(int i=mid+1;i<=r;i++)
        for(int j=head[i];j;j=nxt[j])
        {
            merge1(eu[j],ev[j],l);
            cnt++;
        }
    solve(l,mid);
    while(cnt--)undo();
    cnt=0;
    for(int i=l;i<=mid;i++)
        for(int j=head[i];j;j=nxt[j])
        {
            merge1(eu[j],ev[j],mid+1);
            cnt++;
        }
    solve(mid+1,r);
    while(cnt--)undo();
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        for(int i=0;i<=m;i++)head[i]=0;
        for(int i=1;i<=m;i++)
        {
            int w;
            cin>>eu[i]>>ev[i]>>w;
            nxt[i]=head[w];
            head[w]=i;
        }
        for(int i=1;i<=q;i++)cin>>c[i];
        sort(c+1,c+q+1);
        k=unique(c+1,c+q+1)-c-1;
        for(int i=1;i<=n;i++)
        {
            f1[i]=i;
            siz1[i]=1;
            p[i]=0;
        }
        for(int i=1;i<=k;i++)
        {
            p[c[i]]=i;
            f2[i]=i;
            siz2[i]=1;
        }
        ans=0;
        num=k;
        top=0;
        solve(0,m);
        if(num>1)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
