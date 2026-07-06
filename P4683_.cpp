#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=25000+10,L=20,M=N*L;
int n,mlen=0,nxt[M][30],ed[M],tot=0,tag[M],cnt=0;
string s[N],ans;
void insert(string s)
{
    int p=0,len=s.length();
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!nxt[p][c])
            nxt[p][c]=++tot;
        p=nxt[p][c];
    }
    ed[p]=true;
}
void mark(string s)
{
    int p=0,len=s.length();
    tag[0]=true;
    for(int i=0;i<len;i++)
    {
        p=nxt[p][s[i]-'a'];
        tag[p]=true;
    }
}
void dfs(int x,int fa)
{
    if(ed[x])ans.push_back('P');
    for(int i=0;i<='z'-'a';i++)
    {
        if((!nxt[x][i])||tag[nxt[x][i]])
            continue;
        ans.push_back('a'+i);
        dfs(nxt[x][i],x);
    }
    for(int i=0;i<='z'-'a';i++)
    {
        if((!nxt[x][i])||!tag[nxt[x][i]])
            continue;
        ans.push_back('a'+i);
        dfs(nxt[x][i],x);
    }
    // ans.push_back('!');
    if(!tag[x])ans.push_back('-');
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i].length()>s[mlen].length())
            mlen=i;
        insert(s[i]);
    }
    mark(s[mlen]);
    dfs(0,-1);
    cout<<ans.length()<<endl;
    for(int i=0;i<ans.length();i++)
        cout<<ans[i]<<endl;
    return 0;
}