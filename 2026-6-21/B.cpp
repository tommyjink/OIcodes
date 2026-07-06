#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,M=500;
int n,head[N],tot=0,du[N];
int dep[N],fa[N],q[N],a[N],h[N],ord[N],dia[N],dl;
int cnt,len,path[M][20],plen[M],tmp[20],ans[20],now[20];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void bfs(int s)
{
    int l=1,r=1;
    q[1]=s;
    fa[s]=0;
    dep[s]=0;
    while(l<=r)
    {
        int x=q[l++];
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            if(y==fa[x])continue;
            fa[y]=x;
            dep[y]=dep[x]+1;
            q[++r]=y;
        }
    }
}
void getpath(int x,int y)
{
    bfs(x);
    len=0;
    while(y)
    {
        tmp[++len]=y;
        y=fa[y];
    }
    for(int i=1;i*2<=len;i++)
        swap(tmp[i],tmp[len-i+1]);
}
bool lessans(int x[],int y[],int l)
{
    if(!y[0])return true;
    if(!x[0])return true;
    for(int i=1;i<=l;i++)
        if(x[i]!=y[i])return x[i]<y[i];
    return false;
}
void brute()
{
    cnt=0;
    len=0;
    for(int i=1;i<=n;i++)
    {
        bfs(i);
        for(int j=i+1;j<=n;j++)
            len=max(len,dep[j]+1);
    }
    for(int i=1;i<=n;i++)
    {
        bfs(i);
        for(int j=i+1;j<=n;j++)
        {
            if(dep[j]+1!=len)continue;
            getpath(i,j);
            cnt++;
            plen[cnt]=len;
            for(int k=1;k<=len;k++)
                path[cnt][k]=tmp[k];
            cnt++;
            plen[cnt]=len;
            for(int k=1;k<=len;k++)
                path[cnt][k]=tmp[len-k+1];
        }
    }
    for(int i=1;i<=n;i++)
        a[i]=i;
    ans[0]=0;
    do
    {
        now[0]=0;
        for(int i=1;i<=cnt;i++)
        {
            for(int j=1;j<=len;j++)
                tmp[j]=a[path[i][j]];
            tmp[0]=1;
            if(lessans(now,tmp,len))
            {
                now[0]=1;
                for(int j=1;j<=len;j++)
                    now[j]=tmp[j];
            }
        }
        if(lessans(now,ans,len))
        {
            ans[0]=1;
            for(int i=1;i<=len;i++)
                ans[i]=now[i];
        }
    }while(next_permutation(a+1,a+n+1));
    for(int i=1;i<=len;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
int far(int s)
{
    bfs(s);
    int x=s;
    for(int i=1;i<=n;i++)
        if(dep[i]>dep[x])x=i;
    return x;
}
void getdia()
{
    int x=far(1),y=far(x);
    dl=0;
    while(y)
    {
        dia[++dl]=y;
        y=fa[y];
    }
    for(int i=1;i*2<=dl;i++)
        swap(dia[i],dia[dl-i+1]);
}
void cal(int rt,int ban)
{
    int l=1,r=1;
    ord[1]=rt;
    fa[rt]=ban;
    dep[rt]=0;
    while(l<=r)
    {
        int x=ord[l++];
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            if(y==fa[x])continue;
            fa[y]=x;
            dep[y]=dep[x]+1;
            ord[++r]=y;
        }
    }
    for(int i=1;i<=r;i++)
        h[ord[i]]=0;
    for(int i=r;i>=1;i--)
    {
        int x=ord[i];
        for(int j=head[x];j;j=e[j].next)
        {
            int y=e[j].to;
            if(fa[y]==x)h[x]=max(h[x],h[y]+1);
        }
    }
}
bool cmp(vector<int> x,vector<int> y)
{
    if(y.empty())return true;
    for(int i=0;i<(int)x.size();i++)
        if(x[i]!=y[i])return x[i]<y[i];
    return false;
}
vector<int> dfs(int x,int f,int rem,int cur,int ban)
{
    vector<int> res,best;
    if(!rem)return res;
    int c=0,ch[20];
    for(int i=head[x];i;i=e[i].next)
    {
        int y=e[i].to;
        if(y==f||y==ban)continue;
        if(h[y]>=rem-1)ch[++c]=y;
    }
    if(rem==1)
    {
        res.push_back(c);
        return res;
    }
    for(int i=1;i<=c;i++)
    {
        vector<int> tmp=dfs(ch[i],x,rem-1,cur+c,0);
        if(cmp(tmp,best))best=tmp;
    }
    res.push_back(cur+c-1);
    for(auto x:best)
        res.push_back(x);
    return res;
}
void work()
{
    getdia();
    int D=dl-1;
    vector<int> best;
    if(D%2==0)
    {
        int R=D/2,rt=dia[R+1],k=0;
        cal(rt,0);
        for(int i=1;i<=n;i++)
            if(dep[i]==R)k++;
        for(int i=head[rt];i;i=e[i].next)
        {
            int y=e[i].to;
            if(h[y]<R-1)continue;
            vector<int> now;
            now.push_back(k);
            for(int j=1;j<=R;j++)
                now.push_back(k+j);
            vector<int> tmp=dfs(rt,0,R,k+R+1,y);
            for(auto x:tmp)
                now.push_back(x);
            if(cmp(now,best))best=now;
        }
    }
    else
    {
        int R=D/2,x=dia[R+1],y=dia[R+2],k=0;
        if(!R)
        {
            cout<<2<<" "<<1<<endl;
            return;
        }
        cal(x,y);
        for(int i=1;i<=n;i++)
            if(dep[i]==R)k++;
        cal(y,x);
        for(int i=1;i<=n;i++)
            if(dep[i]==R)k++;
        cal(y,x);
        vector<int> now;
        now.push_back(k);
        for(int i=1;i<=R+1;i++)
            now.push_back(k+i);
        vector<int> tmp=dfs(y,x,R,k+R+2,0);
        for(auto z:tmp)
            now.push_back(z);
        best=now;
        cal(x,y);
        now.clear();
        now.push_back(k);
        for(int i=1;i<=R+1;i++)
            now.push_back(k+i);
        tmp=dfs(x,y,R,k+R+2,0);
        for(auto z:tmp)
            now.push_back(z);
        if(cmp(now,best))best=now;
    }
    for(auto x:best)
        cout<<x<<" ";
    cout<<endl;
}
void solve()
{
    cin>>n;
    tot=0;
    for(int i=1;i<=n;i++)
        head[i]=du[i]=0;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
        du[x]++;
        du[y]++;
    }
    if(n<=8)
    {
        brute();
        return;
    }
    work();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
