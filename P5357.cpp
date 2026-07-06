#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e6+10;
int n,nxt[N],son[N][26],tot=0,id[N],cnt[N];
int in[N];
int insert(string s)
{
    int len=s.length(),p=0;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!son[p][c])son[p][c]=++tot;
        p=son[p][c];
    }
    return p;
}
void getfail()
{
    queue<int> q;
    for(int i=0;i<26;i++)
        if(son[0][i])q.push(son[0][i]);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=0;i<26;i++)
        {
            if(!son[x][i]){son[x][i]=son[nxt[x]][i];}
            else
            {
                nxt[son[x][i]]=son[nxt[x]][i];
                q.push(son[x][i]);
                in[son[nxt[x]][i]]++;
            }
        }
    }
}
void solve(string s)
{
    int len=s.length(),p=0;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        p=son[p][c];
        cnt[p]++;
    }
    queue<int> q;
    for(int i=1;i<=tot;i++)
        if(!in[i])q.push(i);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        int v=nxt[x];
        cnt[v]+=cnt[x];
        if(!--in[v])q.push(v);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string t;
        cin>>t;
        id[i]=insert(t);
    }
    string s;cin>>s;
    getfail();
    solve(s);
    for(int i=1;i<=n;i++)
        cout<<cnt[id[i]]<<endl;
    return 0;
}