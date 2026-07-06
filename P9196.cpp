#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e6+100;
int n,m,ans[N];
string s[N],t[N];
struct qry
{
    int id,y1,y2,val;
};
vector<qry> Q[N];
vector<int> P[N];
struct trie
{
    int nex[N][30],cnt=0,now=0;
    int L[N],R[N];
    void insert(string s)
    {
        int len=s.length(),p=0;
        for(int i=0;i<len;i++)
        {
            int c=s[i]-'A';
            if(!nex[p][c])nex[p][c]=++cnt;
            p=nex[p][c];
        }
    }
    void dfs(int x)
    {
        L[x]=++now;
        for(int i=0;i<='Z'-'A';i++)
            if(nex[x][i])dfs(nex[x][i]);
        R[x]=now;
    }
    pii getlr(string s)
    {
        int len=s.length(),p=0;
        for(int i=0;i<len;i++)
        {
            int c=s[i]-'A';
            if(!nex[p][c])return pii(-1,-1);
            p=nex[p][c];
        }
        return pii(L[p],R[p]);
    }
}t1,t2;
struct Tree
{
    int t[N];
    inline int lowbit(int x)
    {
        return x&(-x);
    }
    void add(int x,int d)
    {
        if(x==0)return;
        for(int i=x;i<N;i+=lowbit(i))
            t[i]+=d;
    }
    int query(int x)
    {
        // cout<<x<<"!!!"<<endl;
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=t[i];
        return res;
    }
}T;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    memset(T.t,0,sizeof(T.t));
    memset(t1.nex,0,sizeof(t1.nex));
    memset(t2.nex,0,sizeof(t2.nex));
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        t[i]=s[i];
        reverse(t[i].begin(),t[i].end());
        t1.insert(s[i]);
        t2.insert(t[i]);
    }
    t1.dfs(0);
    t2.dfs(0);
    for(int i=1;i<=n;i++)
    {
        int x=t1.getlr(s[i]).first;
        int y=t2.getlr(t[i]).first;
        P[x].emplace_back(y);
        // cout<<x<<","<<y<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        reverse(s2.begin(),s2.end());
        pii p1=t1.getlr(s1);
        pii p2=t2.getlr(s2);
        int x=p1.first,xx=p1.second;
        int y=p2.first,yy=p2.second;
        // cout<<x<<","<<xx<<"."<<y<<","<<yy<<":"<<s2<<endl;
        if(x==-1||y==-1)continue;
        Q[x-1].push_back((qry){i,y,yy,-1});
        Q[xx].push_back((qry){i,y,yy,1});
    }
    // cout<<"!"<<endl;
    for(int i=1;i<N;i++)
    {
        for(auto j:P[i])
            T.add(j,1);
        for(auto j:Q[i])
        {
            ans[j.id]+=j.val*(T.query(j.y2)-T.query(j.y1-1));
            // cout<<j.id<<" "<<j.val<<" "<<j.y1<<" "<<j.y2<<" "<<T.query(j.y2)<<" "<<T.query(j.y1-1)<<endl;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}